# Run Command
* make

# EXPRIMENT COMMAND
* man objdump
* objdump -t cxx.


# MEMORY CHECKER
* g++ -std=c++17 main.cpp -o program
* valgrind ./program
* https://valgrind.org/docs/manual/quick-start.html#quick-start.prepare


# Fundamental Principles of OOP

**Class** - A blueprint or template that defines the structure (data members) and behavior (methods) of objects.

**Object** - A specific instance of a class, representing a concrete example of the structure defined by that class.

**Instance** - Another term for an object; it emphasizes that this is a specific occurrence of a class.

**Instantiating** - The process of creating an object from a class.

**Data Members** - Variables that hold data or state for the object.

**Methods** - Functions defined within a class that describe the behaviors or actions the object can perform.

**Abstraction** - The concept of simplifying complex systems by hiding unnecessary details and exposing only the essential features.

**Encapsulation** - The practice of restricting direct access to some of an object's components, allowing access only through well-defined public interfaces (methods).

**Inheritance** - A mechanism that allows a class (derived class or child class) to inherit properties and methods from another class (base class or parent class).

**Polymorphism** - The ability to treat different object types (that share the same base type) as instances of their common base class, allowing for methods to behave differently based on the object being referenced.

# Keys Concept Of OOP

**Class** - Describes the structure of an object.

**Object** - A specific example (instance) of that structure.

**Instance** - Another name for an object.

**Instantiating** - Creating an object from a class.

**Data Members** - Variables that hold the state of an object.

**Methods** - Functions defined within a class.

**Abstraction** - A concept that simplifies complexity by hiding intricate details.

**Encapsulation** - Granting access to private data only through controlled public interfaces (methods).

**Inheritance** - The ability to create derived classes that inherit properties from their parent class.

**Polymorphism** - The ability to treat objects of different classes as if they are instances of a common base class.


# Keys of constexpr
--------------------------------
When Should You Use constexpr?
Variables: When you have constant values that should be known at compile time, and you want to allow the compiler to perform optimizations.

Functions: When the function's logic can be evaluated at compile time for certain inputs, reducing the need for recalculations at runtime.

Classes: When you want to create constant objects that can be used in constant expressions and have compile-time construction.

Differences from const:
const makes a variable read-only but doesn't necessarily enforce compile-time evaluation.
constexpr guarantees compile-time evaluation, where possible, and can be used to create constant expressions, ensuring higher efficiency.


# Fundamental Rules of Allocation/Deallocation Properties
Each object allocated with malloc() must be deallocated with free().

Using free() on memory allocated with malloc() ensures proper deallocation in C-style memory management.
Each object allocated with new must be deallocated with delete.

Using delete to deallocate objects created with new ensures that both memory and object destructors are handled properly.
Each array allocated with new[] must be deallocated with delete[].

Failing to use delete[] for arrays allocated with new[] may cause undefined behavior or memory leaks, as delete[] ensures that destructors for each element in the array are called.
malloc(), new, and new[] never return a NULL pointer in a successful allocation (except for zero-size allocations, which are implementation-defined).

If the allocation fails, new and new[] will throw a std::bad_alloc exception unless nothrow versions are used (i.e., new(std::nothrow)), in which case they return nullptr.

Note: If you use malloc(), it returns NULL on failure, and you must manually check for this case.

free(), delete, and delete[] can be safely applied to NULL or nullptr pointers without causing errors.

Deallocating a NULL pointer is safe and has no effect.
Additional Best Practices and Clarifications
Avoid mixing malloc()/free() with new/delete.

Always pair malloc() with free() and new with delete. Mixing them (e.g., using free() for memory allocated with new) leads to undefined behavior, as they manage memory differently.
new vs. new(std::nothrow):

In low-memory conditions, new throws a std::bad_alloc exception. If you prefer a non-throwing version, use new(std::nothrow), which returns nullptr instead of throwing an exception.
Deallocation of partial objects:

If new fails in the middle of a complex object’s constructor, destructors will be called for all successfully initialized members, but any partially constructed objects should still be handled carefully to avoid leaks.
Use RAII (Resource Acquisition Is Initialization) for safer memory management.

Prefer using smart pointers like std::unique_ptr or std::shared_ptr to manage dynamically allocated objects. They automatically release memory when the pointer goes out of scope, reducing the risk of memory leaks.

Prefer using new or smart pointers in C++ because they work better with constructors, destructors, and exception handling. C++ provides more robust memory management tools than C.
Avoid zero-size allocations.

Though zero-size allocations (e.g., malloc(0)) are implementation-defined and legal, avoid them, as they can lead to unexpected behavior. Always check the size before allocating memory.
Double delete (or free) is dangerous.

Never free or delete a pointer twice, as this leads to undefined behavior (usually a crash or heap corruption). After freeing or deleting a pointer, set it to nullptr to avoid accidental reuse.
Order of deletion in inheritance hierarchies.

When deleting a derived class object through a base class pointer, ensure the destructor in the base class is marked virtual, or only the base class destructor will run, leading to resource leaks in the derived class.

Memory Management in Modern C++:
Avoid manual memory management when possible. Modern C++ encourages the use of automatic resource management techniques such as smart pointers and containers (std::vector, std::string, etc.), which handle allocation and deallocation for you.
