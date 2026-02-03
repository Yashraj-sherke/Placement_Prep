# BitBuds - Technical Interview Preparation Guide

## 📋 Project Overview
**BitBuds** is a full-stack gamified coding platform for children (ages 6-14) featuring missions, badges, XP/leveling, and progress tracking.

**Tech Stack:**
- **Frontend:** React 18 + TypeScript, Vite, Tailwind CSS
- **Backend:** Node.js + Express.js, MongoDB + Mongoose
- **Auth:** JWT (access + refresh tokens)
- **Architecture:** RESTful API, MVC pattern

---

## 🏗️ Architecture Questions

### 1. **Explain the overall architecture of BitBuds. How do the frontend and backend communicate?**

**Answer:**
BitBuds follows a **client-server architecture** with clear separation of concerns:

- **Frontend (React + TypeScript):** SPA that runs in the browser, handles UI/UX, state management via Context API
- **Backend (Node.js + Express):** RESTful API server that handles business logic, authentication, and database operations
- **Communication:** Frontend makes HTTP requests (via Axios) to backend API endpoints. Backend responds with JSON data
- **Architecture Pattern:** MVC on backend (Models, Controllers, Services), Component-based on frontend

**Key Design Decisions:**
- Service layer separates business logic from controllers for better testability
- Middleware pipeline for auth, validation, error handling, and sanitization
- Context API for global state (auth, user data) instead of Redux to keep it lightweight for kids' platform

---

### 2. **Why did you choose MongoDB over a relational database like PostgreSQL?**

**Answer:**
MongoDB was chosen for several reasons specific to this use case:

**Advantages:**
- **Flexible Schema:** User progress, badges, and missions have varying structures. NoSQL allows easy iteration without migrations
- **Nested Documents:** User stats contain nested category progress (basics, loops, conditionals) - perfect for document model
- **Scalability:** Horizontal scaling is easier for a platform that could grow to millions of young users
- **JSON-like Structure:** Direct mapping between MongoDB documents and JavaScript objects simplifies development

**Trade-offs Acknowledged:**
- Lack of ACID transactions (though Mongoose provides some transaction support)
- No built-in referential integrity (handled at application level)
- For this educational platform, eventual consistency is acceptable

---

### 3. **Explain your folder structure and why you organized it this way.**

**Answer:**

```
backend/src/
├── models/          # Mongoose schemas (data layer)
├── controllers/     # Request handlers (presentation layer)
├── services/        # Business logic (service layer)
├── routes/          # API route definitions
├── middleware/      # Auth, validation, error handling
├── validators/      # Joi schemas for input validation
└── utils/           # Helper functions, constants
```

**Rationale:**
- **Separation of Concerns:** Controllers handle HTTP, services handle logic, models handle data
- **Testability:** Services can be unit tested independently
- **Reusability:** Services can be called from multiple controllers
- **Maintainability:** Clear boundaries make debugging easier

**Example Flow:**
`Route → Middleware → Controller → Service → Model → Database`

---

### 4. **How does your middleware pipeline work? Explain the order and why.**

**Answer:**

**Middleware Order:**
1. **CORS** - Allow frontend origin
2. **Body Parser** - Parse JSON requests
3. **Sanitization** - Prevent XSS/NoSQL injection
4. **Rate Limiting** - Prevent abuse (100 req/15min)
5. **Route-specific middleware:**
   - `authenticate` - Verify JWT token
   - `validation` - Validate request body with Joi
6. **Controller** - Handle request
7. **Error Handler** - Catch and format errors

**Why This Order:**
- Security middleware (CORS, sanitization) comes first
- Rate limiting prevents DoS before expensive operations
- Authentication before validation (no point validating unauthenticated requests)
- Error handler is last to catch all errors

---

### 5. **Explain the difference between your `authenticate` and `optionalAuth` middleware.**

**Answer:**

**`authenticate` (auth.middleware.js):**
- **Required authentication** - throws 401 if no valid token
- Used for protected routes (create project, submit mission)
- Attaches `req.user` with user data

