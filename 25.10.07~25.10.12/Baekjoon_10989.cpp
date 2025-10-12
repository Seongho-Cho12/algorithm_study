// 2025.10.12
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

void radixSort(vector<int> &A);
void countingSort(vector<int> &A);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, val, idx = 0;
    cin >> N;
    vector<int> A(10001, 0);
    for (int i=0; i<N; i++) {
        cin >> val;
        A[val]++;
    }
    for (int i=0; i<N; i++) {
        while (A[idx] == 0) {
            idx++;
        }
        A[idx]--;
        cout << idx << "\n";
    }
}

void radixSort(vector<int> &A)
{
    vector<queue<int>> Q(10);
    vector<int> temp;
    int base = 1;
    int val;
    for (int k=0; k<5; k++) {
        for (int i=0; i<A.size(); i++) {
            val = A[i] / base % 10;
            Q[val].push(A[i]);
        }
        for (int i=0; i<10; i++) {
            while (!Q[i].empty()) {
                temp.push_back(Q[i].front());
                Q[i].pop();
            }
        }
        A = move(temp);
        temp = {};
        base *= 10;
    }
}

void countingSort(vector<int> &A)
{
    vector<int> Q(10001, 0);
    for (int i : A) {
        Q[i]++;
    }
    int idx = 0;
    for (int i=0; i<A.size(); i++) {
        while (Q[idx] == 0) {
            idx++;
        }
        Q[idx]--;
        A[i] = idx;
    }
}

// radix sort 내용이라 구현하면 될 줄 알았는데 메모리가 매우 작음
// 시간도 짧아서 O(N)으로 구현하는 문제
// counting sort를 구현했으나 이것 역시 메모리가 부족함
// 함수를 사용하지 않고 바로 데이터를 받을 때부터 처리하도록 하여 해결