package designpatterns.structure;

import java.util.ArrayList;
import java.util.List;

/*
 * The Adapter pattern converts the interface of a class into another interface clients expect, allowing incompatible classes to work together
 * Treat single objects and groups uniformly (tree structure).
*/

// Component
interface Graphic {
    void draw();
}

// Leaf
class Circle implements Graphic {
    public void draw() {
        System.out.println("Circle");
    }
}

// Composite
class CompositeGraphic implements Graphic {

    private List<Graphic> children = new ArrayList<>();

    public void add(Graphic g) {
        children.add(g);
    }

    @Override
    public void draw() {
        for (Graphic g : children) {
            g.draw();
        }
    }
}

public class CompositePattern {
    public static void main(String[] args) {
        Circle c1 = new Circle();
        Circle c2 = new Circle();
        CompositeGraphic group = new CompositeGraphic();
        group.add(c1);
        group.add(c2);
        group.draw();
    }
}
