package threads.sync.src;

public class NumberPrinter {
    public synchronized void printNumber(int n) {
        System.out.println(Thread.currentThread().getName() + ": " + n);
    }

}
