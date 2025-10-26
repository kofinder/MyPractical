package threads.sync.src;

public class SharedResource {
    public static void doWork() {
        synchronized (SharedResource.class) {
            System.out.println(Thread.currentThread().getName() + " working");
        }
    }

}
