#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

const int MOD = 1000000003;

int main() {
	int N, K, threshold;
	scanf("%d %d", &N, &K);
	threshold = N / 2;
	if (K > threshold) printf("0");
	else {
		vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++) {
			dp[i][1] = i;
		}
		for (int i = 4; i <= N; i++) {
			for (int j = 2; j <= K; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
			}
		}
		printf("%d", dp[N][K]);
	}
}