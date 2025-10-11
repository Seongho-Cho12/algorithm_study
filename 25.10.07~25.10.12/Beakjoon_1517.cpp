// 2025.10.11
#include <iostream>
#include <vector>
using namespace std;

long mergeSort(vector<int> &A, int S, int E, long move);
long merge(vector<int> &A, int S, int M, int E);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long res;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    res = mergeSort(A, 0, N-1, 0);
    cout << res;
}

long mergeSort(vector<int> &A, int S, int E, long move)
{
    if (S == E) return move;
    int M = (S + E) / 2 + 1;
    move += mergeSort(A, S, M-1, 0);
    move += mergeSort(A, M, E, 0);
    move += merge(A, S, M, E+1);
    return move;
}

long merge(vector<int> &A, int S, int M, int E)
{
    vector<int> temp;
    int i = S;
    int j = M;
    int cnt = 0;
    long move = 0;
    while (i < M && j < E) {
        if (A[i] <= A[j]) {
            temp.push_back(A[i]);
            i++;
            move += cnt;
        }
        else {
            temp.push_back(A[j]);
            j++;
            cnt++;
        }
    }
    while (i < M) {
        temp.push_back(A[i]);
        i++;
        move += cnt;
    }
    while (j < E) {
        temp.push_back(A[j]);
        j++;
    }
    for (int k=S; k<E; k++) {
        A[k] = temp[k - S];
    }
    return move;
}

// 3트
// 방식은 맞았으나 결과값이 int 범위를 넘을 수 있다는 것을 몰랐음
// 출력 값을 long으로 바꾸어 해결