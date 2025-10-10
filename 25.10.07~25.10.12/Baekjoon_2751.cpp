// 2025.10.10
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &A, int S, int E);
void mergeTwoGroups(vector<int> &A, int S, int M, int E);

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
    mergeSort(A, 0, N-1);
    for (int i=0; i<N; i++) {
        cout << A[i] << "\n";
    }
}

void mergeSort(vector<int> &A, int S, int E)
{
    if (S == E) return;
    int M = (S + E) / 2 + 1;
    mergeSort(A, S, M-1);
    mergeSort(A, M, E);
    mergeTwoGroups(A, S, M, E+1);
}

void mergeTwoGroups(vector<int> &A, int S, int M, int E)
{
    vector<int> temp;
    int i = S;
    int j = M;
    while (i < M && j < E) {
        if (A[i] < A[j]) {
            temp.push_back(A[i]);
            i++;
        }
        else {
            temp.push_back(A[j]);
            j++;
        }
    }
    if (i == M) {
        for (int k=j; k<E; k++) {
            temp.push_back(A[k]);
        }
    }
    else {
        for (int k=i; k<M; k++) {
            temp.push_back(A[k]);
        }
    }
    for (int k=S; k<E; k++) {
        A[k] = temp[k-S];
    }
}

// 1트컷
// quicksort의 경험을 토대로 아주 깔끔한 코딩 완료