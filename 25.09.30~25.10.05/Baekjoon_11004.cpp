#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 2025.10.05
// void quick_sort(vector<int>& vec, int start, int end, int pivot)
// {
//     int temp;
//     if (start == end) {
//         if (vec[pivot] < vec[start]) {
//             temp = vec[pivot];
//             vec[pivot] = vec[start];
//             vec[start] = temp;
//         }
//         return;
//     }
//     int prev_start = start;
//     int prev_end = end;
//     while (start < end) {
//         if (vec[start] > vec[pivot] && vec[end] <= vec[pivot]) {
//             temp = vec[start];
//             vec[start] = vec[end];
//             vec[end] = temp;
//         }
//         if (vec[start] <= vec[pivot]) {
//             start++;
//         }
//         if (vec[end] > vec[pivot]) {
//             end--;
//         }
//     }
//     if (vec[end] > vec[pivot]) {
//         temp = vec[end];
//         vec[end] = vec[pivot];
//         vec[pivot] = temp;
//     }
//     else {
//         temp = vec[end+1];
//         vec[end+1] = vec[pivot];
//         vec[pivot] = temp;
//     }

//     if (end > prev_start + 1) {
//         quick_sort(vec, prev_start, end - 2, end - 1);
//     }
//     if (end < prev_end) {
//         quick_sort(vec, end + 1, prev_end, pivot);
//     }
// }

// int find_answer(vector<int>& vec, int start, int end, int pivot, int K)
// {
//     int temp;
//     int prev_start = start;
//     int prev_end = end;
//     // for (int i=start; i<=end; i++) {
//     //     cout << vec[i] << " ";
//     // }
//     // cout << "\n";
//     temp = vec[pivot];
//     vec[pivot] = vec[(start + end) / 2];
//     vec[(start + end) / 2] = temp;
//     while (start < end) {
//         while (vec[start] <= vec[pivot] && start < vec.size() - 1) {
//             start++;
//         }
//         while (vec[end] > vec[pivot] && end > 0) {
//             end--;
//         }
//         if (start < end) {
//             temp = vec[start];
//             vec[start] = vec[end];
//             vec[end] = temp;
//         }
//     }
//     if (vec[end] <= vec[pivot]) {
//         end++;
//     }
//     // cout << "pivot: " << vec[pivot] << "\n";
//     // cout << "target: " << vec[end] << "\n";
//     temp = vec[end];
//     vec[end] = vec[pivot];
//     vec[pivot] = temp;
//     if (end == K-1) {
//         return vec[end];
//     }
//     else if (end > K-1) {
//         if (end > prev_start + 1) {
//             return find_answer(vec, prev_start, end - 2, end - 1, K);
//         }
//         else {
//             return vec[end-1];
//         }
//     }
//     else {
//         if (end < prev_end) {
//             return find_answer(vec, end + 1, prev_end, pivot, K);
//         }
//         else {
//             return vec[end+1];
//         }
//     }
// }

// int partition(vector<int> &vec, int start, int end)
// {
//     int temp;
//     if (start + 1 == end) {
//         if (vec[start] > vec[end]){
//             temp = vec[start];
//             vec[start] = vec[end];
//             vec[end] = temp;
//         }
//         return end;
//     }
//     int mid = (start + end) / 2;
//     temp = vec[mid];
//     vec[mid] = vec[end];
//     vec[end] = temp;
//     int pivot = end;
//     end--;
//     while (start <= end) {
//         while (vec[pivot] < vec[end] && end > 0) {
//             end--;
//         }
//         while (vec[pivot] > vec[start] && start < vec.size() - 1) {
//             start++;
//         }
//         if (start <= end) {
//             temp = vec[start];
//             vec[start] = vec[end];
//             vec[end] = temp;
//             start++;
//             end--;
//         }
//     }
//     temp = vec[start];
//     vec[start] = vec[pivot];
//     vec[pivot] = temp;
//     return start;
// }

// int find_answer_new(vector<int>& vec, int start, int end, int K)
// {
//     if (start == end) return vec[start];
//     int pivot = partition(vec, start, end);
//     if (pivot == K) return vec[pivot];
//     else if (pivot < K) return find_answer_new(vec, pivot+1, end, K);
//     else return find_answer_new(vec, start, pivot-1, K);
// }

void quickSort(vector<int> &A, int S, int E, int K);
int partition(vector<int> &A, int S, int E);
void swap(vector<int> &A, int i, int j);

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // int N, K, answer;
    // cin >> N >> K;
    // vector<int> vec(N);
    // for (int i=0; i<N; i++) {
    //     cin >> vec[i];
    // }
    // answer = find_answer(vec, 0, N-2, N-1, K);
    // // answer = find_answer_new(vec, 0, N-1, K-1);
    // cout << answer;
    // // sort(vec.begin(), vec.end());
    // // cout << vec[K-1];

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    quickSort(A, 0, N-1, K-1);
    cout << A[K-1];
}

void quickSort(vector<int> &A, int S, int E, int K) {
    int pivot = partition(A, S, E);
    if (pivot == K) {
        return;
    }
    else if (K < pivot) {
        quickSort(A, S, pivot-1, K);
    }
    else {
        quickSort(A, pivot+1, E, K);
    }
}

int partition(vector<int> &A, int S, int E) {
    if (S + 1 == E) {
        if (A[S] > A[E]) {
            swap(A, S, E);
        }
        return E;
    }

    int M = (S + E) / 2;
    swap(A, S, M);
    int pivot = A[S];
    // cout << pivot << "\n";
    int i = S+1, j = E;

    while (i <= j) {
        while (pivot < A[j] && j > 0) {
            j--;
        }
        while (pivot > A[i] && i < A.size()) {
            i++;
        }
        if (i <= j) {
            swap(A, i++, j--);
        }
        // cout << i << " " << j << "\n";
    }
    
    A[S] = A[j];
    A[j] = pivot;
    return j;
}

void swap(vector<int> &A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 여러번 시도
// quick sort: 기준값을 선정해 해당 값보다 작은 값과 큰 값으로 분류
// sort를 쓰면 너무 쉬운 문제라 직접 재귀함수로 구현
// 문제를 다시 읽어보니 정렬을 구현할 필요 없이 quick sort의 아이디어만 구현하면 된다고 이해
// 직접 구현했으나 연달아 타임아웃으로 실패
// 교재 코드 그대로 넣어서 성공
// 하지만 교재 코드도 틀리는 케이스 존재
// input :
// 5 2
// 4 2 5 3 1
// output : 2
// 교재 코드를 수정해보자