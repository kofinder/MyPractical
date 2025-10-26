package threads.concurrents;

import java.util.concurrent.ExecutionException;

import threads.concurrents.src.*;

public class Main {
    public static void main(String[] args) throws InterruptedException, ExecutionException {

        FixedThreadPool.run();
        SingleThreadExecutor.run();
        CachedThreadPool.run();
        ScheduledThreadPool.run();
        FutureThread.run();
        FutureIsDone.run();
        CompletableFutureRunAsync.run();
        CompletableFutureSupplyAsync.run();
        CompletableFutureThenApply.run();
        CompletableFutureThenAccept.run();
        CompletableFutureThenCombine.run();
        CompletableFutureAllOf.run();
        CompletableFutureExceptionally.run();
        ForkJoinPool.run();
        ForkJoinAsync.run();
        ParallelStreamSum.run();
        ParallelStreamFilter.run();
        ParallelStreamForEach.run();
        ExecutorInvokeAll.run();
        ScheduledExecutorFixedRate.run();

    }
}
