#include<bits/stdc++.h>
/* Oliver Brito
10038 - Jolly Jumpers */
using namespace std;
int main(){
	int size;
	while(cin>>size){
		bool jol = true;
		vector<int>jolly;
		while(size--){
			int aux;
			cin>>aux;
			jolly.push_back(aux);
		}
		vector<int>diff;
		for (int i = 0; i < jolly.size() - 1; ++i){
			int aux = abs(jolly[i]-jolly[i+1]);
			diff.push_back(aux);
		}
		sort(diff.begin(),diff.end());
		for (int i = 0; i < diff.size(); ++i){
			if(diff[i]!=(i+1))jol = false;
		}
		if(jol)cout<<"Jolly"<<endl;
		else cout<<"Not jolly"<<endl;
	}
}