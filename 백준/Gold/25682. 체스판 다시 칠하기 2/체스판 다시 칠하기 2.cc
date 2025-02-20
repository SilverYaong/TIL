#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    bool arr[n][m];
    int black[n][m];
    int white[n][m];

    fill(&black[0][0], &black[n][0], 0);
    fill(&white[0][0], &white[n][0], 0);
    fill(&arr[0][0], &arr[n][0], 0);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = (s[j] == 'B') ? 0 : 1;
        }
    }

    // 누적합 계산
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0) {
                white[i][j] += white[i - 1][j];
                black[i][j] += black[i - 1][j];
            }
            if (j > 0) {
                white[i][j] += white[i][j - 1];
                black[i][j] += black[i][j - 1];
            }
            if (i > 0 && j > 0) {
                white[i][j] -= white[i - 1][j - 1];
                black[i][j] -= black[i - 1][j - 1];
            }

            if (arr[i][j] == 0) // 검은색일 때
            {
                if ((i + j) % 2 == 0) {
                    black[i][j]++;
                } else {
                    white[i][j]++;
                }
            }
            else // 흰색일 때
            {
                if ((i + j) % 2 == 0) {
                    white[i][j]++;
                } else {
                    black[i][j]++;
                }
            }
        }
    }

    int ans = n * m;
    for (int i = 0; i <= n - k; i++)
    {
        for (int j = 0; j <= m - k; j++)
        {
            int subsumA = black[i + k - 1][j + k - 1];
            int subsumB = white[i + k - 1][j + k - 1];

            if (i > 0) {
                subsumA -= black[i - 1][j + k - 1];
                subsumB -= white[i - 1][j + k - 1];
            }
            if (j > 0) {
                subsumA -= black[i + k - 1][j - 1];
                subsumB -= white[i + k - 1][j - 1];
            }
            if (i > 0 && j > 0) {
                subsumA += black[i - 1][j - 1];
                subsumB += white[i - 1][j - 1];
            }

            ans = min(ans, min(subsumA, subsumB));
        }
    }
    
    cout << ans << '\n';
}