package threads.concurrents.src;

import java.util.concurrent.RecursiveTask;

public class ForkJoinPool {
    static class SumTask extends RecursiveTask<Integer> {
        private int[] arr;
        private int start, end;

        public SumTask(int[] arr, int start, int end) {
            this.arr = arr;
            this.start = start;
            this.end = end;
        }

        @Override
        protected Integer compute() {
            if (end - start <= 2) {
                int sum = 0;
                for (int i = start; i < end; i++)
                    sum += arr[i];
                return sum;
            } else {
                int mid = (start + end) / 2;
                SumTask left = new SumTask(arr, start, mid);
                SumTask right = new SumTask(arr, mid, end);
                left.fork();
                return right.compute() + left.join();
            }
        }
    }

    public static void run() {
        java.util.concurrent.ForkJoinPool pool = new java.util.concurrent.ForkJoinPool(); // now refers to
                                                                                          // java.util.concurrent.ForkJoinPool
        int[] data = { 1, 2, 3, 4, 5 };
        int result = pool.invoke(new SumTask(data, 0, data.length));
        System.out.println("ForkJoinPool sum: " + result);
    }

}
