#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, H[100009];
int dp[100009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];

	// 동적 계획 알고리즘
	dp[1] = 0;
	dp[2] = abs(H[1] - H[2]);
	for (int i = 3; i <= N; i++) {
		dp[i] = min(dp[i - 1] + abs(H[i - 1] - H[i]), dp[i - 2] + abs(H[i - 2] - H[i]));
	}

	// 출력
	cout << dp[N] << endl;
	return 0;
}