**`optionalAuth` (optionalAuth.middleware.js):**
- **Optional authentication** - doesn't throw error if no token
- Used for routes that work for both logged-in and guest users
- Example: Viewing a project (logged-in users see if they liked it, guests just view)
- Attaches `req.user` if token exists, otherwise `req.user = null`

**Use Case:**
```javascript
// Public projects - anyone can view, but logged-in users see personalized data
router.get('/:id', optionalAuth, getProjectById);
```

---

## 🗄️ Database Design Questions

### 6. **Explain your database schema design. What are the main collections and their relationships?**

**Answer:**

**Main Collections:**

1. **Users** - User accounts (email, password, profile)
2. **UserStats** - Gamification data (XP, level, streaks, badges)
   - 1:1 relationship with Users
3. **Missions** - Coding challenges
4. **Progress** - User mission progress
   - Many-to-many between Users and Missions
5. **Badges** - Achievement definitions
6. **CodeProjects** - User-created projects
   - Many-to-one with Users

**Relationships:**
```javascript
User (1) ←→ (1) UserStats
User (1) ←→ (many) CodeProjects
User (many) ←→ (many) Missions (via Progress)
UserStats (many) ←→ (many) Badges
```

**Design Decisions:**
- Separated UserStats from Users for performance (stats updated frequently)
- Embedded badges array in UserStats (denormalization for faster reads)
- Referenced Users in Projects (normalization to avoid data duplication)

---

### 7. **Why did you create separate UserStats and Progress models instead of embedding everything in the User model?**

**Answer:**

**Separation Benefits:**

**UserStats Model:**
- **Frequently Updated:** XP, streaks, levels change often
- **Performance:** Updating a smaller document is faster
- **Indexing:** Can index on `totalXP` for leaderboard queries without indexing entire User collection
- **Scalability:** Stats can be cached separately

**Progress Model:**
- **Many-to-Many:** Each user has progress on multiple missions
- **Granular Updates:** Update individual mission progress without touching user data
- **Query Flexibility:** Can query "all users who completed mission X"

**Alternative (Embedding):**
```javascript
// BAD: Embedding all progress in User
User {
  progress: [{ mission: ..., status: ... }] // Could grow to 100+ items
}
```
This would make User documents huge and slow to query.

---

### 8. **Explain your indexing strategy. Which fields did you index and why?**

**Answer:**

**Key Indexes:**

**UserStats:**
```javascript
{ totalXP: -1 }      // Leaderboard queries (descending)
{ level: -1 }        // Level-based filtering
{ currentStreak: -1 } // Streak leaderboards
{ user: 1 }          // Unique index for 1:1 relationship
```

**CodeProjects:**
```javascript
{ user: 1, createdAt: -1 }  // Compound: user's recent projects
{ isPublic: 1, likes: -1 }  // Public projects sorted by popularity
{ tags: 1 }                  // Tag-based search
```

**Why These Indexes:**
- **Leaderboard:** `totalXP: -1` makes `find().sort({totalXP: -1})` fast
- **Compound Index:** `{user: 1, createdAt: -1}` optimizes "user's recent projects" query
- **Trade-off:** Indexes speed up reads but slow down writes (acceptable for read-heavy platform)

---

### 9. **How do you handle the "forking" feature in your database? Explain the data model.**

**Answer:**

**Fork Data Model:**

```javascript
CodeProject {
  forkedFrom: ObjectId,  // Reference to original project
  forkCount: Number,     // How many times this was forked
  user: ObjectId         // Owner of the fork
}
```

**Fork Process:**
1. User clicks "Fork" on Project A
2. Backend creates new Project B with:
   - Copy of content (blocks, code, assets)
   - `forkedFrom: Project A's ID`
   - `user: Current user's ID`
   - `isPublic: false` (forks start private)
3. Increment `Project A.forkCount`

**Querying:**
- Find all forks of a project: `find({ forkedFrom: projectId })`
- Check if project is a fork: Virtual field `isFork` checks if `forkedFrom` exists

**Design Choice:** Reference instead of embedding allows independent evolution of forks.

---

### 10. **Explain your XP and leveling system. How is it calculated and stored?**

**Answer:**

