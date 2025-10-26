package threads.sync.src;

class Base {
    public synchronized void show() {
        System.out.println("Base");
    }
}

class Derived extends Base {
    @Override
    public synchronized void show() {
        System.out.println("Derived");
    }
}
