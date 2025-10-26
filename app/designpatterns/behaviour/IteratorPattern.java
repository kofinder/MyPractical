package designpatterns.behaviour;

import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

/*
 * The Iterator pattern provides a way to access elements of a collection sequentially without exposing its underlying representation
 * Example: Iterating through a List or Set
 */

public class IteratorPattern {
    public static void main(String[] args) {
        List<String> names = Arrays.asList("Alice", "Bob", "Charlie");

        Iterator<String> iterator = names.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

    }
}
