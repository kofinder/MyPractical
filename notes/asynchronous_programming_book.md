## Parallel Programming Paradigms
  > Parallel programming is a computing technique. Its allows multiple tasks or computations to run simultaneously, splitting work across processors, cores, or threads to solve problems faster than sequential execution.

# FOUNDATION
- process : Process is a memory container, live on Memory, Not run CPU, By itself, a process does nothing
- thread : Threads are the execution units, AKA execution path. Scheduled by the OS. Run on the CPU core.
- Synchronous Execution: Tasks are executed one after another in a defined order. Each task waits for the previous task to finish before starting (blocking behavior).

- Asynchronous Execution: Tasks can start and continue running without waiting for other tasks to finish. Tasks may overlap in time, run in parallel, or be scheduled to complete later (non-blocking behavior).

> **Note:** Synchronization is not an execution model. It refers to coordination mechanisms (locks, mutexes, semaphores, barriers) used to ensure correctness when tasks execute concurrently.

### 1. Data Parallelism
- **Definition:** Same operation applied concurrently on elements of a dataset.
- **Example:** Vector addition, matrix multiplication.
- **Key point:** Distributes data across multiple processors.

### 2. Task Parallelism
- **Definition:** Different tasks (functions) run in parallel, possibly on the same or different data.
- **Example:** One thread handles I/O while another processes data.
- **Key point:** Ideal for independent tasks with minimal dependencies.

### 3. Stream Parallelism
- **Definition:** Parallelism applied to a sequence of operations on streams of data.
- **Example:** Video processing where each frame goes through a pipeline of filters.
- **Key point:** Works well for continuous data streams.

### 4. Implicit Parallelism
- **Definition:** Compiler/runtime automatically detects and exploits parallelism.
- **Example:** OpenMP `#pragma omp parallel for`.
- **Key point:** Programmer doesn’t manually manage threads; easier but less control.

---

## Parallel Programming Models

### 1. Phase Parallel
- Program divided into phases executed in parallel.
- **Example:** MapReduce (map phase, reduce phase).

### 2. Divide and Conquer
- Problem recursively divided into subproblems solved in parallel.
- **Example:** Parallel quicksort, mergesort.

### 3. Pipeline
- Computation divided into stages; each stage processes data and passes it along.
- **Example:** CPU instruction pipelines.

### 4. Master-Slave
- Master assigns tasks to slave nodes; collects results.
- **Example:** Distributed computation, rendering tasks.

### 5. Work Pool
- Tasks placed in a shared pool; idle processors fetch tasks dynamically.
- **Example:** Thread pool in Java, OpenMP task scheduling.

---

## Concurrency Programming Concepts

### 1. Context Switching
- CPU switches from one thread/process to another.
- **Key point:** Introduces overhead but enables multitasking.

### 2. Preemptive Multitasking
- OS interrupts a running task to schedule another.
- **Example:** Modern OS (Windows, Linux).

### 3. Non-Preemptive Multitasking
- Task yields control voluntarily.
- **Example:** Early Mac OS (cooperative multitasking).

---

## Parallel Programming Types

### 1. Shared-Memory Parallelism
- Multiple threads/processors share the same memory space.
- **Example:** OpenMP on multicore CPUs.
- **Key point:** Synchronization required (locks, semaphores).

### 2. Message-Passing Parallelism
- Processors communicate via messages, no shared memory.
- **Example:** MPI (Message Passing Interface).
- **Key point:** Suitable for distributed systems.

---

## Multithreading Programming
- Multiple threads execute within a single process.
- **Key concepts:** Thread creation, synchronization (mutex, semaphore), deadlocks.
- **Example:** Web server handling multiple requests concurrently.

---

## Event-Driven Programming
- Program flow driven by events (user input, messages, timers).
- **Example:** GUI apps, Node.js.
- **Key point:** Avoids blocking by responding to events asynchronously.

---

## Reactive Programming
- Program reacts to data changes or events.
- **Key concepts:**
  - **Backpressure:** Control data flow to prevent overwhelming consumer.
  - **Pull-based / Push-based:** Data requested by consumer (pull) or pushed by producer (push).
- **Example:** RxJava, Reactive Streams.

---

## Dataflow Programming
- Computation represented as a graph of operations; data flows along edges.
- **Example:** TensorFlow, Apache NiFi.

---

