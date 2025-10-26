package threads.concurrents.src;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class CompletableFutureThenApply {
    // Transform result of async task
    public static void run() throws ExecutionException, InterruptedException {
        CompletableFuture<Integer> cf = CompletableFuture.supplyAsync(() -> 10).thenApply(n -> n * 2);
        System.out.println("thenApply result: " + cf.get());
    }

}
