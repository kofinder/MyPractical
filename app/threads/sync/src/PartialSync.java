package threads.sync.src;

public class PartialSync {
    private int value = 0;

    public void compute() {
        System.out.println("Start computation");
        synchronized (this) {
            value++;
            System.out.println("Value after increment: " + value);
        }
        System.out.println("End computation");
    }

}
