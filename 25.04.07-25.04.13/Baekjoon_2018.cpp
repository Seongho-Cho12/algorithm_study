#include <iostream>
#include <vector>
using namespace std;

// 2025.04.09
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, sum, fst = 0, snd = 1, res = 1;
    cin >> N;
    if (N < 3) {
        cout << res;
        return 0;
    }
    int halfN = N/2 + 2;
    vector<int> vec(halfN);
    vec[0] = 0;
    for (int i=1; i<halfN; i++) {
        vec[i] = vec[i-1] + i;
    }
    while (snd < halfN) {
        sum = vec[snd] - vec[fst];
        if (sum == N) {
            res++;
            fst++;
        }
        else if (sum > N) {
            fst++;
        }
        else {
            snd++;
        }
    }
    cout << res;
    return 0;
}

// 문제 상황: 메모리 부족
// 모든 부분합을 저장할 필요 없다는 걸 생각해서 루트 계산을 찾아와 넣으려다가
// 그러면 안된다는걸 깨달아버림
// N의 절반 근처에서 두 값을 더하는것 이상으로 계산하면 어짜피 자기자신밖에 없다로 틀음
// 그리고 다 더해봤자 int 범위도 넘지 않는다는 걸 확인해버림 -> long long을 int로 수정
// 그래서 적절한 값인 halfN을 정했는데 그러면 N이 3보다 작은 경우는 값이 너무 커지는 상황
// 그럼 하드코딩하면 되잖아?????
// 그렇게 성공
