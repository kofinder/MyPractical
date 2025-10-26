package designpatterns.creational;

/*
 * The Prototype pattern creates new objects by 
    copying (cloning) an existing object rather than creating a new instance from scratch
 * 
 */

public class Prototype implements Cloneable {
    private String name;
    private int age;

    public Prototype(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return this.age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    // deep copy
    protected Prototype deepClone() {
        return new Prototype(this.name, this.age);
    }

    @Override
    protected Prototype clone() {
        try {
            return (Prototype) super.clone(); // shallow copy
        } catch (CloneNotSupportedException ex) {
            throw new AssertionError();
        }
    }

}
