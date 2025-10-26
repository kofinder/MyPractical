package designpatterns.behaviour;

/*
 * The Template Method pattern defines the skeleton of an algorithm in a method, deferring some steps to subclasses
 * Skeleton of algorithm, customizable steps.
 */

abstract class Game {
    abstract void initialize();

    abstract void play();

    abstract void end();

    // Template method
    public final void playGame() {
        initialize();
        play();
        end();
    }
}

class Football extends Game {
    void initialize() {
        System.out.println("Football Game Initialized");
    }

    void play() {
        System.out.println("Football Game Playing");
    }

    void end() {
        System.out.println("Football Game Finished");
    }
}

public class TemplateMethodPattern {
    public static void main(String[] args) {
        Game game = new Football();
        game.playGame();

    }
}
