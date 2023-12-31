import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		for (int i = 2; i <= N; i++) A[i] = sc.nextInt();
		for (int i = 3; i <= N; i++) B[i] = sc.nextInt();

		// 동적 계획 알고리즘
		int[] dp = new int[N + 1];
		dp[1] = 0;
		dp[2] = A[2];
		for (int i = 3; i <= N; i++) {
			dp[i] = Math.min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
		}

		// 출력
		System.out.println(dp[N]);
	}
};
