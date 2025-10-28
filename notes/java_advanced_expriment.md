


# Thread Analysis    
    *** A thread is a unit of execution inside a process. Every process has at least one thread, called the main thread. A process can be single-threaded or multi-threaded ***

1. "A thread is a unit of execution inside a process."
    * A thread executes code within the context of a process.

2. "Every process has at least one thread, called the main thread."
    * When a program starts, the JVM creates a main thread to run the main() method.
    *  Even if you create no other threads, the process still has this main thread.

3. "A process can be single-threaded or multi-threaded."
    * Single-threaded → only the main thread executes.
    * Multi-threaded → additional threads are created alongside the main thread.


 # UNARY OPERATOR
 1. Bitwise AND - “both must be 1 for the result to be 1. if not 0”

 2. Operator (XOR) - “1 if the bits are different, 0 if they are the same.”

 3. Operator (Right Shift) - “Moves the bits of a number to the right by a certain number of positions”

 4. Operator (Left Shift) - “Moves the bits of a number to the left by a certain number of positions” / “Left shift is like multiplying by 2 for each shift”







# THREAD STATE - Here are all 6 thread states and what they mean:
-------------------- ------------------------------------------
| State             | Description                             |
| ----------------- | --------------------------------------- |
| **NEW**           | Thread created but not started          |
| **RUNNABLE**      | Ready to run or running                 |
| **BLOCKED**       | Waiting for a monitor lock              |
| **WAITING**       | Waiting indefinitely for another thread |
| **TIMED_WAITING** | Waiting for a specified time            |
| **TERMINATED**    | Execution completed                     |
-------------------- -----------------------------------------


# LIST: Time Complexity + Thread Safety
--------------------------- -------------------- ----------------- --------------------------- ----------------------------------- ------------------------------------------------------
| Class                    | Thread-Safe?      | Access (get/set) | Search (contains/indexOf) | Insert/Delete                     | Notes                                                |
| ------------------------ | ----------------  | ---------------- | ------------------------- | --------------------------------- | ---------------------------------------------------- |
| **ArrayList**            | ❌                | O(1)             | O(n)                      | O(n) worst-case (shift elements)  | Resizable array                                      |
| **LinkedList**           | ❌                | O(n)             | O(n)                      | O(1) at ends, O(n) middle         | Doubly-linked list                                   |
| **Vector**               | ✅ (synchronized) | O(1)             | O(n)                      | O(n) worst-case                   | Legacy, synchronized                                 |
| **Stack**                | ✅ (synchronized) | O(1)             | O(n)                      | O(1) (push/pop)                   | Extends Vector                                       |
| **CopyOnWriteArrayList** | ✅                | O(1)             | O(n)                      | O(n) (copy entire array on write) | Best for read-heavy                                  |
| **SynchronizedList**     | ✅ (wrapper)      | O(1)             | O(n)                      | O(n)                              | Uses single lock; iteration needs synchronized block |
---------------------------- ------------------ ------------------- --------------------------- ---------------------------------- -------------------------------------------------------

# SET: Time Complexity + Thread Safety
----------------------------- -------------- ----------- ---------- ------------------- -------------------------------
| Class                     | Thread-Safe?  | Add      | Remove   | Search (contains) | Notes                         |
| ------------------------- | ------------  | -------- | -------- | ----------------- | ----------------------------- |
| **HashSet**               | ❌            | O(1) avg | O(1) avg | O(1) avg          | Backed by HashMap             |
| **LinkedHashSet**         | ❌            | O(1) avg | O(1) avg | O(1) avg          | Maintains insertion order     |
| **TreeSet**               | ❌            | O(log n) | O(log n) | O(log n)          | Red-Black Tree, sorted        |
| **CopyOnWriteArraySet**   | ✅            | O(n)     | O(n)     | O(n)              | Based on CopyOnWriteArrayList |
| **ConcurrentSkipListSet** | ✅            | O(log n) | O(log n) | O(log n)          | Thread-safe, sorted           |
| **SynchronizedSet**       | ✅            | O(1) avg | O(1) avg | O(1) avg          | Wrapper with coarse lock      |
---------------------------- --------------- ---------- ---------- -------------------- -------------------------------

