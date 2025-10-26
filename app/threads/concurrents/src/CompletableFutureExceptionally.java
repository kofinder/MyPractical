package threads.concurrents.src;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class CompletableFutureExceptionally {
    // Handle exceptions in async tasks
    public static void run() throws ExecutionException, InterruptedException {
        CompletableFuture<Integer> cf = CompletableFuture.supplyAsync(() -> 1 / 0)
                .exceptionally(ex -> {
                    System.out.println("Exception caught: " + ex);
                    return -1;
                });
        System.out.println("Handled result: " + cf.get());
    }

}
