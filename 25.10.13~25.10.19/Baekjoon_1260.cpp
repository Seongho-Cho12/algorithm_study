// 2025.10.17
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    bool DFSChecked = false;
    bool BFSChecked = false;
    vector<bool> next;
};

void DFS(vector<Node> &A, int V, vector<int> &res);
void BFS(vector<Node> &A, queue<int> &Q, vector<int> &res);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, V, a, b;
    cin >> N >> M >> V;
    vector<Node> A(N);
    for (Node &n : A) {
        n.next.resize(N, false);
    }
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        A[a-1].next[b-1] = true;
        A[b-1].next[a-1] = true;
    }
    vector<int> DFSres;
    vector<int> BFSres;
    queue<int> Q;
    Q.push(V-1);
    DFS(A, V-1, DFSres);
    BFS(A, Q, BFSres);
    for (int i : DFSres) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i : BFSres) {
        cout << i << " ";
    }
}

void DFS(vector<Node> &A, int V, vector<int> &res)
{
    if (A[V].DFSChecked) {
        return;
    }
    res.push_back(V+1);
    A[V].DFSChecked = true;
    int N = A[V].next.size();
    for (int i=0; i<N; i++) {
        if (A[V].next[i]) {
            DFS(A, i, res);
        }
    }
}

void BFS(vector<Node> &A, queue<int> &Q, vector<int> &res)
{
    if (Q.empty()) {
        return;
    }
    int V = Q.front();
    Q.pop();
    if (A[V].BFSChecked) {
        BFS(A, Q, res);
        return;
    }
    res.push_back(V+1);
    A[V].BFSChecked = true;
    int N = A[V].next.size();
    for (int i=0; i<N; i++) {
        if (A[V].next[i]) {
            Q.push(i);
        }
    }
    BFS(A, Q, res);
}

// A의 요소를 모두 훑는 for문에서 n을 지정하면 복사 형태로 들어감
// 참조를 해야 실제 노드의 값들을 수정함 (gpt 도움)
// queue의 back은 방금 넣은 부분, front가 곧 나올 부분 (검색)
// BFSChecked인 경우 BFS를 계속 진행하도록 함수를 실행 후 return해야 함 (오류 통해 알아냄)