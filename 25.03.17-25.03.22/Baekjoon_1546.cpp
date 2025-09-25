#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, temp, max = 0, sum = 0;
    float res;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> temp;
        if (temp > max) {
            max = temp;
        }
        sum += temp;
    }
    res = (float)sum * 100 / (max * N);
    cout << res;
    return 0;
}
