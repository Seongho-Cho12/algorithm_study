#include <iostream>
#include <queue>
using namespace std;

// 2025.09.28

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) != abs(b)) {
            // b가 앞에, a가 뒤에 들어온다고 이해하기
            // 이 문제에서는 절댓값이 작은 값이 앞에 들어와야 함
            return abs(a) > abs(b);
        }
        else {
            // 이 문제에서는 같은 절댓값인 경우 음수가 앞에 들어와야 함
            return a > b;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue <int, vector<int>, cmp> pq;
    int N, input;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> input;
        if (input == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(input);
        }
    }
}

// priority queue를 사용하는 문제
// 1트컷
// 해당 링크 참고: https://jungeu1509.github.io/algorithm/use-priorityqueue/