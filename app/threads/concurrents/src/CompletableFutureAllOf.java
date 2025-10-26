package threads.concurrents.src;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class CompletableFutureAllOf {
    // Wait for multiple async tasks to finish
    public static void run() throws ExecutionException, InterruptedException {
        CompletableFuture<Void> cf = CompletableFuture.allOf(
                CompletableFuture.runAsync(() -> System.out.println("Task A")),
                CompletableFuture.runAsync(() -> System.out.println("Task B")));
        cf.get();
    }

}
