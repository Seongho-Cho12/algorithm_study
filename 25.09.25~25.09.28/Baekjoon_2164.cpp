#include <iostream>
#include <queue>
using namespace std;

// 2025.09.27
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, ans;
    queue<int> q;
    cin >> N;
    for (int i=1; i<=N; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        ans = q.front();
        q.pop();
        if (q.empty()) {
            break;
        }
        ans = q.front();
        q.pop();
        q.push(ans);
    }
    cout << ans;
}

// queue를 쓰기만 하면 풀려서 쉬운 문제
// 꼼수로 N보다 작으며 가장 큰 2의 제곱수로 풀려다가
// 홀수인 경우 해당 방법으로 계산 시 답이 틀리다는 것을 확인
// 그냥 정석적으로 푸니까 바로 해결