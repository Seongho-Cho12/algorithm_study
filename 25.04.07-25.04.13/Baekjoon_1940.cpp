#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2025.04.10
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, sum, left = 0, right, res = 0;
    cin >> N >> M;
    right = N - 1;
    vector<int> sorted_vec(N);
    for (int i=0; i<N; i++) {
        cin >> sorted_vec[i];
    }
    sort(sorted_vec.begin(), sorted_vec.end());
    while (left < right) {
        sum = sorted_vec[left] + sorted_vec[right];
        if (sum == M) {
            res++;
            left++;
        }
        else if (sum > M) {
            right--;
        }
        else {
            left++;
        }
    }
    cout << res;
    return 0;
}

// 1트컷