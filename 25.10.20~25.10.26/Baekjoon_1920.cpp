// 2025.10.22
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> &A, int query, int S, int E);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, k;
    cin >> N;
    vector<int> org(N);
    for (int i=0; i<N; i++) {
        cin >> org[i];
    }
    sort(org.begin(), org.end());
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> k;
        cout << (int) binarySearch(org, k, 0, org.size()) << "\n";
    }
}

bool binarySearch(vector<int> &A, int query, int S, int E)
{
    int M = (S + E) / 2;
    if (S == M) return (query == A[M]);
    if (A[M] == query) return true;
    else if (A[M] < query) return binarySearch(A, query, M, E);
    else return binarySearch(A, query, S, M);
}

// 1트컷
// Binary Search 관련 부분이라 algorithm에 search가 존재해도 직접 구현함