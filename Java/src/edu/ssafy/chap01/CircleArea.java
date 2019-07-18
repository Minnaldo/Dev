package edu.ssafy.chap01;

public class CircleArea {

	public static void main(String[] args) {
		double r = 5;
		double pie = Math.PI;
		double size = pie * Math.pow(r, 2);
		System.out.printf("반지름이 5Cm인 원의 넓이는 %.1fCm2 입니다", size);
	}

}