package edu.framework;

import chap06two.Lion;

public class Main {
    public static void main(String[] args) {

        Lion l = new Lion();
        Base b = new Base();

        b.toAnimal(l);
        b.toWalk(l);
        b.toRoar(l);

        LionKing lk = new LionKing();
        b.toAnimal(lk);
        b.toRoar(lk);
        b.toWalk(lk);

    }
}
