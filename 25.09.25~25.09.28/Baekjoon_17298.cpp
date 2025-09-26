#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 2025.09.26
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, input;
    cin >> N;
    vector<int> arr(N);
    vector<int> res(N, -1);
    stack<int> stk;
    for (int i=0; i<N; i++) {
        cin >> input;
        arr[i] = input;
        while (!stk.empty() && arr[stk.top()] < input) {
            res[stk.top()] = input;
            stk.pop();
        }
        stk.push(i);
    }
    for (int i=0; i<N; i++) {
        cout << res[i] << ' ';
    }
}

// 1트컷