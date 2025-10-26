package threads.concurrents.src;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class CompletableFutureRunAsync {
    // Run async task without returning a result
    public static void run() throws ExecutionException, InterruptedException {
        CompletableFuture<Void> cf = CompletableFuture
                .runAsync(() -> System.out.println("Async task using CompletableFuture"));
        cf.get();
    }

}
