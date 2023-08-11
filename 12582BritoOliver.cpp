//12582 Wedding of Sultan - Oliver Brito

#include<bits/stdc++.h>
using namespace std;
int main(void){
	int cases;
	cin>>cases;
	for (int j = 0; j < cases; ++j){
		string aux;
		cin>>aux;
		stack<char>sprink;
		sprink.push(aux[0]);
		map<char,int>resultado;
		for (int i = 1; i < aux.size()-1; ++i){
			if(sprink.top()!=aux[i])sprink.push(aux[i]);
			else{
				sprink.pop();
				resultado[aux[i]]++;
				resultado[sprink.top()]++;
			}
		}
		map<char,int>::iterator it;
		cout<<"Case "<<j+1<<endl;
		for (it = resultado.begin(); it != resultado.end(); ++it){
			cout<<it->first<<" = "<<it->second<<endl;
		}
	}
}