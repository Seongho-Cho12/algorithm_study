// 2025.10.31
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int res, a;
    char buho;
    bool isAfterMinus = false;
    cin >> res;
    while (cin >> buho) {
        cin >> a;
        if (isAfterMinus) {
            res -= a;
        }
        else {
            if (buho == '-') {
                isAfterMinus = true;
                res -= a;
            }
            else {
                res += a;
            }
        }
    }
    cout << res;
}

// 1트컷
// cin으로 받아올 것이 없는 경우 그 자체로 false가 나옴