package threads.concurrents.src;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class ScheduledThreadPool {
    // Demonstrates scheduling a task to run after a delay
    public static void run() throws InterruptedException {
        ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);
        scheduler.schedule(() -> System.out.println("Scheduled task executed after 2s"), 2, TimeUnit.SECONDS);
        scheduler.shutdown();
    }

}
