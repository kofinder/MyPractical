package designpatterns.structure;

/*
 * The Singleton pattern ensures a class has 
 * only one instance and provides a global point of access to it.
 * 
 */

class SingleTon {

    public static SingleTon instance = new SingleTon();

    private SingleTon() {
    }

    public static SingleTon getInstance() {
        return instance;
    }

    public void hello() {
        System.out.println("hello world!");
    }
}

class SingleTonPattern {
    public static void main(String[] args) {
        var pattern = SingleTon.getInstance();
        pattern.hello();
    }
}