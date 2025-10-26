package threads.concurrents.src;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CachedThreadPool {
    // Demonstrates cached thread pool that grows dynamically
    public static void run() {
        ExecutorService executor = Executors.newCachedThreadPool();
        executor.submit(() -> System.out.println("Task executed in cached thread pool"));
        executor.shutdown();
    }

}