**XP Formula:**
```javascript
XP required for level N = 100 × N²
```

**Examples:**
- Level 1: 100 XP
- Level 2: 400 XP
- Level 5: 2,500 XP
- Level 10: 10,000 XP

**Reverse Calculation (XP → Level):**
```javascript
level = Math.floor(Math.sqrt(totalXP / 100)) + 1
```

**Storage:**
```javascript
UserStats {
  totalXP: 2500,    // Cumulative XP
  level: 5          // Calculated level
}
```

**Virtual Fields:**
```javascript
xpForNextLevel: 100 × (level + 1)²
progressToNextLevel: (currentLevelXP / neededXP) × 100
```

**Why This Formula:**
- **Progressive Difficulty:** Each level requires more XP (quadratic growth)
- **Motivation:** Early levels are quick, later levels feel rewarding
- **Scalability:** Can support 50+ levels without astronomical XP requirements

---

## 🔌 API Design Questions

### 11. **Explain your API versioning strategy and why you chose it.**

**Answer:**

**Strategy:** URL-based versioning (`/api/v1/...`)

**Rationale:**
- **Clarity:** Version is immediately visible in the URL
- **Backward Compatibility:** Can run v1 and v2 simultaneously
- **Easy Routing:** Express router handles versioning cleanly

```javascript
app.use('/api/v1/missions', missionRoutes);
app.use('/api/v2/missions', missionRoutesV2); // Future
```

**Alternatives Considered:**
- **Header-based:** More RESTful but harder for frontend devs to test
- **Query parameter:** Less clean, easy to forget

**Migration Plan:**
When introducing breaking changes, create `/api/v2/` and deprecate v1 after 6 months.

---

### 12. **How did you design your error responses? Show examples.**

**Answer:**

**Standardized Error Format:**
```json
{
  "success": false,
  "message": "Validation error",
  "error": {
    "statusCode": 400,
    "errors": [
      { "field": "email", "message": "Invalid email format" }
    ]
  }
}
```

**Error Middleware:**
```javascript
// error.middleware.js
export const errorHandler = (err, req, res, next) => {
  const statusCode = err.statusCode || 500;
  res.status(statusCode).json({
    success: false,
    message: err.message,
    error: {
      statusCode,
      ...(process.env.NODE_ENV === 'development' && { stack: err.stack })
    }
  });
};
```

**Benefits:**
- **Consistency:** Frontend always knows the structure
- **Debugging:** Stack traces in development only
- **User-Friendly:** Clear error messages for kids/parents

---

### 13. **Explain your pagination strategy for the leaderboard and projects.**

**Answer:**

**Implementation:**
```javascript
// Query params: ?page=2&limit=10
const { page = 1, limit = 10 } = req.query;
const skip = (page - 1) * limit;

const projects = await CodeProject.find({ isPublic: true })
  .sort({ likes: -1 })
  .limit(parseInt(limit))
  .skip(parseInt(skip));

const total = await CodeProject.countDocuments({ isPublic: true });

res.json({
  data: projects,
  pagination: {
    page: parseInt(page),
    limit: parseInt(limit),
    total,
    pages: Math.ceil(total / limit)
  }
});
```

**Why This Approach:**
- **Performance:** Only fetch needed documents
- **Scalability:** Works with millions of records
- **UX:** Frontend can show "Page 1 of 50"

**Trade-off:** `skip()` is slow for large offsets (page 1000). For production, would use cursor-based pagination.

---

## 🔐 Authentication & Security Questions

### 14. **Explain your JWT authentication flow. How do access and refresh tokens work?**

**Answer:**

**Token Strategy:**
- **Access Token:** Short-lived (15 minutes), used for API requests
- **Refresh Token:** Long-lived (7 days), used to get new access tokens

**Flow:**

1. **Login:**
   ```javascript
   POST /api/v1/auth/login
   → Returns: { accessToken, refreshToken }
   → Frontend stores in memory (access) and httpOnly cookie (refresh)
   ```

2. **API Request:**
   ```javascript
   GET /api/v1/missions
   Headers: { Authorization: "Bearer <accessToken>" }
   ```

