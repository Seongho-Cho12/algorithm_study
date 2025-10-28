// 2025.10.28
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int S = 0, E = N-1, a, b, sum = 0;
    for (int i=0; i<N-1; i+=2) {
        a = A[i];
        b = A[i+1];
        if (a < 0 && b <= 0) {
            sum += a * b;
            S = i + 2;
        }
        else break;
    }
    for (int i=N-1; i>S; i-=2) {
        a = A[i];
        b = A[i-1];
        if (a > 1 && b > 1) {
            sum += a * b;
            E = i - 2;
        }
        else break;
    }
    for (int i=S; i<=E; i++) {
        sum += A[i];
    }
    cout << sum;
}

// 1트컷