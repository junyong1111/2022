#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N = 0;
    cin >> N;
    vector<int>V(N,0);
    for(int i=0; i<N; i++){
        cin >> V[i]; 
    }

    vector<int>Sorted_V;
    Sorted_V = V;
    sort(Sorted_V.begin(), Sorted_V.end()); // 이진탐색을 위해 정렬
    Sorted_V.erase(unique(Sorted_V.begin(), Sorted_V.end()), Sorted_V.end()); // 중복값 제거 

    for(int i=0; i<N; i++){
        int compare = V[i];
        cout <<  lower_bound(Sorted_V.begin(), Sorted_V.end(), compare) - Sorted_V.begin() << " ";
        // lower_bound는 찾는값이 가장 먼저 나온 인덱스값을 반환해준다.
    }
    return 0;
}