// 2025.10.16
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Person
{
    bool isChecked = false;
    vector<int> friends;
};

bool checkFriends(int idx, int chain, vector<Person> &A);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, a, b;
    cin >> N >> M;
    vector<Person> A(N);
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        A[a].friends.push_back(b);
        A[b].friends.push_back(a);
    }
    for (int i=0; i<N; i++) {
        if (checkFriends(i, 5, A)) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}

bool checkFriends(int idx, int chain, vector<Person> &A)
{
    if (chain == 1) return true;
    A[idx].isChecked = true;
    for (int i : A[idx].friends) {
        if (!A[i].isChecked && checkFriends(i, chain - 1, A)) {
            return true;
        }
    }
    A[idx].isChecked = false;
    return false;
}

// 1트컷
// Person의 포인터를 이용한 구현을 시도하다가
// stack에서 각 요소를 제거하며 search를 진행하면
// 이후 다른 노드부터 찾을 때 복구 불가능하므로
// 그냥 벡터 & 인덱스 값으로 진행