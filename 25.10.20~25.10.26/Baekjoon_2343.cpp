// 2025.10.23
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &A, int M, int l, int r);
bool canMakeBR(vector<int> &A, int M, int size);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, l = 0, r = 0, res;
    cin >> N >> M;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
        r += A[i];
        if (A[i] > l) {
            l = A[i];
        }
    }
    // cout << l << " " << r;
    res = binarySearch(A, M, l, r);
    cout << res;
}

int binarySearch(vector<int> &A, int M, int l, int r)
{
    if (r - l == 1) {
        if (canMakeBR(A, M, l)) {
            return l;
        }
        else return r;
    }
    int mid = (l + r) / 2;
    if (canMakeBR(A, M, mid)) {
        return binarySearch(A, M, l, mid);
    }
    else {
        return binarySearch(A, M, mid, r);
    }
}

bool canMakeBR(vector<int> &A, int M, int size)
{
    int cnt = 1;
    int temp = 0;
    for (int i : A) {
        if (size - temp >= i) {
            temp += i;
        }
        else {
            cnt++;
            temp = i;
        }
    }
    if (cnt > M) {
        return false;
    }
    else return true;
}

// 1트컷
// 아이디어가 전혀 떠오르지 않아서
// 책에 나온 아이디어 사용
// 모든 레슨을 계속 탐색하는 건 불가피하지만
// 레슨 최대값을 binary search하듯 확인할 수 있음