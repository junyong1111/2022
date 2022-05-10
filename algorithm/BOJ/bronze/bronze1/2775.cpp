#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        
        int Num = 1;
        int K, N;
        cin >> K >> N;
        vector<int>ans(N,0);
        for(int i=0; i<N; i++)
            ans[i] = i+1; //제일 아랫층 셋팅 
        for(int i=1; i<=K; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(j==1){continue;} // 각 층의 1호사람들은 1명으로 고정
                else{
                    ans[j-1]+= ans[j-2]; //그게 아니라면 자신부터 그 전층의 사람까지 모두 더해준다
                }
            }
        }
        cout << ans[N-1]<<"\n"; 
    }
    return 0;
}