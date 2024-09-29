
# Learning Resources
Explore these resources for in-depth understanding and guidance on C++:

- [C++ Reference](https://en.cppreference.com)
- [Simplify C++](https://simplifycpp.org)
- [Modern C++ Programming](https://github.com/federico-busato/Modern-CPP-Programming)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html#quick-start.prepare)
- [Lambda Functions in C++](https://www.gyata.ai/c-plus-plus/lambda-functions)

---

# Memory Debugging
Memory debugging is essential for identifying and resolving memory-related issues. Here are some tools and techniques to assist you:

## Enable Compiler Flags for Debugging
When compiling your program, use the following flags to enable debugging information and sanitizers:

```bash
g++ -g -Wall -Wextra -pedantic -fsanitize=address -fsanitize=undefined -o my_program my_program.cpp
```

### Flags Explained:
- `-g`: Generates debugging information for use with a debugger.
- `-Wall -Wextra`: Enables comprehensive warnings for potential issues in the code.
- `-fsanitize=address`: Activates the AddressSanitizer to detect memory errors, such as out-of-bounds access.
- `-fsanitize=undefined`: Enables checks for undefined behavior in the code.

## Valgrind (Memory Leak Detection)
Valgrind is a powerful tool for detecting memory leaks and memory management issues.

```bash
valgrind --leak-check=full --track-origins=yes ./my_program
```

### Options Explained:
- `--leak-check=full`: Provides detailed information about memory leaks.
- `--track-origins=yes`: Helps identify the origin of uninitialized memory reads.

## AddressSanitizer (ASan)
For detecting memory errors at runtime, compile with ASan:

```bash
g++ -fsanitize=address -g -o my_program my_program.cpp
```

## Undefined Behavior Sanitizer (UBSan)
To check for undefined behaviors, compile with UBSan:

```bash
g++ -fsanitize=undefined -g -o my_program my_program.cpp
```

## Static Code Analysis
Static analysis tools can identify potential issues in your code before runtime.

- Using `scan-build`:
  ```bash
  scan-build g++ -o my_program my_program.cpp
  ```

- Using `cppcheck`:
  ```bash
  cppcheck --enable=all my_program.cpp
  ```

## Heap Profiling Tools
Use Valgrind's Massif tool for heap profiling to analyze memory usage.

```bash
valgrind --tool=massif ./my_program
massif-visualizer massif.out.<pid>
```

## Third-Party Memory Debugging Tools
You can also utilize third-party tools for memory debugging:

```bash
drmemory -- ./my_program
```

---

# Code Debugging with LLDB
LLDB is a powerful debugger for inspecting and modifying program execution.

## Basic LLDB Commands
- **Run with arguments:**
  ```bash
  lldb -- file.out args
  ```
- **Run the program:**
  ```bash
  lldb run  # or lldb r
  ```

## Breakpoints
Set breakpoints to pause execution at specific points in your code.

- **Set a breakpoint in a file:**
  ```bash
  lldb break set -f file.cpp -l <line_number>
  ```

- **Set a breakpoint on a function:**
  ```bash
  lldb break square(int)  # Using implicit name
  lldb break Program:Program()  # Class constructor
  lldb break LLDBProgram::add(int, int)  # Namespaced function
  ```

## Navigation Commands
- **Step over the next line:**
  ```bash
  next
  ```

- **Step into the next line:**
  ```bash
  step
  ```

- **Continue execution:**
  ```bash
  c
  ```

- **Backtrace of the stack:**
  ```bash
  bt
  ```

- **Switch to a specific frame:**
  ```bash
  frame select 0
  ```

## Watchpoints
Watchpoints are useful for monitoring variable changes.

- **Set a watchpoint on a variable:**
  ```bash
  watchpoint set variable globalvariable
  ```

- **Set a watchpoint with access control:**
  ```bash
  watchpoint set variable -w read | write | read_write globalVar
  ```

- **Watchpoint for member variables:**
  ```bash
  watchpoint set variable d.memberVarable
  ```

---