## Incremental Computing
- Recompute only affected parts when input changes.
- **Example:** Spreadsheet recalculation, build systems like `make`.

---

## Metrics in Parallel & Concurrent Programming
- **Speedup:** `Time(serial) / Time(parallel)`
- **Efficiency:** `Speedup / #Processors`
- **Scalability:** How well performance improves with more resources.
- **Latency vs Throughput:** Latency = delay per task; Throughput = tasks per unit time.

---


# ⚙️ Processes, Threads, and Services

## 🧩 Processes in Linux
- **Lifecycle:**  
  1. Creation (`fork()`, `exec()`)  
  2. Execution  
  3. Termination (`exit()`)

- **Identifiers:**  
  - **PID:** Unique Process ID.  
  - **PPID:** Parent Process ID.

- **Remote Procedure Calls (RPCs):**  
  → Allow processes to execute procedures on remote systems.

---

## 🔗 Inter-Process Communication (IPC) Mechanisms

| Mechanism | Description |
|------------|-------------|
| **Pipes / Named Pipes (FIFOs)** | Unidirectional communication between related processes. |
| **Signals** | Notify processes of system or user events. |
| **Message Queues** | Exchange structured messages asynchronously. |
| **Semaphores** | Synchronize access to shared resources. |
| **Shared Memory** | Fastest IPC — direct memory sharing between processes. |
| **Sockets** | Network-based IPC, allows communication between machines. |

### ✅ IPC Key Qualities
- **Reliability:** Messages and synchronization remain consistent.  
- **Scalability:** Efficient across many processes or nodes.  
- **Flexibility:** Supports various communication models (local/remote).  
- **Use Case:** Choose based on data size, speed, and communication pattern.

---

## 🧵 Threads in Concurrency

- **Thread Lifecycle:**  
  1. **Creation** → Thread is started.  
  2. **Execution** → Performs assigned task.  
  3. **Synchronization** → Coordinates with other threads.  
  4. **Termination** → Ends and releases resources.

---

## 🔒 Synchronization Primitives

| Primitive                     |               Purpose                             |
|-------------------------------|---------------------------------------------------|
| **Mutex (Mutual Exclusion):** | Locks a critical section to one thread at a time. |
| **Semaphore:**                | Controls access count to shared resources.        |
| **Condition Variable:**       | Allows threads to wait for specific conditions.   |


### Additional Primitives:
- **Barriers:** All threads wait until each reaches a certain point.  
- **Read–Write Locks:** Multiple readers or one writer at a time.  
- **Spin Locks:** Busy-wait locks for short critical sections.

---


# ⚠️ Common Problems in Multithreading

| Problem | Description |
|----------|--------------|
| **Race Condition** | Two or more threads access shared data simultaneously, causing unpredictable results. |
| **Deadlock** | Two or more threads wait on each other indefinitely for resources. |
| **Starvation** | A thread never gets CPU time or access to resources due to unfair scheduling. |
| **Livelock** | Threads keep reacting to each other and make no progress. |

---

# 🧰 Techniques for Managing Thread Challenges

1. **Synchronization Mechanisms:**  
   Use mutexes, semaphores, and condition variables to protect shared resources.

2. **Deadlock Prevention & Detection:**  
   - Follow lock ordering.  
   - Use timeouts to detect stalled threads.  
   - Apply algorithms like wait-for graphs.

3. **Thread Scheduling:**  
   Ensure fair CPU allocation to prevent starvation.

---

# 🚀 Strategies for Effective Thread Management

- **Minimize Shared State:**  
  Reduce dependency between threads to avoid conflicts.

- **Lock Hierarchy:**  
  Always acquire locks in a consistent global order.

- **Timeouts:**  
  Avoid indefinite waiting when acquiring locks.

- **Thread Pools:**  
  Reuse threads for better performance and resource management.

- **Synchronization Primitives:**  
  Use appropriate locking tools for thread safety.

- **Testing & Debugging:**  
  Use tools like thread sanitizers or debuggers to detect race conditions and deadlocks.

- **Scalability & Performance Considerations:**  
  Balance between concurrency and system overhead.

- **Communication & Collaboration:**  
  Use message passing, queues, or events for clean inter-thread communication.

---

