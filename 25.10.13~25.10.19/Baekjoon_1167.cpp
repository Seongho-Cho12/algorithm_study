// 2025.10.19
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    bool isChecked = false;
    vector<int> next;
    vector<int> dist;
};

struct QueueVal
{
    int V;
    int dist;
};

struct Compare
{
    bool operator()(const QueueVal &a, const QueueVal &b) {
        return a.dist > b.dist;
    }
};

int deepest_depth(vector<Node> &A, priority_queue<QueueVal, vector<QueueVal>, Compare> &pq, bool justCheck);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, a, b, distance, startnode, res = 0;
    priority_queue<QueueVal, vector<QueueVal>, Compare> pq;
    cin >> V;
    vector<Node> A(V), A_copy(V);
    for (int i=0; i<V; i++) {
        cin >> a >> b;
        while (b != -1) {
            cin >> distance;
            A[a-1].next.push_back(b-1);
            A[a-1].dist.push_back(distance);
            cin >> b;
        }
    }
    A_copy = A;
    QueueVal v {0, 0};
    pq.push(v);
    startnode = deepest_depth(A_copy, pq, true);
    v = {startnode, 0};
    pq.push(v);
    res = deepest_depth(A, pq, false);
    cout << res;
}

int deepest_depth(vector<Node> &A, priority_queue<QueueVal, vector<QueueVal>, Compare> &pq, bool justCheck)
{
    int V = pq.top().V;
    int dist = pq.top().dist;
    pq.pop();
    A[V].isChecked = true;
    int N = A[V].next.size();
    for (int i=0; i<N; i++) {
        if (!A[A[V].next[i]].isChecked){
            QueueVal qv {A[V].next[i], dist + A[V].dist[i]};
            pq.push(qv);
        }
    }
    if (pq.empty()) {
        if (justCheck) return V;
        return dist;
    }
    return deepest_depth(A, pq, justCheck);
}

// 2트컷
// 첫 번째 시도에서 모든 leaf 노드에 대해 가장 긴 거리를 측정함
// 하지만 가장 중요한 아이디어인
// "임의의 노드에서 가장 긴 경로로 연결된 노드는 트리의 지름에 해당하는 두 노드 중 하나다"
// 를 알고 있어야만 시간초과가 나지 않음
// 이해하는 법: 가장 긴 거리의 노드끼리 잡고 양쪽으로 늘리면
// 어느 노드에서 시작하더라도 가장 멀리 있는 노드는
// 양쪽 두 노드 중 하나가 된다.