#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>ONE(1000001,0);

int makeOne(int N){
    if(N<=3)
        return ONE[N];
    else{
        if(N%3==0){
            if(ONE[N]==0){ // 처음 계산되는 상황
                if(N%2==0){
                    int min = makeOne(N/3)<makeOne(N/2)?ONE[N/3]:ONE[N/2];
                    ONE[N] = min<makeOne(N-1)?(min+1):(1+ONE[N-1]);
                    return ONE[N];
                }//2로 나눠지는경우
                else{
                    ONE[N] = makeOne(N/3)<makeOne(N-1)?(1+ONE[N/3]):(1+ONE[N-1]);
                    return ONE[N];
                }//3으로만 나눠지는경우
            }
            else
                return ONE[N]; 
    }//3으로 나눠지는 경우
        if(N%2==0){
            if(ONE[N]==0){
            ONE[N] = makeOne(N/2)<makeOne(N-1)?(1+ONE[N/2]):(1+ONE[N-1]);
            return ONE[N];
            }
            else
                return ONE[N];
        } //2로 나눠지는 경우
        else{
            if(ONE[N]==0){ // 둘 다 아닌경우
                ONE[N] = 1+makeOne(N-1); 
                return ONE[N];
            }
            else
                return ONE[N];
        }
}//else
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    ONE[0] = 0;
    ONE[1] = 0;
    ONE[2] = 1;
    ONE[3] = 1;
    int N = 0;
    cin >> N ;
    int ans = makeOne(N);
    cout << ans << "\n";
    return 0;
}