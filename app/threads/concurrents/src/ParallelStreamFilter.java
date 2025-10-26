package threads.concurrents.src;

import java.util.Arrays;
import java.util.List;

public class ParallelStreamFilter {
    public static void run() {
        List<String> words = Arrays.asList("apple", "banana", "orange", "pear");
        List<String> longWords = words.parallelStream().filter(s -> s.length() > 4).toList();
        System.out.println("Filtered words: " + longWords);
    }

}
