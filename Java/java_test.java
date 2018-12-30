
class Animal {
    Animal() {
        System.out.println("Animal");
    }
};


class Dog extends Animal {
    Dog() {
        System.out.println("Dog");
    }
};


class Puppy extends Dog {
    Puppy() {
        System.out.println("Puppy");
    }
};


class Cat extends Animal {
    Cat() {
        System.out.println("Cat");
    }
};


class Kitty extends Cat {
    Kitty() {
        System.out.println("Kitty");
    }
};


public class java_test {
    public static void main(String[] args) {
        Dog dog = new Dog();
        Cat cat = new Cat();

        // Puppy puppy = (Cat)dog;
        Cat cat1 = (Animal)cat;

    }
}