| Feature                            | `std::thread` | `std::jthread`             |
| ---------------------------------- | ------------- | -------------------------- |
| Introduced in                      | C++11         | C++20                      |
| Must manually join/detach          | ✅ Yes         | ❌ No (joins automatically) |
| Auto-join on destruction           | ❌             | ✅                          |
| Supports stop request/cancellation | ❌             | ✅ (via `stop_token`)       |
| Moveable                           | ✅             | ✅                          |
| Copyable                           | ❌             | ❌                          |

---

# Thread Synchronization with Locks
* Race conditions – what they are and how they can happen
* Data race-free mechanism: Only one person can write at a time, or each has their own notebook → safe and consistent results.
* Mutual exclusion as a synchronization mechanism and how it is implemented in C++ by std::mutex
* Generic lock management
* What condition variables are and how to use them with mutexes
* Implementing a fully synchronized queue using std::mutex and std::condition_ variable
* The new synchronization primitives introduced with C++20 – semaphores, barriers, and latches


# Resource Contention in Multithreading

## Definition
- **Resource contention** occurs when **two or more threads or processes compete for the same limited resource** at the same time.
- Resources can include:
  - CPU
  - Memory
  - Disk
  - Network
  - Shared data structures (variables, files, I/O devices)

---

## Why It Happens
- Multiple threads need access to the same resource simultaneously.
- Only one thread can safely use the resource at a time.
- Without proper management, contention can cause:
  - **Performance degradation**
  - **Deadlocks**
  - **Data races**
  - **Starvation**

# Consequences of Resource Contention
- Performance loss: Threads spend time waiting for resources.
- Deadlocks: Threads wait indefinitely for resources held by each other.
- Starvation: Some threads never get access to resources.
- Reduced throughput: Overall program runs slower due to waiting.---

✅ **Summary**
- Processes → Independent, isolated memory.  
- Threads → Lightweight, shared memory.  
- IPC → Connects processes.  
- Synchronization → Coordinates threads safely.  
- Metrics → Measure and improve parallel performance.  
- Thread Management → Prevent race conditions, deadlocks, and inefficiency.

✅ **Summary**
- std::this_thread::sleep_for(1s) is used to simulate a task taking time and show concurrency clearly.
- It is not required for std::jthread or RAII; it’s purely illustrative.


✅ **Summary**
* Data race: simultaneous unsynchronized access with at least one write → undefined behavior.
* Data race-free mechanism: ensures safe access to shared data → prevents undefined behavior.
*C++ tools: mutexes, locks, atomics, condition variables, RAII threads.

✅ **Summary**
* std::this_thread::yield() → voluntarily gives up CPU without terminating.
* Useful for fair scheduling, avoiding busy-waiting, and cooperative multitasking.
* Often replaced by condition variables or proper synchronization in production code.
---

# Yielding Thread Execution in C++

## Definition
- **Yielding**: A thread voluntarily gives up its current CPU time slice to allow other threads to run.
- The thread **does not terminate**; it can resume later when the scheduler picks it.

---

## 🧩 How to Yield in C++

### 📘 Definition
- **`std::this_thread::yield()`**: A function that **suggests to the OS scheduler** that the current thread is willing to **pause execution** and let other threads run.

### 🧠 Key Points
- It’s a **non-blocking hint**, not a guarantee — the scheduler may or may not switch threads.
- Useful to **improve fairness** when multiple threads are competing for CPU.
- Helps avoid **busy-wait loops** consuming 100% CPU.

### ✅ Syntax
```cpp
#include <thread>
std::this_thread::yield();
```

### 📍 Use Cases
- Inside **spinlocks** or **polling loops**.
- When waiting for a condition that’s likely to change soon.
- When a thread performs background or low-priority tasks.

---

## 1️⃣ What is Thread Cancellation?

### 📘 Definition
- **Thread cancellation** means **stopping a thread before it finishes** its execution naturally.
- **C++ does not provide safe, forceful thread termination**.
- Instead, **cooperative cancellation** is used — threads periodically check a signal (flag) and **exit gracefully** when requested.

---

## 2️⃣ Cooperative Cancellation Mechanism

### ⚙️ How It Works
- Use a **shared atomic flag** (e.g., `std::atomic_bool`) to indicate whether the thread should continue running.
- The thread periodically checks this flag within its main loop.
- When the flag is set to `false`, the thread completes any pending work and exits cleanly.

