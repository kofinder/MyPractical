package designpatterns.behaviour;

/*
 * The Visitor pattern lets you define new operations on elements of an object structure without changing the classes of those elements
 * Add operations to elements without changing them.
 */

// Element
interface ComputerPart {
    void accept(ComputerPartVisitor visitor);
}

// Concrete Elements
class Keyboard implements ComputerPart {
    public void accept(ComputerPartVisitor visitor) {
        visitor.visit(this);
    }
}

class Monitor implements ComputerPart {
    public void accept(ComputerPartVisitor visitor) {
        visitor.visit(this);
    }
}

// Visitor
interface ComputerPartVisitor {
    void visit(Keyboard keyboard);

    void visit(Monitor monitor);
}

// Concrete Visitor
class ComputerPartDisplayVisitor implements ComputerPartVisitor {
    public void visit(Keyboard keyboard) {
        System.out.println("Displaying Keyboard");
    }

    public void visit(Monitor monitor) {
        System.out.println("Displaying Monitor");
    }
}

public class VisitorPattern {
    public static void main(String[] args) {
        ComputerPart[] parts = { new Keyboard(), new Monitor() };
        ComputerPartVisitor visitor = new ComputerPartDisplayVisitor();

        for (ComputerPart part : parts) {
            part.accept(visitor);
        }

    }
}
