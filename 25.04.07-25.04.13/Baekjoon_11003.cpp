#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;

// 2025.04.12

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L, res;
    cin >> N >> L;
    vector<int> original(N);
    deque<int> window;
    for (int i=0; i<N; i++) {
        cin >> original[i];
    }
    for (int i=0; i<N; i++) {
        while (!window.empty() && original[window.back()] >= original[i]) {
            window.pop_back();
        }
        window.push_back(i);
        if (window.front() == i - L) {
            window.pop_front();
        }
        res = original[window.front()];
        cout << res << " ";
    }
    return 0;
}

// 예전코드
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int N, L, res;
//     cin >> N >> L;
//     vector<int> original(N);
//     multiset<int> window;
//     for (int i=0; i<N; i++) {
//         cin >> original[i];
//     }
//     for (int i=0; i<L; i++) {
//         window.insert(original[i]);
//         res = *window.begin();
//         cout << res << " ";
//     }
//     for (int i=L; i<N; i++) {
//         window.insert(original[i]);
//         auto it = window.find(original[i-L]);
//         window.erase(it);
//         res = *window.begin();
//         cout << res << " ";
//     }
//     return 0;
// }

// 처음 아이디어:
// 숫자를 자동 정렬되는 set에 넣어서 push pop 하면
// 각각 비용은 log만큼 드니까
// 값을 하나씩 넣고 빼서 그 set의 가장 작은 값 구하기
// set는 총 N개, set의 최대 크기는 L
// 따라서 대략 NlogL에 계산 가능할 것으로 보임
// set 사용법을 잘 몰라서 gpt 찬스
// 찾아보니 multiset이 중복을 허용해서 이거 사용
// 타임아웃 걸림

// 세그먼트 트리 생각해봤는데 딱히 위 방식보다 좋지도 않고
// 세그먼트 트리 구현도 귀찮고 공부해야되고 해서
// 솔직히 아직 트리 구조 책에 나오지도 않아서 진짜 아닌거 같기도 하고

// 그래서 결국 굴복해버림
// gpt가 알려준 deque방식
// 예시 4 2 1 5 2 6, L = 3
// 0
// 1
// 2
// 2, 3
// 2, 4
// 4, 5
// 새로운 값을 뒤에 넣기
// 만약 넣는 숫자가 뒤 숫자보다 작으면 넣는 숫자보다 작은 숫자가 나오기 전까지 pop
// 만약 맨 앞의 숫자가 윈도우를 벗어나면 맨 앞 숫자 pop 하고 가장 앞 숫자 읽기
