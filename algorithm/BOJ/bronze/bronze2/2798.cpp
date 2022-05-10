#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N, M;
	int Sum = 0;
	cin >> N >> M;
	vector<int>ans(N,0);
	for(int i=0; i<N; i++)
	{
		cin >> ans[i];
		Sum += ans[i];
	}
	sort(ans.begin(), ans.end());
	int answer = 0;
	int black = 0;
	int min = 210000000 ;
	int card = 0;
	
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			for(int k=j+1; k<N; k++){
				answer = ans[i] + ans[j]+ ans[k];
				if(answer >M){continue;}
				black = abs(answer-M); 
				if(min>=black){
					min = black;
					card = answer;
				}
			}
		}
	}
	cout << card << "\n";
	return 0;
}

