#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int L,P,V;
    cin >> L >> P >> V;
    
    /*
    캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있다. 강산이는 이제 막 V일짜리 휴가를 시작했다. 강산이가 캠핑장을 최대 며칠동안 사용할 수 있을까? (1 < L < P < V)
    */
   int cnt = 1;
    while(1){
        if(L==0 && P==0 && V==0)
            break;
        int answer = 0;

        while(V>P){
            V = V-P; 
            answer = answer + L; 
        }
        if(V>=L){
            answer = answer + L;
        }
        else{
            answer = answer + V;
        }
        cout << "Case " << cnt++ << ":" << " " <<answer <<"\n";
        cin >> L >> P >> V;
    }

    return 0;
}