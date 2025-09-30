#include <iostream>
#include <vector>
using namespace std;

// 2025.09.30
void bubble_sort(vector<int> original, int N)
{
    int temp;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N-i-1; j++) {
            if (original[j] > original[j+1]) {
                temp = original[j];
                original[j] = original[j+1];
                original[j+1] = temp;
            }
        }
    }
    for (int i=0; i<N; i++){
        cout << original[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> original(N);
    for (int i=0; i<N; i++) {
        cin >> original[i];
    }
    bubble_sort(original, N);
}

// 1트컷
// Bubble Sort: 바로 인접한 수들끼리만 비교해서 스왑, O(N^2), 비효율적
// 그냥 algorithm 임포트하고 sort 쓰면 되는건데 한번 구현해보기