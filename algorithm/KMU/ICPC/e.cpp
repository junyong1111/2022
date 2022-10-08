#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r" , stdin);

    int number = 0;
    int budget = 0;
    int sales = 0;

    cin >> number >> budget >> sales;

    vector<int>V(number, 0);
    for(int i=0; i<number; i++)
        cin >> V[i];
    
    sort(V.begin(), V.end());

    for(int i=0; i<number; i++)
        cout << V[i] << " ";
    cout << "\n";
    int temp = 0;
    int cnt = 0;
    int sum = 0;
    for(int i=0; i<number; i++){
        temp = budget - V[i];
        if(temp>=0){
            cnt ++;
            budget = budget-V[i];
        }
        else{
            if(budget - V[i]/2 >=0){
                budget = budget -V[i]/2;
                cnt++;
            }
            else{
                for(int j=1; j<sales; j++){ 
                    sum += V[i-j];
                    budget +=V[i-j]; 
                }
                sum += V[i];
                sum = sum/2;

                if(sum<=budget){
                    cnt++;
                    cout << cnt << "\n";
                    return 0;
                }
                else{
                    cout << cnt << "\n";
                    return 0;
                }   
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}