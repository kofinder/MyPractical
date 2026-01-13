# 🔑 Key “Times” in Computing
> Understanding the different phases in the lifecycle of a program.

---

## **1. Design-time**
- When the programmer writes code (in IDE/editor).  
- Tools like IntelliSense, syntax highlighting, and static analysis run here.  
- **Example:** Compiler underlines errors before hitting "build."

---

## **2. Compile-time**
- When the compiler translates source code → machine code or bytecode.  
- Checks performed:  
  - Type checking  
  - Syntax validation  
  - Name resolution  
- **Example:** `int x = "hello";` → compile-time error.

---

## **3. Link-time**
- After compilation, the linker resolves symbols across modules.  
- **Example:** Function calls in one `.o` file resolved to definitions in another.  
- **Errors:** “undefined reference to function …”

---

## **4. Load-time**
- When the OS loads the program into memory before execution.  
- Dynamic libraries (`.dll`, `.so`) are bound here.  
- **Errors:** Missing shared libraries.

---

## **5. Run-time**
- When the program is executing.  
- Dynamic operations occur: heap allocation, polymorphism, reflection, exceptions.  
- **Errors:** Null pointer dereference, out-of-bounds, division by zero.

---

## **6. Link-time Optimization (LTO)**
- Advanced phase blending compilation and linking.  
- Optimizes across multiple modules.  
- **Example:** Inlining functions from other compilation units.

---

## **7. Just-In-Time (JIT) Compilation**
- For languages like Java, .NET, or LLVM JIT.  
- Code compiled to machine code **at runtime**, just before execution.

---

## **8. Ahead-Of-Time (AOT) Compilation**
- Compilation done **entirely before execution** (like C/C++).  
- Opposite of JIT.

---

## **9. Deployment-time**
- When software is shipped or installed.  
- **Errors:** Wrong environment, missing dependencies.

---

## **10. Debug-time**
- When debugging a program.  
- Tools attach extra checks (e.g., address sanitizers, Valgrind).  

---

# **Space vs Time Complexity**
> Measuring efficiency and memory usage of algorithms.

- **Space Complexity:** Amount of memory required for execution.  
- **Time Complexity:** Number of operations performed to complete execution.

---

# **Asymptotic Notations**
> Mathematical tools to express algorithm efficiency as input size `n` grows.

| Notation          | Meaning                                      | Interview Explanation                                                                 |
| ----------------- | -------------------------------------------- | ------------------------------------------------------------------------------------ |
| **O(f(n))**       | Upper bound (Worst-case)                     | Maximum time an algorithm could take as input grows.                                  |
| **Ω(f(n))**       | Lower bound (Best-case)                      | Minimum time an algorithm will take.                                                 |
| **Θ(f(n))**       | Tight bound (Average-case)                   | Algorithm grows at the same rate in both best and worst cases.                        |

**Key Points:**
- **Big O:** Worst-case scenario  
- **Big Omega:** Best-case scenario  
- **Big Theta:** Both bounds; average behavior

---

# **Big O Notation**
- Mathematical comparison of algorithm efficiency.  
- Focuses on **rate of growth** of operations, not actual execution time.  
- Helps evaluate scalability with increasing input size.

---

# **Time Complexity Examples**
| Complexity          | Notation | Description                          |
| ------------------ | -------- | ------------------------------------ |
| Constant time       | O(1)     | Operations do not depend on input size |
| Linear time         | O(n)     | Operations grow linearly with input size |
| Quadratic time      | O(n²)    | Operations grow quadratically         |
| Logarithmic time    | O(log n) | Operations reduce input size each step |
| Linearithmic time   | O(n log n)| Combination of linear and logarithmic growth |

---

# **Space Complexity**
- Measures memory required for execution, including:  
  - **Input space**: Memory for variables, input arrays  
  - **Auxiliary space**: Temporary memory used for computation (recursion, temporary arrays)
---

# **Common Asymptotic Notations**
| Notation    | Name    | Meaning                    |
| ----------- | ------- | -------------------------- |
| **O(f(n))** | Big O   | Upper bound → Worst-case   |
| **Ω(f(n))** | Omega   | Lower bound → Best-case    |
| **Θ(f(n))** | Theta   | Tight bound → Average-case |
---

# **Rules for Simplifying Complexity**
1. **Drop Constants**  
   - Ignore constant factors when writing time complexity.  
   - Example: O(3n²) → O(n²)

2. **Drop Non-Dominant Terms**  
   - As input size grows, smaller terms become negligible.  
   - Example: O(n² + n) → O(n²)