3. **Token Expired:**
   ```javascript
   → 401 Unauthorized
   → Frontend calls POST /api/v1/auth/refresh
   → Returns new accessToken
   → Retry original request
   ```

**Security Benefits:**
- **Short Access Token:** Limits damage if stolen
- **HttpOnly Cookie:** Refresh token can't be accessed by JavaScript (XSS protection)
- **Rotation:** Refresh tokens can be rotated on each use

---

### 15. **How do you prevent common security vulnerabilities (XSS, NoSQL injection, CSRF)?**

**Answer:**

**XSS Prevention:**
```javascript
// Sanitization middleware
import mongoSanitize from 'express-mongo-sanitize';
import xss from 'xss-clean';

app.use(mongoSanitize()); // Remove $ and . from user input
app.use(xss());           // Sanitize HTML
```

**NoSQL Injection:**
```javascript
// BAD: Direct user input in query
User.find({ email: req.body.email }); // Vulnerable

// GOOD: Validation with Joi
const schema = Joi.object({
  email: Joi.string().email().required()
});
```

**CSRF Protection:**
- Not needed for JWT in headers (CSRF targets cookies)
- If using cookies for access tokens, would add `csurf` middleware

**Rate Limiting:**
```javascript
import rateLimit from 'express-rate-limit';

const limiter = rateLimit({
  windowMs: 15 * 60 * 1000, // 15 minutes
  max: 100 // 100 requests per IP
});
```

**Password Security:**
- Bcrypt with 10 salt rounds
- Password validation (min 8 chars, complexity rules)

---

## ⚡ Performance Questions

### 16. **How would you optimize the leaderboard query for 1 million users?**

**Answer:**

**Current Implementation:**
```javascript
UserStats.find().sort({ totalXP: -1 }).limit(10);
```

**Optimizations:**

1. **Indexing:** Already have `{ totalXP: -1 }` index ✅

2. **Caching:**
   ```javascript
   // Redis cache for top 100
   const cachedLeaderboard = await redis.get('leaderboard:top100');
   if (cachedLeaderboard) return JSON.parse(cachedLeaderboard);
   
   const leaderboard = await UserStats.find()...;
   await redis.setex('leaderboard:top100', 300, JSON.stringify(leaderboard));
   ```

3. **Materialized View:**
   - Separate `Leaderboard` collection updated every 5 minutes
   - Avoids querying entire UserStats collection

4. **Pagination:**
   - Only show top 100, use cursor-based pagination for deeper pages

5. **Denormalization:**
   - Store user name/avatar in UserStats to avoid populate()

**Trade-off:** Caching introduces eventual consistency (acceptable for leaderboards).

---

### 17. **How do you handle the N+1 query problem in your codebase?**

**Answer:**

**Problem Example:**
```javascript
// BAD: N+1 queries
const projects = await CodeProject.find({ isPublic: true });
for (let project of projects) {
  project.user = await User.findById(project.user); // N queries!
}
```

**Solution: Populate**
```javascript
// GOOD: 2 queries total
const projects = await CodeProject.find({ isPublic: true })
  .populate('user', 'firstName lastName profilePicture');
```

**Where Used:**
- `getPublicProjects()` - populates user info
- `getUserDashboard()` - populates badges and missions
- `getLeaderboard()` - populates user details

**Advanced Optimization:**
```javascript
// Select only needed fields
.populate('user', 'firstName lastName') // Don't fetch password, email, etc.
```

---

### 18. **How would you implement real-time features (live leaderboard updates)?**

**Answer:**

**Current:** REST API with polling (frontend fetches every 30 seconds)

**Better Approach: WebSockets**

1. **Socket.io Integration:**
   ```javascript
   // Backend
   io.on('connection', (socket) => {
     socket.join('leaderboard');
   });
   
   // When user completes mission
   io.to('leaderboard').emit('leaderboard:update', newLeaderboard);
   ```

2. **Frontend:**
   ```javascript
   socket.on('leaderboard:update', (data) => {
     setLeaderboard(data);
   });
   ```

