#include <iostream>

using namespace std;

int masses[7]  = {100,50,20,10,5,2,1};


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int testCase= 0;
    cin >> testCase;

    
    while(testCase--){
        int size = 0;
        cin >> size;
        int *arr = new int[size];
        for(int i=0; i<size; i++)
            cin >> arr[i];
        int stack1 = arr[0];
        int stack2 = arr[1];

        for(int i=2; i<size; i++){
            if(stack1 == stack2){
                stack1+= arr[i];
            }
            else if(stack1 < stack2){
                stack1 += arr[i];
            }
            else{
                stack2+= arr[i];
            }
        
        }
        int diff = stack1-stack2;
        if(diff<0)
            diff = diff *-1;
        int answer = 0;
        if(diff ==0){
            cout << 0 <<"\n";
        }
        else{
            for(int i=0; i<7; i++){
            answer += diff/masses[i];
            diff = diff%masses[i];
        }
        cout << answer << endl;
        }
       
    
    }
    return 0;
    
}
