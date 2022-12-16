#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct Condo
{
    int distance;
    int price;
}condo;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int size = 0;
    cin >> size; 

    vector<condo>C(size);
    for(int i=0; i<size; i++)
        cin >> C[i].distance >> C[i].price;
    int answer = 0;
    for(int i=0; i<size; i++)
    {
        condo temp;
        bool check1 = true;
        bool check2 = true;
        temp.distance = C[i].distance;
        temp.price = C[i].price;
        for(int j=0; j<size; j++)
        {
            if(i!=j){
                if(temp.distance>C[j].distance){ //거리가 가까움
                    if(temp.price <C[j].price){
                        check1 = true;
                    }
                    else
                        check1 = false;
                }
                if(temp.price>C[j].price)
                {
                    if(temp.distance <C[j].distance)
                        check2 = true;
                    else
                        check2 = false;
                }
                if(check1 ==false || check2 ==false){
                    break;
                }
            }
        }
        if(check1 == true && check2 == true)
            answer++;
    }
    cout << answer << "\n";
    return 0;

}