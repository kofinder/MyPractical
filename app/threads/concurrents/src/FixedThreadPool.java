package threads.concurrents.src;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FixedThreadPool {
    // Demonstrates creating a fixed thread pool and submitting a task
    public static void run() {
        ExecutorService executor = Executors.newFixedThreadPool(2);
        executor.submit(() -> System.out.println("Task executed in fixed thread pool"));
        executor.shutdown();
    }

}