# MAP: Time Complexity + Thread Safety
----------------------------- ------------- ---------- ----------- ---------- ----------------------------------------------
| Class                     | Thread-Safe?  | Put      | Get      | Remove   | Notes                                         |
| ------------------------- | ------------  | -------- | -------- | -------- | --------------------------------------------- |
| **HashMap**               | ❌            | O(1) avg | O(1) avg | O(1) avg | Backed by array+linked list/tree after Java 8 |
| **LinkedHashMap**         | ❌            | O(1) avg | O(1) avg | O(1) avg | Maintains insertion order                     |
| **TreeMap**               | ❌            | O(log n) | O(log n) | O(log n) | Red-Black Tree, sorted                        |
| **ConcurrentHashMap**     | ✅            | O(1) avg | O(1) avg | O(1) avg | Lock-free, high-performance concurrency       |
| **ConcurrentSkipListMap** | ✅            | O(log n) | O(log n) | O(log n) | Sorted, concurrent                            |
| **Hashtable**             | ✅            | O(1) avg | O(1) avg | O(1) avg | Legacy synchronized                           |
| **SynchronizedMap**       | ✅            | O(1) avg | O(1) avg | O(1) avg | Wrapper using coarse-grained lock             |
---------------------------- --------------- ---------- ----------- ---------- -----------------------------------------------

# QUEUE: Time Complexity + Thread Safety
----------------------------- ------------- ------------- ----------- -------- --------------------------------------
| Class                     | Thread-Safe?  | Add       | Remove    | Search | Notes                                |
| ------------------------- | ------------  | --------- | --------- | ------ | ------------------------------------ |
| **PriorityQueue**         | ❌            | O(log n)  | O(log n)  | O(n)   | Heap-based priority queue            |
| **ArrayDeque**            | ❌            | O(1)      | O(1) ends | O(n)   | Resizable array deque                |
| **LinkedList**            | ❌            | O(1) ends | O(1) ends | O(n)   | Can act as queue/deque               |
| **ConcurrentLinkedQueue** | ✅            | O(1)      | O(1)      | O(n)   | Lock-free, unbounded                 |
| **ConcurrentLinkedDeque** | ✅            | O(1)      | O(1)      | O(n)   | Lock-free, double-ended              |
| **LinkedBlockingQueue**   | ✅            | O(1)      | O(1)      | O(n)   | Blocking, uses locks                 |
| **ArrayBlockingQueue**    | ✅            | O(1)      | O(1)      | O(n)   | Bounded blocking queue               |
| **PriorityBlockingQueue** | ✅            | O(log n)  | O(log n)  | O(n)   | Blocking priority queue              |
| **SynchronousQueue**      | ✅            | O(1)      | O(1)      | N/A    | No internal capacity; direct handoff |
---------------------------- ---------------- ---------- ------------ -------- --------------------------------------



-------------------------- ----------------------------------------------------------------------------------------------------------- -------------------------------------------------------------------
| **Keyword**             | **Purpose / Meaning**                                                                                     | **Example**                                                      |
| ----------------------- | --------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------- |
| `module`                | Declares the module and its name                                                                          | `module com.ejavaguru { }`                                       |
| `requires`              | Specifies a dependency on another module                                                                  | `requires java.logging;`                                         |
| `exports`               | Makes a package accessible to other modules                                                               | `exports com.ejavaguru.api;`                                     |
| `opens`                 | Makes a package accessible **via reflection** (for frameworks like serialization or dependency injection) | `opens com.ejavaguru.impl;`                                      |
| `uses`                  | Declares a **service interface** the module consumes                                                      | `uses com.ejavaguru.Service;`                                    |
| `provides ... with ...` | Declares a **service implementation** for a service interface                                             | `provides com.ejavaguru.Service with com.ejavaguru.ServiceImpl;` |
| `with`                  | Paired with `provides` to specify implementation                                                          | See above (`provides ... with ...`)                              |
-------------------------- ----------------------------------------------------------------------------------------------------------- -------------------------------------------------------------------

---------------------------- ------------------------------------------------- ---------------------------------------------------------- --------------------------------------------------------
| Feature                  | Static Initializer                               | Instance Initializer                                     | Constructor                                            |
| ------------------------ | ------------------------------------------------ | -------------------------------------------------------- | ------------------------------------------------------ |
| **Syntax**               | `static { ... }`                                 | `{ ... }`                                                | `ClassName() { ... }`                                  |
| **Execution Time**       | When class is loaded (once)                      | Every time an object is created                          | Every time an object is created (after instance block) |
| **Number of Executions** | Once per class                                   | Once per object                                          | Once per object                                        |
| **Access**               | Only static variables                            | Instance & static variables                              | Instance & static variables                            |
| **Purpose**              | One-time setup (static variables, configuration) | Common initialization for all constructors               | Object-specific initialization                         |
| **Order of Execution**   | 1st                                              | 2nd (per object)                                         | 3rd (per object)                                       |
| **Relation to main()**   | Executes before `main()` if class is loaded      | Executes when object is created                          | Executes when object is created                        |
| **Keyword Needed**       | `static` keyword                                 | None                                                     | None                                                   |
| **Use Case Example**     | Load configuration files, static constants       | Initialize instance variables shared by all constructors | Custom object initialization logic                     |
--------------------------- -------------------------------------------------- ---------------------------------------------------------- ---------------------------------------------------------

