package edu.framework;

import chap06two.Animal;
import chap06two.Lion;

public class Base {
    public void toAnimal(Animal a) {
        System.out.println(a.whoami());
    }

    public void toRoar(Lion a) {
        a.roar();
    }

    public void toWalk(Animal a) {
        a.walk();
    }
}
