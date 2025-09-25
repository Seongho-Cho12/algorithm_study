#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, sum = 0;
    string nums;
    cin >> N;
    cin >> nums;
    for (int i=0; i<N; i++) {
        // cout << nums[i] << sum << "\n";
        sum += (nums[i] - 48);
    }
    cout << sum;
    return 0;
}
