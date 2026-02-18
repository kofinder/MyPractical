/*
    Static block
    Main starts
    Instance block
    Constructor
    Instance block
    Constructor
*/

class Program {

    static {
        System.out.println("Static block");
    }

    {
        System.out.println("Instance block");
    }

    Program() {
        System.out.println("Constructor");
    }

    public static void main(String[] args) {
        System.out.println("Main starts");
        new Program();
        new Program();
    }
}