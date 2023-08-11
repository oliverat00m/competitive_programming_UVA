#include<iostream>
using namespace std;
int main()
{
	int casos,resultado=0;
	cin>>casos;
	int clown[casos];
	for (int i = 0; i < casos; ++i){
		resultado=0;
		while(true){
			int aux;
			cin>>aux;
			if(aux>resultado)resultado=aux;
			if(cin.peek()=='\n')break;
		}
		clown[i]=resultado;
	}
	for (int i = 0; i < casos; ++i){
		cout<<"Case "<<i+1<<": "<<clown[i]<<endl;
	}
	return 0;
}