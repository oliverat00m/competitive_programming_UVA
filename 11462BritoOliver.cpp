#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int aux;
	while(cin>>aux and aux!=0){
		vector<int>a;
		for (int i = 0; i < aux; ++i){
			int numero;
			cin>>numero;
			a.push_back(numero);
		}
		sort(a.begin(),a.end());
		for (int i = 0; i < aux; ++i){
			cout<<a[i];
			if(i!=aux-1)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}