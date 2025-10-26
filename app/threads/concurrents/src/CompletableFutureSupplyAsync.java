package threads.concurrents.src;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class CompletableFutureSupplyAsync {
    // Run async task returning a value
    public static void run() throws ExecutionException, InterruptedException {
        CompletableFuture<Integer> cf = CompletableFuture.supplyAsync(() -> 5 * 5);
        System.out.println("Result: " + cf.get());
    }

}
