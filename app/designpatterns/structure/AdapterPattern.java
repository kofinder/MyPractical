package designpatterns.structure;

/*
 * The Adapter pattern converts the interface of a class into another interface clients expect, allowing incompatible classes to work together
 * Make an incompatible interface compatible with the client
 */

class OldPrinter {
    void printText(String text) {
        System.out.println(text);
    }
}

interface NewPrinter {
    void print(String text);
}

class PrinterAdapter implements NewPrinter {

    private OldPrinter oldPrinter;

    public PrinterAdapter(OldPrinter printer) {
        this.oldPrinter = printer;
    }

    @Override
    public void print(String text) {
        oldPrinter.printText(text);
    }

}

public class AdapterPattern {
    public static void main(String[] args) {
        OldPrinter oldPrinter = new OldPrinter();
        NewPrinter printer = new PrinterAdapter(oldPrinter);
        printer.print("Hello Adapter");

    }
}
