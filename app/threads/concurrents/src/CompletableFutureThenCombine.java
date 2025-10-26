package threads.concurrents.src;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class CompletableFutureThenCombine {
    // Combine two async results
    public static void run() throws ExecutionException, InterruptedException {
        CompletableFuture<Integer> cf = CompletableFuture.supplyAsync(() -> 10)
                .thenCombine(CompletableFuture.supplyAsync(() -> 20), Integer::sum);
        System.out.println("thenCombine result: " + cf.get());
    }

}
