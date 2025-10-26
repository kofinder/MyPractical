package threads.sync.src;

public class Printer {
    private final Object lock = new Object();

    public void print(String message) {
        synchronized (lock) {
            System.out.println(message);
        }
    }

}
