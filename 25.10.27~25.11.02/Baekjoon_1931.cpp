// 2025.10.29
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, a, b, end = 0, cnt = 0;
    cin >> N;
    vector<vector<int>> A(N);
    for (int i=0; i<N; i++) {
        cin >> a >> b;
        A[i].push_back(b);
        A[i].push_back(a);
    }
    sort(A.begin(), A.end());
    for (int i=0; i<N; i++) {
        if (end <= A[i][1]) {
            end = A[i][0];
            cnt++;
        }
    }
    cout << cnt;
}

// 1트컷