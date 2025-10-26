package threads.sync.src;

public class SharedCounter {
    private int count = 0;

    public void run() {
        for (int i = 0; i < 1000; i++) {
            increment();
        }
    }

    private synchronized void increment() {
        count++;
    }

    public synchronized int getCount() {
        return count;
    }

}