**Challenges:**
- **Scalability:** Need Redis adapter for multi-server Socket.io
- **Battery:** Constant connections drain mobile batteries
- **Complexity:** More complex than REST

**Hybrid Approach:**
- Use WebSockets for active users on leaderboard page
- Fall back to polling for others

---

## 🛡️ Error Handling Questions

### 19. **Explain your error handling strategy. How do you handle async errors?**

**Answer:**

**Async Handler Wrapper:**
```javascript
// middleware/asyncHandler.js
const asyncHandler = (fn) => (req, res, next) => {
  Promise.resolve(fn(req, res, next)).catch(next);
};

// Usage
export const getMissions = asyncHandler(async (req, res) => {
  const missions = await Mission.find(); // Errors auto-caught
  res.json(missions);
});
```

**Why This Works:**
- Wraps async functions in try-catch automatically
- Passes errors to Express error middleware
- Avoids repetitive try-catch blocks

**Error Hierarchy:**
```javascript
class ApiError extends Error {
  constructor(statusCode, message) {
    super(message);
    this.statusCode = statusCode;
  }
}

// Usage
throw new ApiError(404, 'Mission not found');
```

**Global Error Handler:**
```javascript
app.use((err, req, res, next) => {
  logger.error(err);
  res.status(err.statusCode || 500).json({
    success: false,
    message: err.message
  });
});
```

---

### 20. **How do you handle validation errors vs. business logic errors?**

**Answer:**

**Validation Errors (400):**
```javascript
// Joi validation middleware
const validateBody = (schema) => (req, res, next) => {
  const { error } = schema.validate(req.body);
  if (error) {
    return res.status(400).json({
      success: false,
      message: 'Validation error',
      errors: error.details.map(d => ({
        field: d.path[0],
        message: d.message
      }))
    });
  }
  next();
};
```

**Business Logic Errors (custom codes):**
```javascript
// Service layer
if (mission.prerequisite && !userHasCompleted(prerequisite)) {
  throw new ApiError(403, 'Complete prerequisite mission first');
}

if (user.level < mission.requiredLevel) {
  throw new ApiError(403, 'Insufficient level');
}
```

**Distinction:**
- **400:** User sent invalid data (email format, missing fields)
- **403:** User sent valid data but business rules prevent action
- **404:** Resource doesn't exist
- **500:** Server error (database down, etc.)

---

## 🚀 Scalability Questions

### 21. **How would you scale BitBuds to handle 100,000 concurrent users?**

**Answer:**

**Current Bottlenecks:**
1. Single Node.js server
2. Single MongoDB instance
3. No caching layer

**Scaling Strategy:**

**1. Horizontal Scaling (Application Layer):**
```
Load Balancer (Nginx)
    ↓
[Server 1] [Server 2] [Server 3] ... [Server N]
```
- Deploy multiple Node.js instances
- Use PM2 cluster mode or Kubernetes
- Sticky sessions for WebSocket connections

**2. Database Scaling:**
- **Read Replicas:** Route reads to replicas, writes to primary
- **Sharding:** Shard by userId (users 1-100k on shard 1, etc.)
- **Indexing:** Ensure all queries use indexes

**3. Caching Layer (Redis):**
```javascript
// Cache frequently accessed data
- Leaderboard (top 100)
- Mission list (changes rarely)
- User stats (invalidate on update)
```

**4. CDN for Static Assets:**
- Serve images, videos, CSS/JS from CloudFront/Cloudflare
- Reduces server load

**5. Async Processing (Queue):**
```javascript
// Badge checking is expensive
// Use Bull queue with Redis
queue.add('check-badges', { userId });
```

**6. Database Connection Pooling:**
```javascript
mongoose.connect(uri, {
  maxPoolSize: 50 // Reuse connections
});
```

---

## 🧠 Tricky Questions (Test Real Understanding)

### 22. **A user completes a mission but their XP doesn't update. Walk me through how you'd debug this.**

**Answer:**

**Debugging Steps:**

1. **Check Frontend:**
   - Open DevTools Network tab
   - Verify POST request to `/api/v1/missions/:id/submit` sent
   - Check response status (200? 500?)

