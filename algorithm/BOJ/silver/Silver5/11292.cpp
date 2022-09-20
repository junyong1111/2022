#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

typedef struct TallMan{
    string name;
    string heigh;
}Tall;

bool com(Tall a, Tall b){
    return a.heigh>b.heigh;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    while(1){
        int number = 1;
        cin >> number;
        if(number ==0){return 0;}
        vector<Tall>V;

        for(int i=0; i<number; i++){
            Tall T; 
            cin >> T.name >> T.heigh;
            V.push_back(T);
        }
        sort(V.begin(), V.end(), com);
        string answer = V[0].heigh;
        cout << V[0].name << " ";
        for(int i=1; i<number; i++){
            if(answer == V[i].heigh){
                cout << V[i].name << " ";
            }
        }
        cout << "\n";
    }


    return 0;

}