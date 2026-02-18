package threads;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class VirtualThreadDemo {
    public static void main(String[] args) throws InterruptedException {
        ExecutorService service = Executors.newSingleThreadExecutor();

        service.submit(() -> {
            while (true) {
                try {
                    System.out.println("hello world");
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                }
            }

        });
    }

}
