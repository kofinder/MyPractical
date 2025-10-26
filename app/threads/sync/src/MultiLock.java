package threads.sync.src;

public class MultiLock {
    private final Object lock1 = new Object();
    private final Object lock2 = new Object();

    public void task1() {
        synchronized (lock1) {
            System.out.println("Task1");
        }
    }

    public void task2() {
        synchronized (lock2) {
            System.out.println("Task2");
        }
    }
}
