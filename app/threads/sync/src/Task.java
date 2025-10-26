package threads.sync.src;

public class Task {
    public void execute() {
        synchronized (this) {
            System.out.println(Thread.currentThread().getName() + " executing");
        }
    }

}
