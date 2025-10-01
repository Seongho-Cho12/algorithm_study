#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

// 2025.10.01
bool compare(tuple<int, int> a, tuple<int, int> b) {
    if (get<0>(a) == get<0>(b)) {
        return get<1>(a) < get<1>(b);
    }
    else {
        return get<0>(a) < get<0>(b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, temp, max = 0;
    cin >> N;
    vector<tuple<int, int>> vec(N);
    for (int i=0; i<N; i++) {
        cin >> temp;
        vec[i] = make_tuple(temp, i);
    }
    sort(vec.begin(), vec.end(), compare);
    for (int i=0; i<N; i++) {
        if (max < get<1>(vec[i]) - i) {
            max = get<1>(vec[i]) - i;
        }
    }
    cout << max + 1;
}

// 2트클
// bubble sort는 너무 오래 걸리는 문제
// quick sort와 vector 안 tuple로 해결
// compare 함수로 sort 지침 생성
