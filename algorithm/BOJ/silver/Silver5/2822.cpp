#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 8

using namespace std;

typedef struct Quiz{
    int number;
    int Score;
}Q;

bool com(Q a, Q b){
    return a.Score > b.Score;
}

bool com2(Q a, Q b){
    return a.number < b.number;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);


    vector<Q>Quiz(SIZE);
    for(int i=0; i<SIZE; i++){
        cin >> Quiz[i].Score ;
        Quiz[i].number = i+1;
    }

    sort(Quiz.begin(), Quiz.end(), com);

    int sum = 0;

    for(int i=0; i<SIZE-3; i++){
        sum += Quiz[i].Score;
    }
    cout << sum  << "\n";

    sort(Quiz.begin(), Quiz.begin()+5, com2);

     for(int i=0; i<SIZE-3; i++){
       cout <<  Quiz[i].number <<" ";
    }

    return 0;
}