## Parallel Programming Paradigms
  > Parallel programming is a computing technique. Its allows multiple tasks or computations to run simultaneously, splitting work across processors, cores, or threads to solve problems faster than sequential execution.

## Execution Models
  - **Synchronization:** Tasks are executed one after another, in sequence. Each task waits for the previous one to finish.
  - **Asynchronous:**  Tasks can start and continue running while others are still executing. Tasks don’t wait — they can run in parallel or be scheduled to finish later.

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

## How to Yield in C++

```cpp
#include <thread>
std::this_thread::yield(); // hint to the scheduler


## 1️⃣ What is Thread Cancellation?

- **Thread cancellation**: Stopping a thread before it naturally finishes its task.
- **Important:** In C++, you **cannot forcefully terminate a thread safely**.
- Instead, **cooperative cancellation** is used: threads check a **signal/flag** and exit gracefully.

---

## 2️⃣ Cooperative Cancellation Mechanism

- **Flag-based approach:**
  - Use an `std::atomic_bool` or a similar shared variable.
  - Thread periodically checks this flag.
  - If the flag indicates stop, the thread exits after completing its current work.

```cpp
std::atomic_bool running{true};

std::jthread t([&]() {
    while (running.load()) {
        // Do work here
    }
});

running.store(false); // Signal the thread to stop
