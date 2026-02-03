# BitBuds Frontend Interview Preparation

## Project Overview
**BitBuds** - Kids Coding Platform built with React + TypeScript, Tailwind CSS, Vite

---

## BEGINNER LEVEL (5 Questions)

### 1. What is React and why did you use it for BitBuds?

**Answer:**
React is a JavaScript library for building user interfaces using reusable components.

**Why I chose React for BitBuds:**
- **Component Reusability:** Badge cards, mission cards used across multiple pages
- **Virtual DOM:** Fast updates for real-time progress tracking
- **Large Ecosystem:** Easy to find libraries for kids' educational features
- **Easy to Learn:** Simple for team collaboration

**Follow-up: What are components?**
Components are reusable pieces of UI. Example from BitBuds:
```jsx
function BadgeCard({ badge }) {
  return (
    <div className="badge-card">
      <img src={badge.icon} />
      <h3>{badge.name}</h3>
    </div>
  );
}
```

---

### 2. Explain the difference between props and state with examples from your project.

**Answer:**

**Props (Properties):**
- Data passed FROM parent TO child
- Read-only (cannot be modified by child)
- Example: Passing mission data to MissionCard

```jsx
// Parent
<MissionCard mission={missionData} />

// Child
function MissionCard({ mission }) {
  return <h2>{mission.title}</h2>; // Can read, cannot change
}
```

**State:**
- Data managed WITHIN a component
- Can be updated using setState
- Example: Login form input

```jsx
function LoginForm() {
  const [email, setEmail] = useState('');
  
  return (
    <input 
      value={email} 
      onChange={(e) => setEmail(e.target.value)} // Updates state
    />
  );
}
```

**Follow-up: Can you modify props?**
No! Props are read-only. If you need to change data, lift state up to parent or use state.

---

### 3. What is JSX? Why do we use it?

**Answer:**
JSX = JavaScript XML. It lets us write HTML-like code in JavaScript.

**Without JSX:**
```javascript
React.createElement('div', { className: 'card' }, 
  React.createElement('h1', null, 'Hello')
);
```

**With JSX:**
```jsx
<div className="card">
  <h1>Hello</h1>
</div>
```

**Benefits:**
- More readable and intuitive
- Easier to visualize UI structure
- Supports JavaScript expressions with `{}`

**In BitBuds:**
```jsx
<div className="mission-card">
  <h2>{mission.title}</h2>
  <p>XP: {mission.xpReward}</p>
  {mission.completed && <span>✓ Completed</span>}
</div>
```

---

### 4. How did you handle styling in BitBuds? Why Tailwind CSS?

**Answer:**

**Tailwind CSS** - Utility-first CSS framework

**Why I chose it:**
- **Fast Development:** No need to write custom CSS
- **Responsive:** Built-in breakpoints (`sm:`, `md:`, `lg:`)
- **Consistent Design:** Predefined spacing, colors
- **Small Bundle:** Purges unused styles in production

**Example from BitBuds:**
```jsx
<button className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded">
  Start Mission
</button>
```

**Responsive Design:**
```jsx
<div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-4">
  {/* 1 column on mobile, 2 on tablet, 3 on desktop */}
</div>
```

**Follow-up: What are the disadvantages of Tailwind?**
- Long className strings can be messy
- Learning curve for utility names
- HTML becomes cluttered

---

### 5. What is the Virtual DOM? How does it improve performance?

**Answer:**

**Virtual DOM** = Lightweight copy of the real DOM in memory

**How it works:**
1. State changes → React creates new Virtual DOM
2. React compares (diffs) new vs old Virtual DOM
3. React updates ONLY changed parts in real DOM

**Example in BitBuds:**
```jsx
// User earns XP
setXP(xp + 100); // Only XP number updates, not entire page
```

**Benefits:**
- Faster than updating entire DOM
- Batches multiple updates
- Minimizes browser reflows

**Follow-up: What is reconciliation?**
The process of comparing old and new Virtual DOM to find minimal changes needed.

---

## INTERMEDIATE LEVEL (8 Questions)

### 6. Explain React Hooks you used in BitBuds (useState, useEffect, useContext).

**Answer:**

**1. useState - Manage component state**
```jsx
const [missions, setMissions] = useState([]);
const [loading, setLoading] = useState(false);
```