### ✅ Example
```cpp
#include <atomic>
#include <thread>

std::atomic_bool running{true};

std::jthread worker([&]() {
    while (running.load()) {
        // Perform work
        std::this_thread::yield(); // optional: prevent busy waiting
    }
});

// Request cancellation
running.store(false);
```

### 🧠 Notes
- Use **`std::jthread` (C++20)** when possible — it supports **automatic joining** and **cancellation tokens**.
- Avoid `std::terminate()` or `pthread_cancel()` equivalents — they can cause **resource leaks** or **undefined behavior**.

---

# 🧵 Thread-Local Storage (TLS) — C++ Interview Notes

## 🔹 Definition
- Each thread has its **own independent instance** of a variable.
- Declared using the **`thread_local`** keyword (**C++11**).
- Behaves like a global or static variable, but **isolated per thread**.

---

## 🔹 Purpose / Why Use
- Store **thread-specific data** that should not be shared.
- Avoid **synchronization primitives** (mutexes, locks).
- Maintain **thread-specific state** such as logs, buffers, or temporary data.

---

## 🔹 Characteristics

| Property | Description |
|-----------|--------------|
| **Keyword** | `thread_local` |
| **Scope** | Thread |
| **Lifetime** | Created on first use by a thread; destroyed when the thread exits |
| **Sharing** | Not shared across threads |
| **Synchronization** | Not required |
| **Introduced In** | C++11 |

---

## 🔹 Where It Can Be Used
- **Global / namespace scope**  
- **Static class members**  
- **Function-local static variables**

---

## 🔹 Advantages
- **Thread-safe by design** — no locks needed.
- **High performance** for thread-specific data.
- Simplifies design of **multi-threaded systems**.

---

## 🔹 Limitations
- **Higher memory usage** (one instance per thread).
- **Initialization order** across translation units is unspecified.
- **Not suitable** for shared data between threads.

---

## 🔹 Common Use Cases
- Thread-specific loggers.
- Per-thread random number generators.
- Thread-local caches or buffers.
- Thread-specific error or status tracking.

---

## 🧩 Quick Recall

> **Keyword:** `thread_local`  
> **Purpose:** Per-thread variable instance  
> **Lifetime:** Until thread exits  
> **Benefit:** No synchronization required, safe concurrent access  

---

# 🧭 Summary

| Concept | Purpose | Key Feature | Introduced |
|----------|----------|--------------|-------------|
| **`std::this_thread::yield()`** | Yield CPU to other threads | Non-blocking scheduler hint | C++11 |
| **Thread Cancellation** | Gracefully stop a thread | Cooperative flag-based mechanism | C++11+ |
| **Thread-Local Storage** | Per-thread variable instances | `thread_local` keyword | C++11 |


----


## CH3: Thread Synchronization with Locks

Concurrent memory write operations to the same memory address from multiple threads require synchronization mechanisms to prevent data races and ensure data integrity. Atomic operations are typically implemented using hardware instructions that are indivisible.

### 🔹 Mutual Exclusion
Mutual exclusion ensures that multiple threads or processes do not simultaneously access a shared resource such as a variable, critical section, file, or network connection. It is crucial for preventing race conditions.

| Mutex Type                  | Access Type  | Recursive | Timeout |
|------------------------------|-------------|-----------|--------|
| std::mutex                  | EXCLUSIVE   | NO        | NO     |
| std::recursive_mutex        | EXCLUSIVE   | YES       | NO     |
| std::shared_mutex           | EXCLUSIVE (1 writer) / SHARED (N readers) | NO | NO |
| std::timed_mutex            | EXCLUSIVE   | NO        | YES    |
| std::recursive_timed_mutex  | EXCLUSIVE   | YES       | YES    |
| std::shared_timed_mutex     | EXCLUSIVE (1 writer) / SHARED (N readers) | NO | YES |

---

### std::mutex
The `std::mutex` class is a synchronization primitive used to protect shared data from simultaneous access by multiple threads. Key features:
- Exclusive, non-recursive ownership semantics.
- A thread owns the mutex from `lock()` or `try_lock()` until `unlock()` is called.
- Non-recursive: a thread cannot re-lock a mutex it already owns; doing so is undefined behavior.
- Exclusive: if a thread owns a mutex, other threads are blocked or `try_lock()` returns false.

**Methods:**
- `lock()`: Blocks until mutex is acquired.
- `try_lock()`: Non-blocking attempt to acquire the mutex.
- `unlock()`: Releases the mutex.

