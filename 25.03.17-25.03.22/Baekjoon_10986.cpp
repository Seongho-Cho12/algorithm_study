#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, temp, cnt;
    long long res = 0;
    cin >> N >> M;
    vector<int> rems(N+1);
    rems[0] = 0;
    for (int i=1; i<N+1; i++) {
        cin >> temp;
        rems[i] = (rems[i-1] + temp) % M;
    }
    for (int i=0; i<M; i++) {
        cnt = count(rems.begin(), rems.end(), i);
        res += (long long) cnt * (cnt - 1) / 2;
    }
    cout << res;
    return 0;
}

// 이건 몇번 틀리고 나서 맞음
// 첫번째 틀렸을땐 0이 반복해서 나오면 0끼리의 합은 어떤 수로 나누어 떨어진다고 표현하는게 틀렸다고 생각
// 0이 반복해서 나오는 경우를 제외해도 그대로 틀림
// 백준 질문 게시판 보니 overflow 문제 확인
// 0 반복 삭제 코드에 long long 사용해도 실패
// gpt한테 0은 모든 수로 나누어 떨어지는지 물어봄 -> 나누어 떨어진다고 표현하는게 맞다고함
// 원래 코드에서 res만 long long으로 바꿔서 다시 제출, 실패
// 생각해보니 cnt가 int인데 cnt끼리 곱한 값은 int 범위를 넘을 수 있음
// res에 더해줄 테니 어짜피 형변환돼서 상관없을 줄 알았는데 곱한 직후에는 형변환이 이루어지지 않고,
// 계산한 결과가 형변환되어 res에 더해지는 상황임
// 계산 전에 cnt를 long long으로 형변환하도록 바꿨더니 성공
