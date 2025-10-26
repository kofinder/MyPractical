package threads.sync;

import threads.sync.src.Counter;

public class Main {
    public static void main(String[] args) throws InterruptedException {

        Counter counter = new Counter();
        int numThreads = 2000;

        Thread[] threads = new Thread[numThreads];

        // Create and start threads
        for (int i = 0; i < numThreads; i++) {
            threads[i] = new Thread(counter::increment);
            threads[i].start();
        }

        // Wait for all threads to finish
        for (int i = 0; i < numThreads; i++) {
            threads[i].join();
        }

        System.out.println("Final counter value: " + counter.getCount()); // should be 2000

    }
}
