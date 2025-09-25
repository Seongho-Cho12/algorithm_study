#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, temp, res;
    cin >> N >> M;
    vector<vector<int>> sums(N+1, vector<int>(N+1, 0));
    for (int i=1; i<N+1; i++) {
        for (int j=1; j<N+1; j++) {
            cin >> temp;
            sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + temp;
        }
    }
    int x1, y1, x2, y2;
    for (int i=0; i<M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        res = sums[x2][y2] - sums[x1-1][y2] - sums[x2][y1-1] + sums[x1-1][y1-1];
        cout << res << "\n";
    }
    return 0;
}
