#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N,M =0;
    cin >> N >> M;
    vector<int>V(N+1,0);
    for(int i=1; i<=N; i++){
        int temp = 0;
        cin >> temp ;
        V[i] = V[i-1]+temp; //이전값과 함께 저장 
    }

    for(int i=0; i<M; i++){
        int A, B;
        cin >> A >> B;
        cout << V[B]-V[A-1] <<"\n";
    }
    
    return 0;
}
