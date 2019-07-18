package edu.algo.day1;

import java.util.Scanner;

public class SWEA_7510 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		for (int tc = 1; tc <= t; tc++) {
			int ans = 0;
			int n = sc.nextInt();

			for (int i = 1; i <= n; i++) {
				int sum = 0;

				for (int j = i; sum < n; j++) {
					sum += j;
				}

				if (sum == n)
					ans++;
			}

			System.out.println("#" + tc + " " + ans);
		}
	}
}
