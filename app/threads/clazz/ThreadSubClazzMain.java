package threads.clazz;

// ==========================
// 1. Simple Thread using Thread class
// Reason: Demonstrates how to create a basic thread.
// Summary: Starts a new thread and prints a message.
class ThreadSubClazzExample1 {
    public static void run() {
        Thread t = new Thread() {
            public void run() {
                System.out.println("Hello from Thread 1");
            }
        };
        t.start();
    }
}

// ==========================
// 2. Thread using Runnable interface
// Reason: Runnable separates task logic from thread.
// Summary: Runnable passed to Thread, prints a message.
class RunnableSubClazzExample2 {
    public static void run() {
        Runnable task = () -> System.out.println("Hello from Runnable");
        new Thread(task).start();
    }
}

// ==========================
// 3. Multiple threads running
// Reason: Demonstrates concurrent execution of multiple threads.
// Summary: Three threads print messages simultaneously.
class ThreadSubClazzExample3 {
    public static void run() {
        for (int i = 1; i <= 3; i++) {
            int id = i;
            new Thread(() -> System.out.println("Thread " + id + " running")).start();
        }
    }
}

// ==========================
// 4. Thread with sleep
// Reason: Demonstrates pausing thread execution.
// Summary: Thread sleeps for 1 second before printing message.
class ThreadSubClazzExample4 {
    public static void run() throws InterruptedException {
        Thread t = new Thread(() -> {
            try {
                Thread.sleep(1000);
                System.out.println("Thread finished after 1 second");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        t.start();
        t.join(); // Wait for thread to finish
        System.out.println("Main thread finished");
    }
}

// ==========================
// 5. Thread with shared Runnable
// Reason: Demonstrates using a single Runnable for multiple threads.
// Summary: Two threads execute the same task concurrently.
class RunnableSubClazzExample5 {
    public static void run() {
        Runnable task = () -> System.out.println("Shared task running by " + Thread.currentThread().getName());
        new Thread(task, "Thread-A").start();
        new Thread(task, "Thread-B").start();
    }
}

// ==========================
// 6. Thread with anonymous class
// Reason: Shows classic anonymous Runnable usage.
// Summary: Runnable implemented as anonymous inner class.
class ThreadSubClazzExample6 {
    public static void run() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Anonymous Runnable thread running");
            }
        }).start();
    }
}

// ==========================
// 7. Thread with loop inside
// Reason: Demonstrates iterative work in a thread.
// Summary: Thread loops and prints numbers 1-5.
class ThreadSubClazzExample7 {
    public static void run() {
        new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                System.out.println("Loop: " + i);
            }
        }).start();
    }
}

// ==========================
// 8. Two threads printing alternately
// Reason: Demonstrates multiple threads executing distinct tasks.
// Summary: Two threads print different messages concurrently.
class ThreadSubClazzExample8 {
    public static void run() {
        Runnable printA = () -> System.out.println("A");
        Runnable printB = () -> System.out.println("B");
        new Thread(printA).start();
        new Thread(printB).start();
    }
}

// ==========================
// 9. Thread name usage
// Reason: Shows how to name threads for identification.
// Summary: Thread prints its custom name.
class ThreadSubClazzExample9 {
    public static void run() {
        Thread t = new Thread(() -> System.out.println("Thread name: " + Thread.currentThread().getName()));
        t.setName("MyThread");
        t.start();
    }
}

// ==========================
// 10. Thread priority
// Reason: Demonstrates setting thread execution priority.
// Summary: Two threads with different priorities print messages.
class ThreadSubClazzExample10 {
    public static void run() {
        Thread t1 = new Thread(() -> System.out.println("Low priority"));
        Thread t2 = new Thread(() -> System.out.println("High priority"));
        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.MAX_PRIORITY);
        t1.start();
        t2.start();
    }
}

