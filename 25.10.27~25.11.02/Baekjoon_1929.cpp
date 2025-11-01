// 2025.11.01
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    vector<int> A;
    for (int i=0; i<=N; i++) {
        A.push_back(i);
    }
    A[1] = 0;
    for (int i=2; i<=sqrt(N); i++) {
        if (A[i] == 0) {
            continue;
        }
        else {
            for (int j=i+1; j<=N; j++) {
                if (A[j] != 0 && j % i == 0) {
                    A[j] = 0;
                }
            }
        }
    }
    for (int i=M; i<=N; i++) {
        if (A[i] != 0) {
            cout << A[i] << "\n";
        }
    }
}

// 1트컷
// 에라토스테네스 방식 사용
// 2부터 최대값의 루트 값까지 자신의 배수를 삭제
// 그 값이 이미 특정 수의 배수인 경우 건너뛰기