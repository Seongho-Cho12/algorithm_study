#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2025.10.02
bool compare(int a, int b) {
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s;
    vector<int> vec;
    cin >> s;
    while (s != 0) {
        vec.push_back(s % 10);
        s /= 10;
    }
    sort(vec.begin(), vec.end(), compare);
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i];
    }
}

// 1트컷