package threads.concurrents.src;

import java.util.concurrent.CompletableFuture;

public class CompletableFutureThenAccept {
    // Consume result without returning a new value
    public static void run() {
        CompletableFuture.supplyAsync(() -> "Hello").thenAccept(s -> System.out.println("thenAccept: " + s));
    }

}
