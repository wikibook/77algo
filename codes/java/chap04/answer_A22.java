import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		for (int i = 1; i <= N - 1; i++) A[i] = sc.nextInt();
		for (int i = 1; i <= N - 1; i++) B[i] = sc.nextInt();

		// 배열 초기화
		int[] dp = new int[N + 1];
		dp[1] = 0;
		for (int i = 2; i <= N; i++) dp[i] = -1000000000;

		// 동적 계획 알고리즘
		for (int i = 1; i <= N - 1; i++) {
			dp[A[i]] = Math.max(dp[A[i]], dp[i] + 100);
			dp[B[i]] = Math.max(dp[B[i]], dp[i] + 150);
		}

		// 출력
		System.out.println(dp[N]);
	}
};
