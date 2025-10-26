package threads.concurrents.src;

import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ExecutorInvokeAll {
    public static void run() throws InterruptedException, ExecutionException {
        ExecutorService executor = Executors.newFixedThreadPool(2);
        List<Callable<String>> tasks = List.of(() -> "Task1", () -> "Task2");
        List<Future<String>> results = executor.invokeAll(tasks);
        for (Future<String> f : results)
            System.out.println("invokeAll: " + f.get());
        executor.shutdown();
    }

}