```
class Demo {
    static { System.out.println("Static block"); }
    { System.out.println("Instance block"); }
    Demo() { System.out.println("Constructor"); }
    public static void main(String[] args) {
        System.out.println("Main starts");
        new Demo();
        new Demo();
    }
}
```


# Compare IS-A vs HAS-A relationships in Java:

| Feature               | IS-A Relationship                                              | HAS-A Relationship                                                       |
| --------------------- | -------------------------------------------------------------- | ------------------------------------------------------------------------ |
| **Definition**        | Represents **inheritance**; “is a type of”                     | Represents **composition/aggregation**; “has a” or “contains a”          |
| **Implementation**    | Achieved using `extends` (class) or `implements` (interface)   | Achieved by including an object of one class as a field in another class |
| **Nature**            | **Tight coupling**                                             | **Looser coupling**                                                      |
| **Code Example**      | `class Car extends Vehicle { }` → Car **is a** Vehicle         | `class Car { Engine engine; }` → Car **has an** Engine                   |
| **Relationship Type** | Parent-child                                                   | Whole-part                                                               |
| **Access to Methods** | Can access parent class methods (depending on access modifier) | Can access methods via object reference                                  |
| **When to Use**       | When there is a **natural “is a” relationship**                | When one class **contains or uses another**                              |
------------------------ ---------------------------------------------------------------- ---------------------------------------------------------------------------


# Compare Arrays vs Collections in Java:
------------------------ ------------------------------------------ --------------------------------------
| Feature               | Arrays                                   | Collection                          |
| --------------------- | ---------------------------------------- | ----------------------------------- |
| **Size**              | Fixed                                    | Growable                            |
| **Data type**         | Homogeneous only                         | Homogeneous or Heterogeneous        |
| **Primitive support** | Supports both primitive and Object types | Supports only Object types          |
| **Memory management** | Poor                                     | Better                              |
| **Performance**       | Better if size is known in advance       | Less performant                     |
| **Methods**           | Limited predefined methods               | Large library of predefined methods |
------------------------ ------------------------------------------ --------------------------------------


# Compare Collection, List, Queue, and Set in Java:
------------------------- ------------------------ ---------------------------- ------------------------------ -----------------------------
| Feature               | Collection             | List                        | Queue                       | Set                         |
| --------------------- | ---------------------- | --------------------------- | --------------------------- | --------------------------- |
| **Type**              | Super interface        | Sub-interface of Collection | Sub-interface of Collection | Sub-interface of Collection |
| **Duplicates**        | Can store duplicates   | Can store duplicates        | Can store duplicates        | Cannot store duplicates     |
| **Order**             | No guaranteed order    | Maintains insertion order   | No guaranteed order         | No guaranteed order         |
| **Element Retrieval** | Forward direction only | Forward & backward          | Forward & backward          | Forward only                |
| **Adding Elements**   | Only at end            | Anywhere (index-based)      | At start or end             | Only at end                 |
| **Null Values**       | Can store null         | Can store null              | Cannot store null           | Only one null allowed       |
------------------------ ------------------------ ----------------------------- ----------------------------- ------------------------------


# Compare Comparable vs Comparator
------------------------------------ ------------------------------------------- ---------------------------------------------------
| Feature                           | Comparable                               | Comparator                                         |
| --------------------------------- | ---------------------------------------- | -------------------------------------------------- |
| **Sorting sequence**              | Single sorting sequence (e.g., id, name) | Multiple sorting sequences (e.g., id, name, price) |
| **Effect on original class**      | Modifies the original class              | Does not modify the original class                 |
| **Method used**                   | `compareTo()`                            | `compare()`                                        |
| **Package**                       | `java.lang`                              | `java.util`                                        |
| **Usage with Collections.sort()** | `Collections.sort(list)`                 | `Collections.sort(list, comparator)`               |
| **Purpose**                       | Defines natural ordering                 | Defines custom ordering                            |
------------------------------------ ------------------------------------------ -----------------------------------------------------