**2. useEffect - Side effects (API calls, subscriptions)**
```jsx
useEffect(() => {
  // Fetch missions when component mounts
  fetchMissions();
}, []); // Empty array = run once
```

**3. useContext - Share data globally**
```jsx
// AuthContext.tsx
const AuthContext = createContext();

// In component
const { user, login, logout } = useContext(AuthContext);
```

**Follow-up: What's the dependency array in useEffect?**
- `[]` - Run once on mount
- `[count]` - Run when count changes
- No array - Run on every render

---

### 7. How did you implement authentication in BitBuds?

**Answer:**

**Authentication Flow:**

1. **Login → Get JWT Token**
```jsx
const login = async (email, password) => {
  const response = await axios.post('/api/v1/auth/login', { email, password });
  const { accessToken } = response.data;
  
  // Store token
  localStorage.setItem('token', accessToken);
  setUser(response.data.user);
};
```

2. **Protected Routes**
```jsx
function ProtectedRoute({ children }) {
  const { user } = useContext(AuthContext);
  
  if (!user) {
    return <Navigate to="/login" />;
  }
  
  return children;
}

// Usage
<Route path="/dashboard" element={
  <ProtectedRoute>
    <Dashboard />
  </ProtectedRoute>
} />
```

3. **Send Token with Requests**
```jsx
axios.interceptors.request.use(config => {
  const token = localStorage.getItem('token');
  if (token) {
    config.headers.Authorization = `Bearer ${token}`;
  }
  return config;
});
```

