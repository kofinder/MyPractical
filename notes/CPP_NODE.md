MEMORY MANAMGEMENT
1. empty base optimization
2. Ill-formed, no diagnostic required (IFNDR)
3. ODR violation (One Definition Rule)
4. Pointer interconvertibility
5. Memory Tagging Extensions (MTEs)
6. Undefined Behavior (UB)
7. Type punning
8. The std::start_lifetime_as<T>() function &  std::memcpy() function
9. Casts and cv-qualifications
10. RAII and C++’s special member functions

TEMPLATES
1. Defining member function templates



# MEMORY LAYOUTS
+------------------------+
| Stack (local variables)|
+------------------------+
| Heap (dynamic memory)  |
+------------------------+
| BSS (uninitialized data)|
+------------------------+
| Data (initialized globals)|
+------------------------+
| Text (code instructions) |
+------------------------+


# Java memory layout
------------------------------------ ----------------------------------------------------------------------------------- -----------------------------------------------------------------------------------------------------
| **Memory Segment**                | **Purpose / What it Stores**                                                      | **Notes / JVM Mapping**                                                                            |
| --------------------------------- | --------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| **Method Area**                   | Class-level data: class definitions, static variables, constants, method bytecode | Corresponds to **Text, Data, BSS** segments in traditional memory layout; shared among all threads |
| **Heap**                          | All **objects and arrays** created at runtime                                     | Garbage-collected; instance variables reside here                                                  |
| **Stack**                         | **Method call frames**, local variables, and references                           | Each thread has its own stack; memory is released when method call ends                            |
| **Program Counter (PC) Register** | Holds **address of the current instruction** for each thread                      | One PC register per thread                                                                         |
| **Native Method Stack**           | Memory for **native (non-Java) method execution**                                 | Used when Java calls native libraries (JNI)                                                        |
------------------------------------ ------------------------------------------------------------------------------------ ----------------------------------------------------------------------------------------------------

# Mapping to Classical Segments
-------------------- -------------- ---------------------------------
| Classical Segment | JVM Area    | Explanation                     |
| ----------------- | ----------- | ------------------------------- |
| **Text**          | Method Area | Method bytecode                 |
| **Data**          | Method Area | Initialized static fields       |
| **BSS**           | Method Area | Uninitialized static fields     |
| **Heap**          | Heap        | Objects and arrays              |
| **Stack**         | Stack       | Local variables & method frames |
-------------------- ------------- ---------------------------------

# Memory Samgemnt
------------ ---------------------------------- ---------------- ------------------------
| Segment   | Stores                           | Access         | Purpose               |
| --------- | -------------------------------- | -------------- | --------------------- |
| **Text**  | Code (machine instructions)      | Read + Execute | Runs your program     |
| **Data**  | Initialized globals              | Read + Write   | Keeps static data     |
| **BSS**   | Uninitialized globals            | Read + Write   | Zero-initialized vars |
| **Heap**  | Dynamically allocated memory     | Read + Write   | `new` / `malloc`      |
| **Stack** | Local variables & function calls | Read + Write   | Call frames           |
------------ ---------------------------------- ---------------- ------------------------


The Method Area in Java corresponds to:
    Text segment – method bytecode
    Data segment – initialized static fields
    BSS segment – uninitialized static fields
So, Text + Data + BSS relate to the Method Area.