---------------------------- ----------------------------------------------------------------- -----------------------------------------------------------------
| **Feature**              | **`Stack` (`java.util.Stack`)**                                  | **Notes / Modern Alternative**                                  |
| ------------------------ | ---------------------------------------------------------------- | --------------------------------------------------------------- |
| **Type**                 | Class (extends `Vector`)                                         | Legacy class; part of Java Collections but extends old `Vector` |
| **Collection Framework** | Indirectly implements `List` / `Collection`                      | Not recommended for new code; use `Deque` instead               |
| **Data Structure**       | LIFO (Last-In-First-Out)                                         | Push/pop operations follow LIFO principle                       |
| **Duplicates Allowed**   | Yes                                                              | Can store repeated elements                                     |
| **Order Maintained**     | Yes, elements maintain insertion order (as in `Vector`)          | LIFO order enforced by push/pop                                 |
| **Null Values**          | Yes, can store `null`                                            | Same as `Vector`                                                |
| **Main Methods**         | `push(E item)`, `pop()`, `peek()`, `empty()`, `search(Object o)` | `push` adds to top, `pop` removes from top                      |
| **Thread Safety**        | Yes, because `Vector` methods are synchronized                   | Synchronization can cause overhead; `Deque` is faster           |
| **Modern Replacement**   | `ArrayDeque` (implements `Deque`)                                | Recommended for non-thread-safe stack operations                |
--------------------------- ------------------------------------------------------------------- -----------------------------------------------------------------

# Java COURRENT
----------------------------- ------------- -------------------------- ----------------------------------------
| Feature                    | Level      | Purpose                   | Notes                                 |
| -------------------------- | ---------- | ------------------------- | ------------------------------------- |
| `Thread`                   | Low-level  | Run code in a new thread  | Manual management                     |
| `Runnable`                 | Low-level  | Encapsulate task logic    | Pass to Thread/Executor               |
| `synchronized`             | Low-level  | Protect critical sections | Only one thread at a time             |
| `ExecutorService`          | High-level | Thread pool for tasks     | Efficient task execution              |
| `Future`                   | High-level | Retrieve async result     | Used with ExecutorService             |
| `CompletableFuture`        | High-level | Async composition         | Chain tasks, handle exceptions        |
| `ForkJoinPool`             | High-level | Parallel recursive tasks  | Divide-and-conquer                    |
| `Parallel Stream`          | High-level | Parallel data processing  | Simple syntax, leverages ForkJoinPool |
| `ScheduledExecutorService` | High-level | Delayed/periodic tasks    | Timer-like behavior                   |
------------------------------ ------------ -------------------------- ----------------------------------------


# Java Functional Interfaces Summary

| **Interface**           | **Method (Signature)** | **Input**                | **Output**             | **Purpose / Example Use**                                                                                       |
| ----------------------- | ---------------------- | ------------------------ | ---------------------- | --------------------------------------------------------------------------------------------------------------- |
| **Function<T, R>**      | `R apply(T t)`         | One argument (`T`)       | Returns a value (`R`)  | Transform a value → e.g., convert a String to its length:<br>`Function<String, Integer> len = s -> s.length();` |
| **Predicate<T>**        | `boolean test(T t)`    | One argument (`T`)       | Boolean (`true/false`) | Test a condition → e.g., check if a number is even:<br>`Predicate<Integer> isEven = n -> n % 2 == 0;`           |
| **Consumer<T>**         | `void accept(T t)`     | One argument (`T`)       | No return (void)       | Perform an action → e.g., print a value:<br>`Consumer<String> print = s -> System.out.println(s);`              |
| **Supplier<T>**         | `T get()`              | No input                 | Returns a value (`T`)  | Provide or generate data → e.g., return a random number:<br>`Supplier<Double> random = () -> Math.random();`    |
| **BiFunction<T, U, R>** | `R apply(T t, U u)`    | Two arguments (`T`, `U`) | Returns a value (`R`)  | Combine two inputs → e.g., sum two integers:<br>`BiFunction<Integer, Integer, Integer> add = (a, b) -> a + b;`  |


+--------------------------------------------------------+
|                 JVM Process (Java Virtual Machine)     |
|                                                        |
|   ┌─────────────────────────────────────────────────┐  |
|   │                Application Threads              │  |
|   │                                                 │  |
|   │   [Main Thread]   → runs your main() method      │  |
|   │   [Worker Thread] → (if you create Thread/Runnable)│
|   │   [Executor Threads] → (if you use thread pools) │  |
|   └─────────────────────────────────────────────────┘  |
|                                                        |
|   ┌─────────────────────────────────────────────────┐  |
|   │                JVM System Threads               │  |
|   │                                                 │  |
|   │   [Garbage Collector Thread]  → frees memory     │  |
|   │   [JIT Compiler Thread]       → optimizes code   │  |
|   │   [Finalizer Thread]          → calls finalize() │  |
|   │   [Reference Handler Thread]  → manages Weak/Soft|
|   │   [Signal Dispatcher Thread]  → handles OS signals│
|   │   [Attach Listener Thread]    → debugger/profiler │
|   │   [Common-Cleaner Thread]     → clean up resources│
|   └─────────────────────────────────────────────────┘  |
|                                                        |
+--------------------------------------------------------+




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