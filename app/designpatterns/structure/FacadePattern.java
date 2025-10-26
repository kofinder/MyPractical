package designpatterns.structure;

/*
 * The Facade pattern provides a unified, high-level interface to a set of interfaces in a subsystem, simplifying usage
 * Provide a simple interface to a complex subsystem.
 */

// Subsystems
class CPU {
    void start() {
        System.out.println("CPU starting");
    }
}

class Memory {
    void load() {
        System.out.println("Memory loading");
    }
}

class HardDrive {
    void read() {
        System.out.println("HardDrive reading");
    }
}

// Facade
class Computer {
    private CPU cpu = new CPU();
    private Memory memory = new Memory();
    private HardDrive hd = new HardDrive();

    public void startComputer() {
        cpu.start();
        memory.load();
        hd.read();
        System.out.println("Computer started");
    }
}

public class FacadePattern {
    public static void main(String[] args) {
        Computer computer = new Computer();
        computer.startComputer();

    }
}
