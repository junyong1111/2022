#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r", stdin);

	int testCase = 0;
	cin >> testCase;

	while(testCase--)
	{
		vector<char>V;
		int numOfCard = 0 ;
		cin >> numOfCard;
		char ch;
		cin >> ch;
		V.push_back(ch); 
		// 기준점 삽입

		for(int i=1; i<numOfCard; i++){
			cin >> ch;
			if(V[0]<ch)// 뒤에 붙는 경우
			{
				V.push_back(ch);
			}
			else //앞에 붙는 경우
			{
				V.insert(V.begin(), ch);
			}
		}

		for(int i=0; i<numOfCard; i++){
			cout << V[i];
		}
		cout <<"\n";
	}

    return 0;
}
