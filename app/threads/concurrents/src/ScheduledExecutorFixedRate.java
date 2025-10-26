package threads.concurrents.src;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class ScheduledExecutorFixedRate {
    public static void run() {
        ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);
        scheduler.scheduleAtFixedRate(() -> System.out.println("Scheduled at fixed rate"), 0, 1, TimeUnit.SECONDS);
        scheduler.schedule(() -> scheduler.shutdown(), 3, TimeUnit.SECONDS);
    }

}
