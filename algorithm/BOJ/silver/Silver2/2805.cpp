#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    long long Num_Tree, Len_Tree = 0;
    cin >> Num_Tree >> Len_Tree;
    vector<int>Tree(Num_Tree, 0);
    long long Max = 0;
    for(int i=0; i<Num_Tree; i++){
        cin >> Tree[i];
        if(Max< Tree[i])
            Max = Tree[i];
    }
    stable_sort(Tree.begin(), Tree.end());


    long long  Start = 0;
    long long  End = Max ;
    long long  Mid = 0;
    long long answer = 0;


    while(Start <= End){
        long long Sum = 0;
        Mid =(Start+End)/2;

        for(int i=0; i<Num_Tree; i++){
            long long temp = Tree[i] - Mid;
            if(temp > 0){
                Sum += temp;
            }
        }

        if(Sum < Len_Tree)
            End = Mid -1;
        else{
            Start = Mid +1;
            if(Mid > answer)
                answer = Mid;   
        }
    } //while

    cout << answer << "\n";
    return 0;

}