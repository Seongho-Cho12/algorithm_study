#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, start, end, res;
    cin >> N >> M;
    N++;
    vector<int> sum(N);
    sum[0] = 0;
    for (int i=1; i<N; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    for (int i=0; i<M; i++) {
        cin >> start >> end;
        res = sum[end] - sum[start-1];
        cout << res << "\n";
    }
    return 0;
}
