package threads.sync.src;

class Resource {
    String name;

    Resource(String name) {
        this.name = name;
    }
}

public class DeadlockExample {
    public static void main(String[] args) {
        final Resource resource1 = new Resource("Resource1");
        final Resource resource2 = new Resource("Resource2");

        // Thread 1 locks resource1 first, then tries to lock resource2
        Thread t1 = new Thread(() -> {
            synchronized (resource1) {
                System.out.println("Thread 1: locked resource 1");

                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                }

                synchronized (resource2) {
                    System.out.println("Thread 1: locked resource 2");
                }
            }
        });

        // Thread 2 locks resource2 first, then tries to lock resource1
        Thread t2 = new Thread(() -> {
            synchronized (resource2) {
                System.out.println("Thread 2: locked resource 2");

                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                }

                synchronized (resource1) {
                    System.out.println("Thread 2: locked resource 1");
                }
            }
        });

        t1.start();
        t2.start();
    }
}
