#include <iostream>
#include <algorithm>
using namespace std;

long long N, W, w[109], v[109];
long long dp[109][100009];

int main() {
	// 입력, 배열 초기화
	cin >> N >> W;
	for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= W; j++) dp[i][j] = -1'000'000'000'000'000LL;
	}

	// 동적 계획 알고리즘
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= W; j++) {
			if (j < w[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	// 답 출력
	long long Answer = 0;
	for (int i = 0; i <= W; i++) Answer = max(Answer, dp[N][i]);
	cout << Answer << endl;
	return 0;
}
