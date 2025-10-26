package designpatterns.structure;

import java.util.HashMap;
import java.util.Map;

/*
 * The Flyweight pattern reduces memory usage by sharing common parts of objects instead of creating duplicates
 * Reuse objects to save memory.
 */

// Flyweight
interface TreeType {
    void display(int x, int y);
}

// Concrete Flyweight
class Tree implements TreeType {
    private String type;

    public Tree(String type) {
        this.type = type;
    }

    public void display(int x, int y) {
        System.out.println("Tree " + type + " at (" + x + "," + y + ")");
    }
}

// Flyweight Factory
class TreeFactory {
    private static final Map<String, Tree> treeMap = new HashMap<>();

    public static Tree getTree(String type) {
        treeMap.putIfAbsent(type, new Tree(type));
        return treeMap.get(type);
    }
}

public class FlyweightPattern {
    public static void main(String[] args) {
        Tree oak1 = TreeFactory.getTree("Oak");
        Tree oak2 = TreeFactory.getTree("Oak");
        Tree pine = TreeFactory.getTree("Pine");
        oak1.display(1, 1);
        oak2.display(2, 3);
        pine.display(5, 7);
        System.out.println("Oak1 == Oak2? " + (oak1 == oak2)); // true, reused

    }
}
