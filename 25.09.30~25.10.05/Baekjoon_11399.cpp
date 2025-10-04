#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2025.10.04
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, sum = 0;
    cin >> N;
    vector<int> vec(N);
    for (int i=0; i<N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i=0; i<N; i++) {
        sum += vec[i]*(N-i);
    }
    cout << sum;
}

// 1트컷