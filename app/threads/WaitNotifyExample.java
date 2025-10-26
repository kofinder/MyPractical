package threads;

class SharedResource {
    private boolean ready = false;

    synchronized void waitMethod() {
        System.out.println(Thread.currentThread().getName() + " waiting...");
        while (!ready) {
            try {
                wait(); // releases lock and waits
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(Thread.currentThread().getName() + " resumed!");
    }

    synchronized void notifyMethod() {
        System.out.println(Thread.currentThread().getName() + " notifying...");
        ready = true;
        notify(); // wakes up one waiting thread
    }
}

public class WaitNotifyExample {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();

        Thread waiter = new Thread(() -> resource.waitMethod(), "WaiterThread");
        Thread notifier = new Thread(() -> {
            try {
                Thread.sleep(2000); // wait 2 seconds before notifying
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            resource.notifyMethod();
        }, "NotifierThread");

        waiter.start();
        notifier.start();
    }
}
