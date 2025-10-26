package designpatterns.creational;

/*
 * The Bridge pattern decouples an abstraction from its implementation so the two can vary independently
 * Separate abstraction from implementation.
 */

// Implementor
interface Color {
    void applyColor();
}

// Concrete Implementors
class Red implements Color {
    public void applyColor() {
        System.out.println("Red color");
    }
}

class Green implements Color {
    public void applyColor() {
        System.out.println("Green color");
    }
}

// Abstraction
abstract class Shape {
    protected Color color;

    public Shape(Color color) {
        this.color = color;
    }

    abstract void draw();
}

// Refined Abstraction
class Circle extends Shape {
    public Circle(Color color) {
        super(color);
    }

    public void draw() {
        System.out.print("Circle drawn with ");
        color.applyColor();
    }
}

public class BridgePattern {
    public static void main(String[] args) {
        Shape redCircle = new Circle(new Red());
        Shape greenCircle = new Circle(new Green());
        redCircle.draw();
        greenCircle.draw();

    }
}
