package threads.concurrents.src;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class FutureIsDone {
    // Checks if the task is done before retrieving the result
    public static void run() throws ExecutionException, InterruptedException {
        ExecutorService executor = Executors.newFixedThreadPool(1);
        Future<String> future = executor.submit(() -> {
            Thread.sleep(1000);
            return "Task finished after 1s";
        });
        while (!future.isDone()) {
            System.out.println("Waiting...");
        }
        System.out.println(future.get());
        executor.shutdown();
    }

}
