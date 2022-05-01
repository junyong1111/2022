#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    
    while(true)
    {
        vector<int>ans(3,0);
        for(int i=0; i<3; i++){
            cin >> ans[i];
        }
        sort(ans.begin(), ans.end());
        int a = ans[0];
        int b = ans[1];
        int c = ans[2];
        if(a==0 && b==0 &&c==0){
            break;
        }
        else
        {
        int sum =  pow(a,2) + pow(b,2);
        if(sum-(pow(c,2)) == 0){
            cout <<"right"<<"\n";
        }
        else{
            cout <<"wrong\n";
        }
        }

    }
    
    return 0;
}