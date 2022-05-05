#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    queue<int>card;
    

    for(int i=0; i<N; i++)
        card.push(i+1);
    
    while(card.size()!=1)
    {
        card.pop(); // 맨 처음 제거
        card.push(card.front()); //맨 처음 뒤로 
        card.pop(); // 맨 처음 제거
    }// while
    cout << card.front() << "\n";

    return 0;
}