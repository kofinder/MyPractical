package threads.sync.src;

public class NestedSync {
    public synchronized void outer() {
        System.out.println("Outer start");
        inner();
        System.out.println("Outer end");
    }

    private synchronized void inner() {
        System.out.println("Inner method");
    }

}
