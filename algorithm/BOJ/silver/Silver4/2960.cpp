#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int N = 0;
    int K = 0;
    cin >> N >> K;
    vector<int>V(N+1, 0);
    
    int answer = 0;
    int count = 0;

    for(int i=2; i<=N; i++){
        if(V[i]==0){
            for(int j=i; j<=N; j= j+i){
                if(V[j] ==0){
                    V[j] =1;
                    count ++;
                    if(count == K){
                        answer = j;
                        break;
                    }
                }
            }
        }
    }

    cout << answer << " ";
    
    return 0;
}