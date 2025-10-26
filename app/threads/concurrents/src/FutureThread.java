package threads.concurrents.src;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class FutureThread {
    // Submit a callable task and get the result
    public static void run() throws ExecutionException, InterruptedException {
        ExecutorService executor = Executors.newFixedThreadPool(1);
        Future<Integer> future = executor.submit(() -> 10 + 20);
        System.out.println("Future result: " + future.get());
        executor.shutdown();
    }

}
