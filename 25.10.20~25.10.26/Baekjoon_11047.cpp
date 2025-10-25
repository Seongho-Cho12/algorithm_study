// 2025.10.25
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, a, cnt, sum = 0;
    stack<int> A;
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> a;
        A.push(a);
    }
    while (!A.empty() && K != 0) {
        a = A.top();
        A.pop();
        cnt = K / a;
        K = K % a;
        sum += cnt;
    }
    cout << sum;
}

// 1트컷
// 그리디 사용 성공