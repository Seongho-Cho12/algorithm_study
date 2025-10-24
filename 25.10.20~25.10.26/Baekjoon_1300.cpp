// 2025.10.24
#include <iostream>
using namespace std;

int binarySearch(int N, int k, int S, int E);
bool isBigEnough(int N, int k, int target);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, k;
    cin >> N >> k;
    cout << binarySearch(N, k, 1, k);
}

int binarySearch(int N, int k, int S, int E)
{
    if (E == S) return 1;
    if (E - S == 1) {
        if (isBigEnough(N, k, S)) {
            return S;
        }
        else return E;
    }
    int mid = (S + E) / 2;
    if (isBigEnough(N, k, mid)) {
        return binarySearch(N, k, S, mid);
    }
    else return binarySearch(N, k, mid, E);
}

bool isBigEnough(int N, int k, int target)
{
    int cnt = 0;
    int repeat;
    if (target > N) repeat = N;
    else repeat = target;
    for (int i=1; i<=repeat; i++) {
        if (target / i < N) cnt += (target / i);
        else cnt += N;
    }
    return cnt >= k;
}

// 책 아이디어 참고
// k번째 값은 항상 k보다 작거나 같다
// 각 행(i)에서 특정 값(j)보다 작거나 같은 수의 개수는 j / i
// 각 행은 각 행의 맨 앞 값에 1~N까지 곱한 값이므로
// 특정 값을 해당 행 번호로 나누면 특정 값보다 작거나 같은 수의 개수를 알 수 있음
// 한 행 당 최대 N개까지만 확인해야 하는 문제와
// 첫 번째 값을 찾을 때 생기는 문제가 발생하여 각각
// N과 나눈 값의 비교와
// 1인 경우 따로 고려로 해결