// 2025.10.18
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int row;
    int column;
    int cnt;
};

int routeFind(vector<vector<int>> &A, queue<Node> &Q);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N);
    for (int i=0; i<N; i++) {
        cin >> a;
        for (int j=0; j<M; j++) {
            A[i].push_back(a[j] - '0');
        }
    }
    queue<Node> Q;
    Node n;
    n.row = 0;
    n.column = 0;
    n.cnt = 1;
    Q.push(n);
    cout << routeFind(A, Q);
}

int routeFind(vector<vector<int>> &A, queue<Node> &Q)
{
    Node n;
    n = Q.front();
    Q.pop();
    if (n.row < 0 || n.row >= A.size() || n.column < 0 || n.column >= A[0].size()) {
        return routeFind(A, Q);
    }
    else if (A[n.row][n.column] == 0) {
        return routeFind(A, Q);
    }
    else if (n.row == A.size() - 1 && n.column == A[0].size() - 1) {
        return n.cnt;
    }
    A[n.row][n.column] = 0;
    Node left = {n.row, n.column - 1, n.cnt + 1};
    Node right = {n.row, n.column + 1, n.cnt + 1};
    Node up = {n.row - 1, n.column, n.cnt + 1};
    Node down = {n.row + 1, n.column, n.cnt + 1};
    Q.push(left);
    Q.push(right);
    Q.push(up);
    Q.push(down);
    return routeFind(A, Q);
}

// 1트컷