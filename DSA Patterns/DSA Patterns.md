# 🚀 DSA 25 Patterns Master Guide

A **complete guide** to mastering the **25 most important DSA problem-solving patterns** for cracking **FAANG & product-based company interviews**.  
This repository contains **descriptions, syntax, usage, and example problems** for each pattern.

---

## 📚 Why This Guide?
Most coding interview problems can be **mapped to known patterns**.  
If you can **identify the pattern**, you can solve the problem much faster.  
Instead of practicing 500+ random problems, you focus on mastering **25 core templates**.

---

## 🧩 Patterns Covered

### **Beginner → Intermediate**
1. **Sliding Window**
2. **Two Pointers**
3. **Fast & Slow Pointers (Tortoise-Hare)**
4. **Prefix Sum**
5. **Hash Map / Frequency Map**
6. **Stack Pattern**
7. **Binary Search**
8. **Backtracking**
9. **Dynamic Programming (Basic)**
10. **BFS / DFS**
11. **Heap / Priority Queue**
12. **Union-Find (Disjoint Set)**
13. **Bitmasking**

### **Advanced**
14. **Monotonic Stack / Queue**
15. **Matrix Traversal**
16. **Topological Sort**
17. **Meet in the Middle**
18. **Sweep Line Algorithm**
19. **Binary Search on Answer**
20. **Segment Tree / Fenwick Tree**
21. **Trie**
22. **KMP / Z-Algorithm / Rabin-Karp**
23. **Manacher’s Algorithm**
24. **Euler Tour / Binary Lifting**
25. **Kadane’s Algorithm Variations**

---

## 🛠 Pattern Structure

Each pattern in this guide contains:
- **Description** – What it is and why it works.
- **Where to Use** – Problem types that fit this pattern.
- **How to Apply** – Step-by-step approach.
- **Syntax** – Ready-to-use C++ template.
- **Example Problems** – LeetCode, GFG, or InterviewBit links.

---

## 📄 1. Sliding Window

**Description:**  
A technique where a fixed-size or variable-size "window" is moved across an array/string to reuse results instead of recomputing from scratch.

**Where to Use:**  
- Subarray/substring problems  
- Longest substring without repeating characters  
- Max/Min sum of subarray of size `k`

**How to Apply:**  
1. Initialize start and end pointers for the window.  
2. Expand end to add elements.  
3. Shrink start when condition is violated.  
4. Update result.

**Syntax (C++):**
<img width="949" height="350" alt="image" src="https://github.com/user-attachments/assets/53e00979-37ab-4de3-aec2-b28e47b944ae" />
---

## 2. Two Pointer

**Description:**  
Two indexes moving towards each other (or same direction) to solve problems without nested loops.

**Where to Use:**  
- Sorted arrays for pair finding
- Merging sorted arrays
- Removing duplicates in place
  
**How to Apply:**  
1. Sort if needed
2. Initialize pointers (left, right)
3. Move pointers based on conditions

**Syntax (C++):**
<img width="950" height="254" alt="image" src="https://github.com/user-attachments/assets/db2c54ef-70bc-4f93-a851-30a4a94f8428" />


## 2. Binary Search

**Description:**  
Divide search space in half repeatedly until you find the target.

**Where to Use:**  
- orted arrays
- Value space search (Binary Search on Answer)
  
**How to Apply:**  
1. Sort if needed
2. Initialize pointers (left, right)
3. Move pointers based on conditions

<img width="948" height="264" alt="image" src="https://github.com/user-attachments/assets/82da9c6f-6988-4e68-aaca-848949d4fb52" />


