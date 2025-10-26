package designpatterns.structure;

/*
 * The Decorator pattern attaches additional responsibilities to an object dynamically without altering its class
 * **Wrap objects for extra behavior**  
 * Add features dynamically without modifying the original class
 */

// Component
interface Coffee {
    double cost();
}

// Concrete Component
class SimpleCoffee implements Coffee {
    public double cost() {
        return 5;
    }
}

// Decorator
abstract class CoffeeDecorator implements Coffee {
    protected Coffee coffee;

    public CoffeeDecorator(Coffee coffee) {
        this.coffee = coffee;
    }
}

// Concrete Decorator
class MilkDecorator extends CoffeeDecorator {
    public MilkDecorator(Coffee coffee) {
        super(coffee);
    }

    public double cost() {
        return coffee.cost() + 2;
    }
}

public class DecoratorPattern {
    public static void main(String[] args) {
        Coffee coffee = new MilkDecorator(new SimpleCoffee());
        System.out.println("Cost: " + coffee.cost());

    }
}
