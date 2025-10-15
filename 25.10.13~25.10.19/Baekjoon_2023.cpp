// 2025.10.15
#include <iostream>
#include <stack>
using namespace std;

void DFS(int val, int depth, int length);
bool isPrime(int val);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i : {2, 3, 5, 7}) {
        DFS(i, 1, N);
    }
}

void DFS(int val, int depth, int length)
{
    if (!isPrime(val)) return;
    if (depth == length) {
        cout << val << "\n";
        return;
    }
    val *= 10;
    depth++;
    for (int i : {1, 3, 5, 7, 9}) {
        DFS(val + i, depth, length);
    }
    return;
}

bool isPrime(int val)
{
    int k = val / 3;
    for (int i=3; i<=k; i+=2) {
        if (val % i == 0) return false;
    }
    return true;
}

// 1트컷