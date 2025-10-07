#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &A, int S, int E, int K);
int partition(vector<int> &A, int S, int E);
void swap(vector<int> &A, int i, int j);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    quick_sort(A, 0, N-1, K-1);
    cout << A[K-1];
}

void quick_sort(vector<int> &A, int S, int E, int K) 
{
    int pivot = partition(A, S, E);
    if (pivot == K) return;
    else if (pivot < K) {
        quick_sort(A, pivot + 1, E, K);
    }
    else {
        quick_sort(A, S, pivot - 1, K);
    }
}

int partition(vector<int> &A, int S, int E)
{
    int M = (S + E) / 2;
    swap(A, S, M);
    int pivot = S;
    S++;
    while (S <= E) {
        while (A[pivot] < A[E] && E > 0) {
            E--;
        }
        while (A[pivot] > A[S] && S < A.size()) {
            S++;
        }
        if (S <= E) {
            swap(A, S++, E--);
        }
    }
    swap(A, pivot, E);
    return E;
}

void swap(vector<int> &A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 11004번 정답에서 틀린 부분 확인
// S의 범위를 정할 때 A.size()-1보다 작을 때로 while을 정하면
// pivot의 값이 모든 배열에서 가장 큰 경우 S와 E가 같은 상황 발생
// 이 경우 swap 후 E 값이 1 줄기 때문에 엉뚱한 값과 pivot 값을 서로 바꿈
// 이걸 막기 위해 A.size()보다 작은 경우로 바꾸면
// S가 배열 밖으로 나가므로 E보다 커서 S와 E의 스왑이 일어나지 않음
// 따라서 E값이 보존되어 pivot과 제대로 스왑 가능
// 이걸 제대로 이해하고 처음부터 다시 코딩해보았다.