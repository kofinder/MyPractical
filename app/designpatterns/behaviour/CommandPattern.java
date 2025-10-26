package designpatterns.behaviour;

/*
 * The Command pattern encapsulates a request as an object, allowing you to parameterize, queue, and execute requests flexibly
 * Example: Remote control buttons triggering different actions
 * Encapsulate actions as objects
 * turn actions into objects
 */

// Command interface
interface Command {
    void execute();
}

// Receiver
class Light {
    void on() {
        System.out.println("Light ON");
    }

    void off() {
        System.out.println("Light OFF");
    }
}

// Concrete Commands
class LightOnCommand implements Command {
    private Light light;

    public LightOnCommand(Light light) {
        this.light = light;
    }

    public void execute() {
        light.on();
    }
}

class LightOffCommand implements Command {
    private Light light;

    public LightOffCommand(Light light) {
        this.light = light;
    }

    public void execute() {
        light.off();
    }
}

// Invoker
class RemoteControl {
    private Command command;

    public void setCommand(Command command) {
        this.command = command;
    }

    public void pressButton() {
        command.execute();
    }
}

public class CommandPattern {
    public static void main(String[] args) {
        Light light = new Light();
        RemoteControl remote = new RemoteControl();

        remote.setCommand(new LightOnCommand(light));
        remote.pressButton();

        remote.setCommand(new LightOffCommand(light));
        remote.pressButton();

    }
}
