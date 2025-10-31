

# MEMORY MANAGEMENT

### 1. Empty Base Optimization (EBO)
- **Definition:** Compiler optimization to avoid allocating extra space for empty base classes.
- **Example:** `struct Empty {}; struct Derived : Empty { int x; };`  
  `sizeof(Derived)` may equal `sizeof(int)`.

### 2. Ill-Formed, No Diagnostic Required (IFNDR)
- **Definition:** Certain incorrect C++ code that the compiler is not required to diagnose.
- **Example:** Some violations of template rules in SFINAE contexts.
- **Key point:** Can silently compile, behavior undefined.

### 3. ODR Violation (One Definition Rule)
- **Definition:** A program should have exactly one definition of each object/function; violations lead to undefined behavior.
- **Example:** Defining the same function in multiple translation units.

### 4. Pointer Interconvertibility
- **Definition:** Two pointers to related objects can be safely converted to one another under certain conditions.
- **Key point:** Allows casting between base and derived objects safely in memory.

### 5. Memory Tagging Extensions (MTEs)
- **Definition:** Hardware/OS support to detect memory safety issues (like use-after-free).
- **Example:** ARM MTE tagging memory to catch invalid accesses at runtime.

### 6. Undefined Behavior (UB)
- **Definition:** Any code behavior not defined by the C++ standard.
- **Example:** Dereferencing a null pointer, out-of-bounds array access.
- **Key point:** UB can lead to crashes or unexpected results; must avoid.

### 7. Type Punning
- **Definition:** Accessing data as a different type than it was defined as.
- **Example:** Using unions or `reinterpret_cast`.
- **Key point:** Can break strict aliasing rules if not done carefully.

### 8. `std::start_lifetime_as<T>()` & `std::memcpy()`
- **`std::start_lifetime_as<T>()`:** Safely begins the lifetime of an object in allocated memory.  
- **`std::memcpy()`:** Can be used to copy object representation bytes; can be combined with lifetime management.

### 9. Casts and cv-qualifications
- **Definition:** Converting between types and managing `const`/`volatile` qualifiers.
- **Example:** `const_cast`, `reinterpret_cast`, `static_cast`.
- **Key point:** Helps in low-level memory manipulations but must preserve UB rules.

### 10. RAII and C++’s Special Member Functions
- **RAII (Resource Acquisition Is Initialization):** Manage resources via object lifetime.
- **Special member functions:** Constructors, destructors, copy/move constructors, copy/move assignment.
- **Example:** `std::unique_ptr` automatically releases memory.

---
