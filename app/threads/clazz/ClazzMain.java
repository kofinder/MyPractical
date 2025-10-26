package threads.clazz;

// ==========================
// 1. Basic Thread by extending Thread
// Reason: Demonstrate creating a thread using extends.
// Summary: Prints a message from a new thread.
class ThreadExample1 extends Thread {
    public void run() {
        System.out.println("ThreadExample1 running");
    }
}

// ==========================
// 2. Basic Runnable implementation
// Reason: Demonstrate creating a thread using Runnable.
// Summary: Runnable task executed by a thread.
class RunnableExample2 implements Runnable {
    public void run() {
        System.out.println("RunnableExample2 running");
    }
}

// ==========================
// 3. Multiple threads extending Thread
// Reason: Show concurrent execution of multiple Thread instances.
// Summary: Three threads print messages simultaneously.
class ThreadExample3 extends Thread {
    private int id;

    ThreadExample3(int id) {
        this.id = id;
    }

    public void run() {
        System.out.println("ThreadExample3 id=" + id);
    }
}

// ==========================
// 4. Multiple Runnable instances
// Reason: Run multiple tasks using Runnable.
// Summary: Two Runnable objects executed by separate threads.
class RunnableExample4 implements Runnable {
    private String name;

    RunnableExample4(String name) {
        this.name = name;
    }

    public void run() {
        System.out.println("RunnableExample4 name=" + name);
    }
}

// ==========================
// 5. Thread with loop
// Reason: Demonstrate iterative work in a thread.
// Summary: Thread prints numbers 1-5.
class ThreadExample5 extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++)
            System.out.println("ThreadExample5: " + i);
    }
}

// ==========================
// 6. Runnable with loop
// Reason: Runnable performing repeated work.
// Summary: Prints numbers 1-5 from Runnable task.
class RunnableExample6 implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++)
            System.out.println("RunnableExample6: " + i);
    }
}

// ==========================
// 7. Thread sleep example
// Reason: Demonstrate pausing thread execution.
// Summary: Thread sleeps 1 second before printing message.
class ThreadExample7 extends Thread {
    public void run() {
        try {
            Thread.sleep(1000);
            System.out.println("ThreadExample7 finished sleeping");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

// ==========================
// 8. Runnable sleep example
// Reason: Runnable can also sleep inside run().
// Summary: Runnable sleeps and prints message.
class RunnableExample8 implements Runnable {
    public void run() {
        try {
            Thread.sleep(500);
            System.out.println("RunnableExample8 finished sleeping");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

// ==========================
// 9. Thread with parameters
// Reason: Pass data to thread via constructor.
// Summary: Thread prints parameter value.
class ThreadExample9 extends Thread {
    private String message;

    ThreadExample9(String message) {
        this.message = message;
    }

    public void run() {
        System.out.println("ThreadExample9: " + message);
    }
}

// ==========================
// 10. Runnable with parameters
// Reason: Runnable can accept parameters through constructor.
// Summary: Runnable prints passed parameter.
class RunnableExample10 implements Runnable {
    private int value;

    RunnableExample10(int value) {
        this.value = value;
    }

    public void run() {
        System.out.println("RunnableExample10 value: " + value);
    }
}

// ==========================
// 11. Thread with join
// Reason: Show main thread waiting for child thread.
// Summary: Child thread prints first, main resumes after join.
class ThreadExample11 extends Thread {
    public void run() {
        System.out.println("ThreadExample11 running");
    }
}

// ==========================
// 12. Runnable with join
// Reason: Runnable executed by Thread, main waits using join.
// Summary: Main thread waits for Runnable to finish.
class RunnableExample12 implements Runnable {
    public void run() {
        System.out.println("RunnableExample12 running");
    }
}

// ==========================
// 13. Thread interrupt
// Reason: Demonstrate interrupting a thread.
// Summary: Thread detects interruption and prints message.
class ThreadExample13 extends Thread {
    public void run() {
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            System.out.println("ThreadExample13 interrupted");
        }
    }
}

// ==========================
// 14. Runnable interrupt
// Reason: Runnable executed by Thread can also be interrupted.
// Summary: Runnable checks for interrupt exception.
class RunnableExample14 implements Runnable {
    public void run() {
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            System.out.println("RunnableExample14 interrupted");
        }
    }
}

// ==========================
// 15. Thread daemon
// Reason: Background thread stops when main exits.
// Summary: Daemon thread runs infinitely until main exits.
class ThreadExample15 extends Thread {
    public void run() {
        while (true)
            System.out.println("ThreadExample15 daemon running");
    }
}

// ==========================
// 16. Runnable daemon
// Reason: Runnable executed by daemon thread runs in background.
// Summary: Prints message repeatedly until main exits.
class RunnableExample16 implements Runnable {
    public void run() {
        while (true)
            System.out.println("RunnableExample16 daemon running");
    }
}

// ==========================
// 17. Shared counter Thread (race condition)
// Reason: Demonstrates unsynchronized shared resource.
// Summary: Counter may produce inconsistent results.
class ThreadExample17 extends Thread {
    static int counter = 0;

    public void run() {
        for (int i = 0; i < 5; i++)
            counter++;
        System.out.println("ThreadExample17 counter: " + counter);
    }
}

// ==========================
// 18. Shared counter Runnable (synchronized)
// Reason: Demonstrates synchronized access to shared resource.
// Summary: Counter updates safely.
class RunnableExample18 implements Runnable {
    static int counter = 0;

    public void run() {
        for (int i = 0; i < 5; i++)
            increment();
        System.out.println("RunnableExample18 counter: " + counter);
    }

    synchronized void increment() {
        counter++;
    }
}

// ==========================
// 19. Thread yielding
// Reason: Suggest thread scheduler to switch threads.
// Summary: Threads yield between executions.
class ThreadExample19 extends Thread {
    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println("ThreadExample19 " + Thread.currentThread().getName() + " " + i);
            Thread.yield();
        }
    }
}

// ==========================
// 20. Runnable yielding
// Reason: Runnable can yield in its execution loop.
// Summary: Yield helps other threads to run.
class RunnableExample20 implements Runnable {
    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println("RunnableExample20 " + Thread.currentThread().getName() + " " + i);
            Thread.yield();
        }
    }
}
