package threads.sync.src;

public class DelayCounter {
    private int count = 0;

    public synchronized void increment() throws InterruptedException {
        int temp = count;
        Thread.sleep(1);
        count = temp + 1;
    }

    public synchronized int getCount() {
        return count;
    }

}
