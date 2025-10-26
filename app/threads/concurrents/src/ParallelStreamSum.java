package threads.concurrents.src;

import java.util.stream.IntStream;

public class ParallelStreamSum {
    public static void run() {
        int sum = IntStream.range(1, 10).parallel().map(n -> n * 2).sum();
        System.out.println("Parallel stream sum: " + sum);
    }

}
