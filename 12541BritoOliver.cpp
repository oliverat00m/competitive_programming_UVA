#include<iostream>

using namespace std;
int main()
{
	int personas,max=0,min=999999;
	string nombremax,nombremin;
	cin>>personas;
	for (int i = 0; i < personas; ++i){
		int aux1,aux2,aux3;
		string nomaux;
		cin>>nomaux>>aux1>>aux2>>aux3;
		aux1=(30-aux1)+((2022-aux3)*30*12)+(12-aux2)*30;
		if(max<aux1){
			max=aux1;
			nombremax=nomaux;
		}
		if(min>aux1){
			min=aux1;
			nombremin=nomaux;
		}
	}
	cout<<nombremin<<endl;
	cout<<nombremax<<endl;
	return 0;
}