---

### std::recursive_mutex
Allows a thread to acquire the same mutex multiple times (recursive acquisition). Key points:
- Ownership count must be released the same number of times.
- Maximum recursive acquisitions are implementation-defined.
- Interface is identical to `std::mutex`.

---

### std::shared_mutex
Supports multiple access levels for readers-writer scenarios:
- **Shared access**: Multiple threads can acquire shared ownership concurrently (readers).
- **Exclusive access**: Only one thread can acquire exclusive ownership (writer).
- Methods: `lock()`, `try_lock()`, `unlock()` for exclusive access, and `lock_shared()`, `try_lock_shared()`, `unlock_shared()` for shared access.
- Useful when many threads read data and only one thread writes.

---


### Timed Mutex Types
Timed mutexes allow a thread to attempt acquiring a lock for a limited period of time.
- `std::timed_mutex`, `std::recursive_timed_mutex`, `std::shared_timed_mutex` are similar to their non-timed counterparts but provide additional methods:
  - `try_lock_for(duration)`: Tries to lock the mutex, blocking up to the specified duration. Returns true if successful, false if timeout occurs.
  - `try_lock_until(time_point)`: Tries to lock the mutex until the specified point in time or until the mutex is locked.
- These are useful when a thread should not be blocked indefinitely waiting for a lock.

---


### Problems When Using Locks
When using a single mutex properly, writing correct multithreaded code is relatively straightforward. However, when multiple locks are required, code complexity increases significantly. Two common problems when using multiple locks are:
- **Deadlock**: Occurs when two or more threads are waiting indefinitely for each other to release locks.
- **Livelock**: Occurs when threads continuously change state in response to each other without making progress.
----


### Generic Lock Management
C++ provides wrapper classes to simplify mutex usage and ensure safe acquisition and release using RAII principles. Key classes:

| Lock Manager Class | Supported Mutex Types | Mutexes Managed |
|------------------|--------------------|----------------|
| std::lock_guard   | All                | 1              |
| std::scoped_lock  | All                | Zero or more   |
| std::unique_lock  | All                | 1              |
| std::shared_lock  | std::shared_mutex, std::shared_timed_mutex | 1 |

#### std::lock_guard
- RAII wrapper that automatically locks the mutex on construction and unlocks on destruction.
- Simplifies exception-safe locking.

#### std::unique_lock
- Provides more flexibility than `std::lock_guard`.
- Supports deferred locking (`std::defer_lock`), adoption of an already-locked mutex (`std::adopt_lock`), and try-locking (`std::try_to_lock`).
- Allows explicit `lock()` and `unlock()` calls.

#### std::scoped_lock
- RAII wrapper that can manage zero or more mutexes.
- Locks multiple mutexes in the order they are provided to prevent deadlocks.

#### std::shared_lock
- Used with `std::shared_mutex` and `std::shared_timed_mutex`.
- Acquires and releases locks in shared mode (multiple readers).
- Supports deferred locking and lock ownership transfer.

---

### Condition Variables
Condition variables allow threads to communicate and wait for notifications. They are always associated with a mutex and enable efficient waiting until a certain condition is met.

---


### Implementing a Multithreaded Safe Queue
A multithread-safe queue allows multiple producer and consumer threads to add and remove elements concurrently.
- **Single-producer-single-consumer (SPSC)** queues are simpler to synchronize.
- A fixed-size queue can be implemented as a template class using `std::vector<T>`.
- Ensures packets or data items are processed in order, even with multiple threads.

---

### Semaphores
C++20 introduces semaphores as new synchronization primitives:
- **Binary semaphore**: Two states (0 and 1), can implement mutual exclusion. Unlike mutexes, any thread can signal the semaphore.
- **Counting semaphore**: Counter >1, controls access to multiple instances of a shared resource.
- Useful for signaling rather than exclusive locking.

---

### Barriers and Latches
C++20 introduces **barriers** and **latches** to coordinate threads:

#### std::latch
- Allows threads to wait until a specific number of operations are completed.
- Single-use; cannot be reset.

#### std::barrier
- Synchronizes a group of threads at a specific point.
- Reusable; resets after all threads reach the barrier.
- Use `std::latch` for one-time synchronization points and `std::barrier` for repeated phased synchronization.