// ==========================
// 11. Thread join example
// Reason: Shows how main thread waits for child thread.
// Summary: Child thread sleeps, then main resumes after join.
class ThreadSubClazzExample11 {
    public static void run() throws InterruptedException {
        Thread t = new Thread(() -> {
            try {
                Thread.sleep(500);
                System.out.println("Child thread finished");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        t.start();
        t.join();
        System.out.println("Main thread resumes");
    }
}

// ==========================
// 12. Runnable with parameters
// Reason: Shows how to pass data to Runnable.
// Summary: Runnable prints custom message including thread name.
class RunnableSubClazzExample12 {
    public static void run() {
        Runnable task = createTask("Hello Runnable");
        new Thread(task).start();
    }

    static Runnable createTask(String message) {
        return () -> System.out.println(message + " executed by " + Thread.currentThread().getName());
    }
}

// ==========================
// 13. Thread sleeping in loop
// Reason: Demonstrates repeated work with delays.
// Summary: Thread prints count 1-3 with half-second pauses.
class ThreadSubClazzExample13 {
    public static void run() {
        new Thread(() -> {
            for (int i = 1; i <= 3; i++) {
                System.out.println("Count: " + i);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }
}

// ==========================
// 14. Thread interrupt
// Reason: Shows how to interrupt a sleeping thread.
// Summary: Thread is interrupted before completion.
class ThreadSubClazzExample14 {
    public static void run() throws InterruptedException {
        Thread t = new Thread(() -> {
            try {
                Thread.sleep(2000);
                System.out.println("Finished normally");
            } catch (InterruptedException e) {
                System.out.println("Thread was interrupted!");
            }
        });
        t.start();
        Thread.sleep(500);
        t.interrupt();
    }
}

// ==========================
// 15. Daemon thread
// Reason: Demonstrates background thread that ends with main.
// Summary: Daemon thread runs infinitely until main thread exits.
class ThreadSubClazzExample15 {
    public static void run() {
        Thread t = new Thread(() -> {
            while (true)
                System.out.println("Daemon thread running...");
        });
        t.setDaemon(true);
        t.start();
        System.out.println("Main thread exits");
    }
}

// ==========================
// 16. Multiple Runnable tasks
// Reason: Demonstrates running multiple independent tasks concurrently.
// Summary: Two Runnable tasks executed by separate threads.
class RunnableSubClazzExample16 {
    public static void run() {
        Runnable task1 = () -> System.out.println("Task 1");
        Runnable task2 = () -> System.out.println("Task 2");
        new Thread(task1).start();
        new Thread(task2).start();
    }
}

// ==========================
// 17. Runnable with shared counter (not synchronized)
// Reason: Demonstrates race condition with shared resource.
// Summary: Counter may produce inconsistent results.
class RunnableSubClazzExample17 {
    static int counter = 0;

    public static void run() {
        Runnable task = () -> {
            for (int i = 0; i < 5; i++)
                counter++;
            System.out.println("Counter: " + counter);
        };
        new Thread(task).start();
        new Thread(task).start();
    }
}

// ==========================
// 18. Runnable with shared counter (synchronized)
// Reason: Shows how to safely update shared resource.
// Summary: Counter updates correctly due to synchronized method.
class RunnableSubClazzExample18 {
    static int counter = 0;

    public static void run() {
        Runnable task = () -> {
            for (int i = 0; i < 5; i++)
                increment();
            System.out.println("Counter: " + counter);
        };
        new Thread(task).start();
        new Thread(task).start();
    }

    static synchronized void increment() {
        counter++;
    }
}

// ==========================
// 19. Thread yield
// Reason: Demonstrates suggesting thread scheduler to switch threads.
// Summary: Threads yield control between executions.
class ThreadSubClazzExample19 {
    public static void run() {
        Runnable task = () -> {
            for (int i = 1; i <= 3; i++) {
                System.out.println(Thread.currentThread().getName() + " running " + i);
                Thread.yield();
            }
        };
        new Thread(task, "T1").start();
        new Thread(task, "T2").start();
    }
}

// ==========================
// 20. Thread sleep with exception handling
// Reason: Shows safe handling of InterruptedException.
// Summary: Thread sleeps for 1 second, prints messages.
class ThreadSubClazzExample20 {
    public static void run() {
        new Thread(() -> {
            try {
                System.out.println("Thread sleeping...");
                Thread.sleep(1000);
                System.out.println("Thread woke up");
            } catch (InterruptedException e) {
                System.out.println("Interrupted!");
            }
        }).start();
    }
}
