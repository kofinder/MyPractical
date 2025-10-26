package threads.concurrents.src;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ForkJoinTask;
import java.util.concurrent.RecursiveTask;

public class ForkJoinAsync {

    public static void run() throws ExecutionException, InterruptedException {
        java.util.concurrent.ForkJoinPool pool = new java.util.concurrent.ForkJoinPool();

        ForkJoinTask<Integer> task = new RecursiveTask<>() {
            @Override
            protected Integer compute() {
                return 42;
            }
        };

        pool.submit(task);
        System.out.println("ForkJoinTask result: " + task.get());
        pool.shutdown();
    }

}
