package threads.sync.src;

class StringLock {
    public void print(String message) {
        synchronized ("LOCK") {
            System.out.println(message);
        }
    }
}
