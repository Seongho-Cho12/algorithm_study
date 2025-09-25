#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 2025.04.13

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, stack_input = 1, stack_out, temp;
    stack<int> stk;
    vector<char> res;
    cin >> N;
    stack_out = N + 1;
    for (int i=0; i<N; i++) {
        cin >> temp;
        stack_out = N + 1;
        while (stack_input <= temp) {
            stk.push(stack_input);
            stack_input++;
            res.push_back('+');
            // cout << "+\n";
        }
        while (!stk.empty() && stack_out > temp) {
            stack_out = stk.top();
            stk.pop();
            res.push_back('-');
            // cout << "-\n";
            // if (i == 4) {
            //     cout << "stack out: " << stack_out << '\n';
            //     cout << "temp: " << temp << '\n';
            //     bool wtf = stack_out > temp;
            //     cout << "boolean: " << wtf << '\n';
            //     break;
            // }
        }
        // stack<int> tempstack = stk;
        // while (!tempstack.empty()) {
        //     cout << tempstack.top() << " ";
        //     tempstack.pop();
        // }
        // cout << '\n';
        if (stack_out != temp) {
            cout << "NO";
            return 0;
        }
        // if (i == 4) {
        //     return 0;
        // }
    }
    for (char i : res) {
        cout << i << '\n';
    }
    return 0;
}

// 스택 이름을 처음에 stack으로 했는데 이걸로 뭔가 충돌나서 계속 타임아웃걸림
// 개념 자체는 처음부터 맞았던거같음
