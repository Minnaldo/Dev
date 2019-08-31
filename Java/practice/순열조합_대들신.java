

public class 순열조합_대들신 {
	static int[] num = { 1, 2, 3 };
	static final int LIMIT = 2;
	static int[] nums = { 1, 2, 3 };
	static int[] picked = new int[nums.length];
	public static void main(String[] args) {
//		perm(0); // 순열
//		perm_re(0); // 중복순열
//		comb(0, 0); // 조합
//		comb_re(0, 0); // 중복 조합

		powerset(0); // 출력되는 0은 선택되지 않은 자리를 의미하는 것으로 간주함.
//		powersetBit(0, 0);
	}

	static int[] pickedNum = new int[num.length];
	static boolean[] use = new boolean[num.length];

	// 순열
	static void perm(int idx) {
		// LIMIT개를 뽑는 경우의 수
		if (idx >= LIMIT) {
			// 현재까지 뽑은 수를 출력한다
			for (int i = 0; i < LIMIT; i++) {
				System.out.print(pickedNum[i] + " ");
			}
			System.out.println();
			return;
		}

		// 사용하지 원소들만 뽑아야 한다
		// r개의 원소를 뽑는 경우의 수
		//
		for (int i = 0; i < num.length; i++) {
			if (!use[i]) {
				use[i] = true;
				pickedNum[idx] = num[i];
				perm(idx + 1);
				use[i] = false;
			}
		}

	}

	// 중복순열
	static void perm_re(int pickCnt) {
		if (pickCnt >= LIMIT) {
			for (int i = 0; i < LIMIT; i++) {
				System.out.print(pickedNum[i] + " ");
			}
			System.out.println();
			return;
		}
		for (int i = 0; i < num.length; i++) {
			pickedNum[pickCnt] = num[i];
			perm_re(pickCnt + 1);
		}
	}

	// 조합
	static void comb(int pos, int pickCnt) {
		if (pickCnt >= LIMIT) {
			for (int i = 0; i < LIMIT; i++) {
				System.out.print(pickedNum[i] + " ");
			}
			System.out.println();
			return;
		}
		// pos부터 시작하는 이유 : num[pos] 이전 원소들을 앞에서 이미 뽑았기 때문에 뽑지 않아도 된다.
		// num[poㄴ]부터 뽑아야 한다
		for (int i = pos; i < num.length; i++) {
			pickedNum[pickCnt] = num[i];
			comb(i + 1, pickCnt + 1);
		}
	}

	// 중복조합
	static void comb_re(int pos, int pickCnt) {
		if (pickCnt >= LIMIT) {
			for (int i = 0; i < LIMIT; i++) {
				System.out.print(pickedNum[i] + " ");
			}
			System.out.println();
			return;
		}
		for (int i = pos; i < num.length; i++) {
			pickedNum[pickCnt] = num[i];
			comb_re(i, pickCnt + 1);
		}
	}


	// 부분집합
	static void powerset(int idx) {
		if (idx == nums.length) {
			for (int i = 0; i < picked.length; i++) {
				if(picked[i] == 0) continue;
				System.out.print(picked[i] + " ");
			}
			System.out.println();
			return;
		}

		// 수를 선택하지 않는 경우
		powerset(idx + 1);

		// 수를 선택하는 경우
		picked[idx] = num[idx];
		powerset(idx + 1);
		picked[idx] = 0; // 0은 선택되지 않은 자리를 의미하는 것으로 간주함
	}
}