**Follow-up: Where do you store the token?**
- **localStorage** - Persists across sessions (used in BitBuds)
- **sessionStorage** - Cleared when browser closes
- **httpOnly cookie** - More secure (can't be accessed by JS)

---

### 8. How do you handle API calls in React? Explain error handling.

**Answer:**

**API Service Pattern:**
```jsx
// services/missionService.js
export const getMissions = async () => {
  try {
    const response = await axios.get('/api/v1/missions');
    return response.data;
  } catch (error) {
    throw error;
  }
};
```

**In Component:**
```jsx
const [missions, setMissions] = useState([]);
const [loading, setLoading] = useState(false);
const [error, setError] = useState(null);

useEffect(() => {
  const fetchMissions = async () => {
    setLoading(true);
    setError(null);
    
    try {
      const data = await getMissions();
      setMissions(data.missions);
    } catch (err) {
      setError(err.message || 'Failed to load missions');
    } finally {
      setLoading(false);
    }
  };
  
  fetchMissions();
}, []);

// UI
if (loading) return <Spinner />;
if (error) return <ErrorMessage message={error} />;
return <MissionList missions={missions} />;
```

**Follow-up: What is axios interceptor?**
Middleware to modify requests/responses globally (add auth headers, handle errors).

---

### 9. Explain React Router. How did you implement navigation in BitBuds?

**Answer:**

**React Router** - Library for client-side routing (navigation without page reload)

**Setup:**
```jsx
// App.tsx
import { BrowserRouter, Routes, Route } from 'react-router-dom';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/dashboard" element={<Dashboard />} />
        <Route path="/missions" element={<Missions />} />
        <Route path="/missions/:id" element={<MissionDetail />} />
      </Routes>
    </BrowserRouter>
  );
}
```

**Navigation:**
```jsx
import { useNavigate, Link } from 'react-router-dom';

// Declarative
<Link to="/missions">View Missions</Link>

// Programmatic
const navigate = useNavigate();
const handleComplete = () => {
  // After mission completion
  navigate('/dashboard');
};
```

**Dynamic Routes:**
```jsx
// missions/:id
import { useParams } from 'react-router-dom';

function MissionDetail() {
  const { id } = useParams(); // Get id from URL
  // Fetch mission with id
}
```

**Follow-up: Difference between Link and anchor tag?**
- `<Link>` - Client-side navigation (no page reload)
- `<a>` - Server-side navigation (full page reload)

---

### 10. How do you optimize performance in React applications?

**Answer:**

**Techniques I used in BitBuds:**

**1. Code Splitting (Lazy Loading)**
```jsx
import { lazy, Suspense } from 'react';

const Dashboard = lazy(() => import('./pages/Dashboard'));

<Suspense fallback={<Spinner />}>
  <Dashboard />
</Suspense>
```

**2. Memoization (React.memo)**
```jsx
const MissionCard = React.memo(({ mission }) => {
  return <div>{mission.title}</div>;
});
// Re-renders only if mission prop changes
```

**3. useMemo - Expensive Calculations**
```jsx
const sortedMissions = useMemo(() => {
  return missions.sort((a, b) => b.xp - a.xp);
}, [missions]); // Recalculate only when missions change
```

**4. useCallback - Prevent Function Recreation**
```jsx
const handleClick = useCallback(() => {
  console.log('Clicked');
}, []); // Function created once
```

**5. Debouncing Search**
```jsx
const [search, setSearch] = useState('');

useEffect(() => {
  const timer = setTimeout(() => {
    searchMissions(search);
  }, 500); // Wait 500ms after user stops typing
  
  return () => clearTimeout(timer);
}, [search]);
```

**Follow-up: When to use useMemo vs useCallback?**
- **useMemo** - Cache computed VALUES
- **useCallback** - Cache FUNCTIONS

---

### 11. How did you handle forms in BitBuds? Explain controlled vs uncontrolled components.

**Answer:**

**Controlled Components** (Used in BitBuds)
React controls the form state:

```jsx
function LoginForm() {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  
  const handleSubmit = (e) => {
    e.preventDefault();
    login(email, password);
  };
  
  return (
    <form onSubmit={handleSubmit}>
      <input 
        value={email} 
        onChange={(e) => setEmail(e.target.value)} 
      />
      <input 
        type="password"
        value={password} 
        onChange={(e) => setPassword(e.target.value)} 
      />
      <button type="submit">Login</button>
    </form>
  );
}
```

**Uncontrolled Components**
DOM controls the state (using refs):

```jsx
function UncontrolledForm() {
  const emailRef = useRef();
  
  const handleSubmit = (e) => {
    e.preventDefault();
    console.log(emailRef.current.value);
  };
  
  return (
    <form onSubmit={handleSubmit}>
      <input ref={emailRef} />
    </form>
  );
}
```

**Validation:**
```jsx
const [errors, setErrors] = useState({});

const validate = () => {
  const newErrors = {};
  if (!email.includes('@')) {
    newErrors.email = 'Invalid email';
  }
  if (password.length < 8) {
    newErrors.password = 'Password must be 8+ characters';
  }
  setErrors(newErrors);
  return Object.keys(newErrors).length === 0;
};

const handleSubmit = (e) => {
  e.preventDefault();
  if (validate()) {
    login(email, password);
  }
};
```

---

### 12. Explain component lifecycle. How does it relate to useEffect?

**Answer:**

**Class Component Lifecycle:**
1. **Mounting** - componentDidMount
2. **Updating** - componentDidUpdate
3. **Unmounting** - componentWillUnmount

**Functional Component (Hooks):**

```jsx
useEffect(() => {
  // componentDidMount + componentDidUpdate
  console.log('Component mounted or updated');
  
  return () => {
    // componentWillUnmount (cleanup)
    console.log('Component unmounting');
  };
}, [dependency]);
```

**Examples from BitBuds:**

**1. Fetch data on mount:**
```jsx
useEffect(() => {
  fetchMissions();
}, []); // componentDidMount
```

**2. Update when prop changes:**
```jsx
useEffect(() => {
  fetchMissionDetails(missionId);
}, [missionId]); // componentDidUpdate when missionId changes
```

**3. Cleanup (subscriptions, timers):**
```jsx
useEffect(() => {
  const timer = setInterval(() => {
    updateStreak();
  }, 60000);
  
  return () => clearInterval(timer); // componentWillUnmount
}, []);
```

---

### 13. How do you manage global state? Why did you use Context API?

**Answer:**

**Context API** - Share data across components without prop drilling

**Problem (Prop Drilling):**
```jsx
<App user={user}>
  <Header user={user}>
    <Profile user={user} /> {/* Passing through many levels */}
  </Header>
</App>
```

**Solution (Context):**

**1. Create Context:**
```jsx
// AuthContext.tsx
export const AuthContext = createContext();

export function AuthProvider({ children }) {
  const [user, setUser] = useState(null);
  
  const login = async (email, password) => {
    // Login logic
    setUser(userData);
  };
  
  const logout = () => {
    setUser(null);
    localStorage.removeItem('token');
  };
  
  return (
    <AuthContext.Provider value={{ user, login, logout }}>
      {children}
    </AuthContext.Provider>
  );
}
```

**2. Wrap App:**
```jsx
<AuthProvider>
  <App />
</AuthProvider>
```

**3. Use in Components:**
```jsx
function Dashboard() {
  const { user, logout } = useContext(AuthContext);
  
  return (
    <div>
      <h1>Welcome, {user.name}</h1>
      <button onClick={logout}>Logout</button>
    </div>
  );
}
```

**Follow-up: Context API vs Redux?**
- **Context API** - Simple, built-in, good for small apps (BitBuds)
- **Redux** - Complex, better for large apps with many state changes

---

## ADVANCED LEVEL (7 Questions)

### 14. How would you implement infinite scrolling for the mission list?

**Answer:**

**Approach:**

```jsx
function MissionList() {
  const [missions, setMissions] = useState([]);
  const [page, setPage] = useState(1);
  const [hasMore, setHasMore] = useState(true);
  const [loading, setLoading] = useState(false);
  
  const loadMore = async () => {
    if (loading || !hasMore) return;
    
    setLoading(true);
    const newMissions = await fetchMissions(page);
    
    if (newMissions.length === 0) {
      setHasMore(false);
    } else {
      setMissions([...missions, ...newMissions]);
      setPage(page + 1);
    }
    setLoading(false);
  };
  
  useEffect(() => {
    const handleScroll = () => {
      const bottom = window.innerHeight + window.scrollY >= document.body.offsetHeight - 100;
      if (bottom) {
        loadMore();
      }
    };
    
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, [missions, page]);
  
  return (
    <div>
      {missions.map(m => <MissionCard key={m.id} mission={m} />)}
      {loading && <Spinner />}
    </div>
  );
}
```

**Better: Intersection Observer API**
```jsx
const observer = useRef();
const lastMissionRef = useCallback(node => {
  if (loading) return;
  if (observer.current) observer.current.disconnect();
  
  observer.current = new IntersectionObserver(entries => {
    if (entries[0].isIntersecting && hasMore) {
      loadMore();
    }
  });
  
  if (node) observer.current.observe(node);
}, [loading, hasMore]);
```

---

### 15. How do you prevent XSS attacks in React?

**Answer:**

**XSS (Cross-Site Scripting)** - Injecting malicious scripts

**React's Built-in Protection:**
React escapes all values by default:

```jsx
const userInput = '<script>alert("XSS")</script>';
<div>{userInput}</div>
// Renders as text, not executed
```

**Dangerous: dangerouslySetInnerHTML**
```jsx
// AVOID THIS
<div dangerouslySetInnerHTML={{ __html: userInput }} />
// Script WILL execute!
```

**Safe Practices in BitBuds:**

**1. Sanitize User Input**
```jsx
import DOMPurify from 'dompurify';

const cleanHTML = DOMPurify.sanitize(userInput);
<div dangerouslySetInnerHTML={{ __html: cleanHTML }} />
```

**2. Validate on Backend**
```javascript
// Backend validation
const sanitizedTitle = validator.escape(req.body.title);
```

**3. Content Security Policy (CSP)**
```html
<meta http-equiv="Content-Security-Policy" 
      content="script-src 'self'">
```

**Follow-up: What other security concerns exist?**
- CSRF (Cross-Site Request Forgery)
- SQL Injection (backend)
- Insecure token storage

---

### 16. How would you implement real-time updates (live leaderboard)?

**Answer:**

**Option 1: Polling (Current in BitBuds)**
```jsx
useEffect(() => {
  const interval = setInterval(() => {
    fetchLeaderboard();
  }, 30000); // Every 30 seconds
  
  return () => clearInterval(interval);
}, []);
```

**Pros:** Simple, works everywhere  
**Cons:** Inefficient, not truly real-time

**Option 2: WebSockets (Better)**
```jsx
import io from 'socket.io-client';

useEffect(() => {
  const socket = io('http://localhost:5000');
  
  socket.on('leaderboard:update', (data) => {
    setLeaderboard(data);
  });
  
  return () => socket.disconnect();
}, []);
```

**Backend:**
```javascript
io.on('connection', (socket) => {
  socket.join('leaderboard');
});

// When user completes mission
io.to('leaderboard').emit('leaderboard:update', newData);
```

**Option 3: Server-Sent Events (SSE)**
```jsx
useEffect(() => {
  const eventSource = new EventSource('/api/leaderboard/stream');
  
  eventSource.onmessage = (event) => {
    setLeaderboard(JSON.parse(event.data));
  };
  
  return () => eventSource.close();
}, []);
```

**Comparison:**
- **Polling** - Simple, high latency
- **WebSockets** - Bidirectional, complex
- **SSE** - Server-to-client only, simpler than WebSockets

---

### 17. Explain code splitting and lazy loading. How does it improve performance?

**Answer:**

**Problem:** Loading entire app upfront = slow initial load

**Solution: Code Splitting**

**1. Route-based Splitting:**
```jsx
import { lazy, Suspense } from 'react';

const Dashboard = lazy(() => import('./pages/Dashboard'));
const Missions = lazy(() => import('./pages/Missions'));

function App() {
  return (
    <Suspense fallback={<Spinner />}>
      <Routes>
        <Route path="/dashboard" element={<Dashboard />} />
        <Route path="/missions" element={<Missions />} />
      </Routes>
    </Suspense>
  );
}
```

**2. Component-based Splitting:**
```jsx
const CodeEditor = lazy(() => import('./components/CodeEditor'));

function CodeLab() {
  return (
    <Suspense fallback={<div>Loading editor...</div>}>
      <CodeEditor />
    </Suspense>
  );
}
```

**Benefits:**
- Smaller initial bundle (faster first load)
- Load code only when needed
- Better user experience

**Vite automatically creates chunks:**
```
dist/
  ├── index.js (main bundle)
  ├── Dashboard.js (lazy loaded)
  └── Missions.js (lazy loaded)
```

**Follow-up: What is tree shaking?**
Removing unused code during build. Example: If you import only one function from lodash, only that function is bundled.

---

### 18. How do you handle errors in React? Explain Error Boundaries.

**Answer:**

**Error Boundary** - Component that catches JavaScript errors in child components

**Implementation:**
```jsx
class ErrorBoundary extends React.Component {
  constructor(props) {
    super(props);
    this.state = { hasError: false, error: null };
  }
  
  static getDerivedStateFromError(error) {
    return { hasError: true, error };
  }
  
  componentDidCatch(error, errorInfo) {
    console.error('Error:', error, errorInfo);
    // Log to error tracking service (Sentry)
  }
  
  render() {
    if (this.state.hasError) {
      return (
        <div className="error-page">
          <h1>Something went wrong</h1>
          <button onClick={() => window.location.reload()}>
            Reload Page
          </button>
        </div>
      );
    }
    
    return this.props.children;
  }
}

// Usage
<ErrorBoundary>
  <Dashboard />
</ErrorBoundary>
```

**What Error Boundaries DON'T catch:**
- Event handlers (use try-catch)
- Async code (setTimeout, promises)
- Server-side rendering
- Errors in Error Boundary itself

**For async errors:**
```jsx
const handleSubmit = async () => {
  try {
    await submitMission();
  } catch (error) {
    setError(error.message);
  }
};
```

---

### 19. How would you implement dark mode in BitBuds?

**Answer:**

**Approach 1: CSS Variables + Context**

**1. Define CSS Variables:**
```css
/* index.css */
:root {
  --bg-primary: #ffffff;
  --text-primary: #000000;
}

[data-theme="dark"] {
  --bg-primary: #1a1a1a;
  --text-primary: #ffffff;
}

body {
  background-color: var(--bg-primary);
  color: var(--text-primary);
}
```

**2. Theme Context:**
```jsx
const ThemeContext = createContext();

export function ThemeProvider({ children }) {
  const [theme, setTheme] = useState('light');
  
  useEffect(() => {
    const saved = localStorage.getItem('theme') || 'light';
    setTheme(saved);
    document.documentElement.setAttribute('data-theme', saved);
  }, []);
  
  const toggleTheme = () => {
    const newTheme = theme === 'light' ? 'dark' : 'light';
    setTheme(newTheme);
    localStorage.setItem('theme', newTheme);
    document.documentElement.setAttribute('data-theme', newTheme);
  };
  
  return (
    <ThemeContext.Provider value={{ theme, toggleTheme }}>
      {children}
    </ThemeContext.Provider>
  );
}
```

**3. Toggle Button:**
```jsx
function ThemeToggle() {
  const { theme, toggleTheme } = useContext(ThemeContext);
  
  return (
    <button onClick={toggleTheme}>
      {theme === 'light' ? '🌙' : '☀️'}
    </button>
  );
}
```

**Approach 2: Tailwind Dark Mode**
```jsx
// tailwind.config.js
module.exports = {
  darkMode: 'class',
};

// Component
<div className="bg-white dark:bg-gray-900 text-black dark:text-white">
  Content
</div>
```

---

### 20. How do you test React components?

**Answer:**

**Testing Library: React Testing Library + Jest**

**1. Component Test:**
```jsx
import { render, screen, fireEvent } from '@testing-library/react';
import LoginForm from './LoginForm';

test('renders login form', () => {
  render(<LoginForm />);
  
  expect(screen.getByLabelText('Email')).toBeInTheDocument();
  expect(screen.getByLabelText('Password')).toBeInTheDocument();
});

test('submits form with credentials', () => {
  const mockLogin = jest.fn();
  render(<LoginForm onLogin={mockLogin} />);
  
  fireEvent.change(screen.getByLabelText('Email'), {
    target: { value: 'test@example.com' }
  });
  fireEvent.change(screen.getByLabelText('Password'), {
    target: { value: 'password123' }
  });
  fireEvent.click(screen.getByText('Login'));
  
  expect(mockLogin).toHaveBeenCalledWith('test@example.com', 'password123');
});
```

**2. API Mock:**
```jsx
import axios from 'axios';
jest.mock('axios');

test('fetches missions', async () => {
  const missions = [{ id: 1, title: 'Mission 1' }];
  axios.get.mockResolvedValue({ data: { missions } });
  
  render(<MissionList />);
  
  const missionTitle = await screen.findByText('Mission 1');
  expect(missionTitle).toBeInTheDocument();
});
```

**3. Snapshot Testing:**
```jsx
test('matches snapshot', () => {
  const { container } = render(<BadgeCard badge={mockBadge} />);
  expect(container).toMatchSnapshot();
});
```

---

## SYSTEM DESIGN QUESTIONS (3 Questions)

### 21. Design the architecture for BitBuds frontend. Explain your folder structure.

**Answer:**

**Folder Structure:**
```
Frontend/
├── src/
│   ├── components/        # Reusable UI components
│   │   ├── Auth/
│   │   │   ├── AuthModal.tsx
│   │   │   └── ProtectedRoute.tsx
│   │   ├── Layout/
│   │   │   ├── Header.tsx
│   │   │   ├── Footer.tsx
│   │   │   └── Sidebar.tsx
│   │   └── Common/
│   │       ├── Button.tsx
│   │       └── Card.tsx
│   ├── pages/             # Page components
│   │   ├── Dashboard.tsx
│   │   ├── Missions.tsx
│   │   └── Badges.tsx
│   ├── contexts/          # Global state
│   │   └── AuthContext.tsx
│   ├── services/          # API calls
│   │   ├── authService.ts
│   │   └── missionService.ts
│   ├── hooks/             # Custom hooks
│   │   └── useFetch.ts
│   ├── utils/             # Helper functions
│   │   └── formatDate.ts
│   ├── types/             # TypeScript types
│   │   └── mission.ts
│   └── App.tsx
```

**Design Principles:**
- **Separation of Concerns:** Components, logic, data separate
- **Reusability:** Common components in `components/`
- **Scalability:** Easy to add new features
- **Maintainability:** Clear structure for team collaboration

**Data Flow:**
```
User Action → Component → Service → API → Backend
                ↓
            Update State (Context)
                ↓
            Re-render UI
```

---

### 22. How would you scale BitBuds to handle 100,000 concurrent users?

**Answer:**

**Frontend Optimizations:**

**1. CDN for Static Assets**
- Host images, CSS, JS on CloudFront/Cloudflare
- Reduces server load, faster delivery

**2. Code Splitting**
```jsx
const Dashboard = lazy(() => import('./Dashboard'));
// Load only when user navigates to dashboard
```

**3. Caching Strategy**
```jsx
// Cache mission list (changes rarely)
const cachedMissions = localStorage.getItem('missions');
if (cachedMissions && !isStale) {
  setMissions(JSON.parse(cachedMissions));
} else {
  fetchMissions();
}
```

**4. Image Optimization**
- Use WebP format
- Lazy load images
```jsx
<img loading="lazy" src="mission.webp" />
```

**5. Debounce/Throttle**
```jsx
// Search input
const debouncedSearch = debounce(searchMissions, 500);
```

**6. Virtual Scrolling**
For long lists, render only visible items:
```jsx
import { FixedSizeList } from 'react-window';

<FixedSizeList
  height={600}
  itemCount={1000}
  itemSize={50}
>
  {MissionRow}
</FixedSizeList>
```

**Backend Considerations:**
- Load balancer (Nginx)
- Database read replicas
- Redis caching
- Horizontal scaling

---

### 23. Design a real-time collaborative coding feature (2 kids coding together).

**Answer:**

**Requirements:**
- Two users edit same code simultaneously
- See each other's cursors
- Sync changes in real-time

**Architecture:**

**1. WebSocket Connection**
```jsx
const socket = io('http://localhost:5000');

useEffect(() => {
  socket.emit('join-room', { roomId, userId });
  
  socket.on('user-joined', ({ userId, userName }) => {
    setUsers([...users, { userId, userName }]);
  });
  
  socket.on('code-change', ({ delta, userId }) => {
    applyChange(delta);
  });
  
  return () => socket.disconnect();
}, []);
```

**2. Code Editor (Monaco/CodeMirror)**
```jsx
import Editor from '@monaco-editor/react';

const handleChange = (value) => {
  const delta = calculateDelta(previousValue, value);
  socket.emit('code-change', { roomId, delta, userId });
  setPreviousValue(value);
};

<Editor
  value={code}
  onChange={handleChange}
  language="javascript"
/>
```

**3. Cursor Tracking**
```jsx
const handleCursorChange = (position) => {
  socket.emit('cursor-move', { roomId, userId, position });
};

socket.on('cursor-move', ({ userId, position }) => {
  updateCursor(userId, position);
});
```

**4. Conflict Resolution (Operational Transformation)**
Use library like Yjs or ShareDB to handle simultaneous edits

**Backend (Socket.io):**
```javascript
io.on('connection', (socket) => {
  socket.on('join-room', ({ roomId, userId }) => {
    socket.join(roomId);
    io.to(roomId).emit('user-joined', { userId });
  });
  
  socket.on('code-change', ({ roomId, delta }) => {
    socket.to(roomId).emit('code-change', { delta, userId: socket.id });
  });
});
```

**Challenges:**
- Latency handling
- Conflict resolution
- Scalability (room management)

---

## BONUS: Common Follow-up Questions

**Q: Why React over Angular/Vue?**
- Easier learning curve
- Larger community
- Better for component reusability

**Q: What's the difference between React and React Native?**
- React - Web apps (DOM)
- React Native - Mobile apps (native components)

**Q: What is Redux? When would you use it?**
- State management library
- Use for complex apps with many state changes
- BitBuds uses Context API (simpler for small apps)

**Q: What are Higher-Order Components (HOC)?**
Functions that take a component and return enhanced component:
```jsx
const withAuth = (Component) => {
  return (props) => {
    const { user } = useContext(AuthContext);
    if (!user) return <Navigate to="/login" />;
    return <Component {...props} />;
  };
};
```

**Q: What is prop drilling? How to avoid it?**
Passing props through many levels. Avoid with Context API or state management.

---

## Interview Tips

1. **Start with simple explanation, then go deeper**
2. **Use examples from YOUR project**
3. **Mention trade-offs** (shows maturity)
4. **Ask clarifying questions** before answering
5. **Draw diagrams** for architecture questions
6. **Be honest** if you don't know something

**Good luck! 🚀**
