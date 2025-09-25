#include <iostream>
#include <vector>
using namespace std;

// 2025.04.11

int whichDNA(char a)
{
    if (a == 'A') {
        return 0;
    }
    else if (a == 'C') {
        return 1;
    }
    else if (a == 'G') {
        return 2;
    }
    else if (a == 'T') {
        return 3;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, res = 0;
    cin >> N >> M;
    vector<char> DNAs(N+1);
    vector<int> constraints(4);
    vector<int> window(4, 0);
    for (int i=0; i<N; i++) {
        cin >> DNAs[i];
    }
    DNAs[N] = 'A';
    for (int i=0; i<4; i++) {
        cin >> constraints[i];
    }
    for (int i=0; i<M; i++) {
        window[whichDNA(DNAs[i])] += 1;
    }
    for (int i=0; i<N-M+1; i++) {
        if (window[0] >= constraints[0] && window[1] >= constraints[1] && 
            window[2] >= constraints[2] && window[3] >= constraints[3])
        {
            res++;
        }
        window[whichDNA(DNAs[i])] -= 1;
        window[whichDNA(DNAs[i+M])] += 1;
    }
    cout << res;
    return 0;
}

// 1트컷
