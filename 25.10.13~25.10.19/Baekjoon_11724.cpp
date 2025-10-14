// 2025.10.14
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    bool isChecked = false;
    stack<int> next;
};

bool graphSearch(vector<Node> &A, int i);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, u, v, cnt = 0;
    cin >> N >> M;
    vector<Node> A(N);
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        A[u-1].next.push(v-1);
        A[v-1].next.push(u-1);
    }
    for (int i=0; i<N; i++) {
        if (graphSearch(A, i)) {
            cnt++;
        }
    }
    cout << cnt;
}

bool graphSearch(vector<Node> &A, int i)
{
    if (A[i].isChecked) return false;
    A[i].isChecked = true;
    while (!A[i].next.empty()) {
        graphSearch(A, A[i].next.top());
        A[i].next.pop();
    }
    return true;
}

// 1트컷
// isChecked를 먼저 수정해야 무한 재귀에 걸리지 않는다. (gpt가 무한 재귀 가능성 알려줌, 어디서 무한 재귀인지 직접 찾음)
// struct 사용법을 적절히 익히자.