2. **Check Backend Logs:**
   ```javascript
   // Add logging in mission.service.js
   logger.info(`User ${userId} submitting mission ${missionId}`);
   ```

3. **Check Database:**
   ```javascript
   // Verify Progress document created
   db.progresses.findOne({ user: userId, mission: missionId });
   
   // Verify UserStats updated
   db.userstats.findOne({ user: userId });
   ```

4. **Common Issues:**
   - **Transaction Failed:** XP update threw error, rolled back
   - **Race Condition:** Two simultaneous submissions
   - **Validation Error:** XP value invalid (negative, NaN)
   - **Missing Await:** `addXP()` called without await

5. **Fix:**
   ```javascript
   // Ensure atomic update
   const session = await mongoose.startSession();
   session.startTransaction();
   try {
     await Progress.create([{ ... }], { session });
     await UserStats.updateOne({ user }, { $inc: { totalXP: xp } }, { session });
     await session.commitTransaction();
   } catch (error) {
     await session.abortTransaction();
     throw error;
   }
   ```

---

### 23. **If two users like a project at the exact same time, could the like count be wrong? How would you prevent this?**

**Answer:**

**Problem: Race Condition**

```javascript
// BAD: Read-Modify-Write race condition
const project = await CodeProject.findById(id);
project.likes += 1;  // User A reads likes=10, increments to 11
await project.save(); // User B reads likes=10, increments to 11
                      // Result: likes=11 (should be 12!)
```

**Solution 1: Atomic Update**
```javascript
// GOOD: Use MongoDB atomic operators
await CodeProject.findByIdAndUpdate(id, {
  $inc: { likes: 1 },
  $addToSet: { likedBy: userId }
});
```

**Solution 2: Optimistic Locking**
```javascript
// Add version field
const project = await CodeProject.findById(id);
const result = await CodeProject.updateOne(
  { _id: id, __v: project.__v },
  { $inc: { likes: 1, __v: 1 } }
);
if (result.modifiedCount === 0) {
  // Version mismatch, retry
}
```

**Solution 3: Distributed Lock (Redis)**
```javascript
const lock = await redisLock.acquire(`project:${id}:like`);
try {
  // Perform like operation
} finally {
  await lock.release();
}
```

**Current Implementation:** Uses `$addToSet` which is atomic ✅

---

### 24. **A parent complains their child's streak reset even though they logged in yesterday. How could this happen?**

**Answer:**

**Possible Causes:**

1. **Timezone Issue:**
   ```javascript
   // Bug: Server in UTC, user in PST
   const today = new Date(); // 2024-01-01 01:00 UTC
   // User logged in 2024-12-31 23:00 PST (= 2024-01-01 07:00 UTC)
   // Server thinks it's same day, but user crossed midnight locally
   ```

   **Fix:** Store user timezone, calculate streaks in their local time

2. **Clock Skew:**
   - User's device clock is wrong
   - Server clock drifted
   **Fix:** Use NTP-synced servers, validate client timestamps

3. **Activity Not Recorded:**
   ```javascript
   // Bug: User viewed missions but didn't complete one
   // Streak only updates on mission completion
   ```
   **Fix:** Update streak on any meaningful activity (login, view mission, etc.)

4. **Race Condition:**
   - Two requests update streak simultaneously
   - One overwrites the other
   **Fix:** Use atomic updates

5. **Calculation Bug:**
   ```javascript
   // Bug in updateStreak()
   const daysDifference = Math.floor((today - lastActivity) / (1000 * 60 * 60 * 24));
   // If lastActivity is 23 hours ago, daysDifference = 0 (correct)
   // If lastActivity is 25 hours ago, daysDifference = 1 (correct)
   // If lastActivity is 49 hours ago, daysDifference = 2 (streak broken!)
   ```

**Debug Process:**
1. Check `UserStats.lastActivityDate` in database
2. Check server logs for streak update calls
3. Reproduce with user's timezone
4. Add logging to `updateStreak()` method

---

### 25. **You notice the leaderboard query is slow. How would you identify the bottleneck?**

**Answer:**

