#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Rank{
	int country;
	int gold;
	int silver;
	int bronze;
	int rank;
}Rank;

bool com(Rank a, Rank b)
{
	return a.country <= b.country;
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt", "r", stdin);

	int numOfCountry = 0;
	int targetRank = 0;
	cin >> numOfCountry >> targetRank;

	vector<Rank>R(numOfCountry);

	for(int i=0; i<numOfCountry; i++)
	{
		cin >> R[i].country >> R[i].gold >> R[i].silver >> R[i].bronze;
	}
	
	for(int i=0; i<numOfCountry; i++){
		int rnakNum = 1;
		for(int j=0; j<numOfCountry; j++){
			if(i==j)
				continue;
			else
			{
				if(R[i].gold < R[j].gold) //금메달이 나보다 많은 사람이 있다면 순위에서 밀림
					rnakNum++;
				else if(R[i].gold == R[j].gold){ //금메달이 같다면 
					if(R[i].silver < R[j].silver) //은메달이 나보다 많은 사람이 있다면 순위에서 밀림
						rnakNum++;
					else if(R[i].silver == R[j].silver){ //은메달이 같다면
						if(R[i].bronze <R[j].bronze) //동메달이 나보다 많은 사람이 있다면 순위에서 밀림
							rnakNum ++;
					}
				}
			}
		}
		R[i].rank = rnakNum;
	}

	sort(R.begin(), R.end(), com); //이건 필요없을듯
	
	// for(int i=0; i<numOfCountry; i++){
	// 	cout << R[i].country << " " << R[i].gold << " " << R[i].silver << " " << R[i].bronze << " " << R[i].rank <<"\n";
	// }

	for(int i=0; i<numOfCountry; i++)
		if(R[i].country == targetRank)
			cout << R[i].rank << "\n";

	return 0;
}