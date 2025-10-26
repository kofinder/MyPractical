package threads.concurrents.src;

import java.util.Arrays;
import java.util.List;

public class ParallelStreamForEach {
    public static void run() {
        List<String> words = Arrays.asList("apple", "banana", "orange", "pear");
        words.parallelStream().forEach(s -> System.out.println("Word: " + s));
    }

}
