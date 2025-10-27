## Parallel Programming Paradigms

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

# Processes, Threads, and Services