**Step 1: Measure**
```javascript
const start = Date.now();
const leaderboard = await UserStats.find().sort({ totalXP: -1 }).limit(10);
console.log(`Query took ${Date.now() - start}ms`);
```

**Step 2: Explain Plan**
```javascript
const explain = await UserStats.find()
  .sort({ totalXP: -1 })
  .limit(10)
  .explain('executionStats');

console.log(explain.executionStats);
// Check:
// - totalDocsExamined (should be ~10, not 1 million)
// - executionTimeMillis
// - indexUsed (should use totalXP index)
```

**Step 3: Check Index**
```javascript
db.userstats.getIndexes();
// Verify { totalXP: -1 } exists
```

**Step 4: Check Collection Stats**
```javascript
db.userstats.stats();
// Check document count, average size
```

**Possible Issues:**

1. **No Index:** Add `{ totalXP: -1 }` index
2. **Index Not Used:** Query doesn't match index (e.g., sorting by `level` but index on `totalXP`)
3. **Large Documents:** Populate() fetching too much data
4. **Network Latency:** Database on different continent
5. **Lock Contention:** Writes blocking reads

**Optimization:**
```javascript
// Before: 500ms
const leaderboard = await UserStats.find()
  .sort({ totalXP: -1 })
  .limit(10)
  .populate('user');

// After: 50ms
const leaderboard = await UserStats.find()
  .sort({ totalXP: -1 })
  .limit(10)
  .select('totalXP level user') // Only needed fields
  .populate('user', 'firstName lastName profilePicture') // Only needed user fields
  .lean(); // Return plain objects, not Mongoose documents
```

---

### 26. **If you had to add real-time multiplayer coding challenges, how would you architect it?**

**Answer:**

**Requirements:**
- 2-4 kids code together in real-time
- See each other's cursors and edits
- Shared code execution

**Architecture:**

**1. WebSocket Layer (Socket.io):**
```javascript
// Backend
io.on('connection', (socket) => {
  socket.on('join-room', ({ roomId, userId }) => {
    socket.join(roomId);
    io.to(roomId).emit('user-joined', { userId });
  });

  socket.on('code-change', ({ roomId, delta }) => {
    socket.to(roomId).emit('code-update', { delta, userId });
  });
});
```

**2. Operational Transformation (OT) or CRDT:**
- **Problem:** User A types "hello" while User B deletes line 1
- **Solution:** Use OT library (ShareDB) or CRDT (Yjs) to resolve conflicts

**3. Room Management:**
```javascript
Room {
  id: String,
  users: [{ id, cursor, color }],
  code: String,
  language: String,
  createdAt: Date
}
```

**4. Code Execution:**
```javascript
// Sandboxed execution (Docker container)
POST /api/v1/execute
{
  code: "console.log('hello')",
  language: "javascript"
}
→ { output: "hello", error: null }
```

**5. Frontend (React):**
- Monaco Editor with multi-cursor support
- WebSocket connection for real-time sync
- Cursor position broadcasting

**Challenges:**
- **Latency:** Use optimistic updates
- **Security:** Sandbox code execution (VM2, Docker)
- **Scalability:** Room-based sharding
- **Persistence:** Save room state to MongoDB every 30 seconds

**Tech Stack:**
- Socket.io for WebSockets
- Yjs for CRDT
- Judge0 API for code execution
- Redis for room state

---

## 📚 Additional Preparation Tips

### Key Talking Points:
1. **Gamification:** XP formula, badge system, streak calculation
2. **Performance:** Indexing strategy, N+1 prevention, caching
3. **Security:** JWT flow, XSS/NoSQL injection prevention
4. **Scalability:** How you'd scale to millions of users
5. **Trade-offs:** MongoDB vs PostgreSQL, REST vs GraphQL

### Questions to Ask Interviewer:
1. "What's your current tech stack for similar projects?"
2. "How do you handle real-time features at scale?"
3. "What's your approach to gamification in educational products?"

### Demo Preparation:
- Have local dev environment running
- Prepare Postman collection with key API calls
- Show database schema in MongoDB Compass
- Walk through code flow for one feature (e.g., mission submission)

---

**Good luck with your interview! 🚀**
