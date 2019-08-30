package tmp;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class 단지2667 {
	static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	public static void main(String[] args) {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

			int n = Integer.parseInt(br.readLine());

			char[][] map = new char[n][n];
			boolean[][] visit = new boolean[n][n];
			ArrayList<Integer> arr = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				map[i] = br.readLine().toCharArray();
			}
			int cnt = 1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] == '1' && !visit[i][j]) {
						int sum = 1;
						Queue<Pair> q = new LinkedList<>();
						q.add(new Pair(i, j));
						while (!q.isEmpty()) {
							int y = q.peek().first;
							int x = q.peek().second;
							for (int k = 0; k < 4; k++) {
								int ny = y + dir[k][0];
								int nx = x + dir[k][1];

								if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
									if (!visit[ny][nx] && map[ny][nx] == '1') {
										visit[ny][nx] = true;
										q.add(new Pair(ny, nx));
										sum++;
									}
								}
							}
							q.poll();
						}
						arr.add(sum);
					}
				}
			}
			
			Collections.sort(arr);
			int size = arr.size()-1;
			for(int i = 0; i<size; i++) {
				System.out.println(arr.get(i));
			}
			System.out.println(arr.get(arr.size()-1));

		} catch (Exception e) {
		}
	}

	static class Pair {
		int first, second;

		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
}
