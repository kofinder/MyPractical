package designpatterns.creational;

/*
    *  Builder → complex object, step-by-step.
    *  The Builder pattern separates the construction of a complex object from its representation, allowing it to be built step by step.
*/

public class BuilderPattern {
    private final int age; // optional
    private final String address; // optional
    private final String phone; // optional

    private BuilderPattern(Builder builder) {
        this.age = builder.age;
        this.address = builder.address;
        this.phone = builder.phone;
    }

    public static class Builder {

        private int age = 0;
        private String address = "";
        private String phone = "";

        public Builder age(int age) {
            this.age = age;
            return this;
        }

        public Builder address(String address) {
            this.address = address;
            return this;
        }

        public Builder phone(String phone) {
            this.phone = phone;
            return this;
        }

        public BuilderPattern build() {
            return new BuilderPattern(this);
        }

    }

    public int getAge() {
        return this.age;
    }

    public String getAddress() {
        return this.address;
    }

    public String getPhone() {
        return this.phone;
    }

}
