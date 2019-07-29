package edu.framework;

import chap06two.Lion;

public class LionKing extends Lion {
    @Override
    public void walk() {
        System.out.println("심바가 걸어요");
    }

    @Override
    public void roar() {
        System.out.println("심바가 으헝합니다");
    }

    @Override
    public String whoami() {
        return "심바";
    }
}
