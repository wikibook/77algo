#include <iostream>
using namespace std;

// 입력으로 주어지는 변수
int D, X, A[200009];
int Q, S[200009], T[200009];

// 각 일별 주가
int Price[200009];

int main() {
	// 입력
	cin >> D >> X;
	for (int i = 2; i <= D; i++) cin >> A[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> S[i] >> T[i];

	// 각 일별 주가 구하기(누적 합계)
	Price[1] = X;
	for (int i = 2; i <= D; i++) Price[i] = Price[i - 1] + A[i];

	// 답 출력하기
	for (int i = 1; i <= Q; i++) {
		if (Price[S[i]] > Price[T[i]]) cout << S[i] << endl;
		else if (Price[S[i]] < Price[T[i]]) cout << T[i] << endl;
		else cout << "Same" << endl;
	}
	return 0;
}
