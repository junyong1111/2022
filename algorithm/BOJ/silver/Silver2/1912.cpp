#include <iostream>
#include <vector>
#define MAX_SIZE -2100000000


using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);


    int size = 0;
    cin >> size ;
    int minMax = MAX_SIZE;
    vector<int>V(size, 0);
    bool check = false;
    for(int i=0; i<size; i++){
        int temp = 0;
        cin >> temp;
        if(temp>0)
            check = true;
        else{
            if(minMax<temp)
                minMax = temp;
        }
        V[i] = temp;
    }

    int sum = 0;
    int startIdx = 0;
    int endIdx = 0;
    int cnt = -1;
    int max = V[0];

    if(check == false){
        cout << minMax <<"\n";
    }
    else{
        for(int i=0; i<size; i++){
            sum += V[i];
            cnt ++; 
            if(sum<=0){
                sum = 0;
                cnt = -1;
            }
            else{
                if(max<=sum){
                    startIdx = i-cnt;
                    max = sum;
                    endIdx = i;
                }
            }
            
        }
        cout << max  <<"\n";
    }

    return 0;
}