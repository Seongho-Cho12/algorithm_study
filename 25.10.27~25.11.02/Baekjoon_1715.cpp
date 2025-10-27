// 2025.10.27
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N, temp, res = 0, a, b;
    cin >> N;
    priority_queue<long long, vector<long long>, greater<long long>> A;
    for (int i=0; i<N; i++) {
        cin >> temp;
        A.push(temp);
    }
    while (A.size() != 1) {
        a = A.top();
        A.pop();
        b = A.top();
        A.pop();
        temp = a + b;
        A.push(temp);
        res += temp;
    }
    cout << res;
}

// 처음 방식을 잘못 정함
// 새로 만들어진 그룹도 크기 비교해서 다시 확인하기
// priority queue 사용
// 오름차순 정렬 방식 검색