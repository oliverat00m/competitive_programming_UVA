#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
	string input[999],output[999],x;
	int m;
	while(cin>>x && x!="*"){
		input[m]=x;
		m++;
	}
	for (int i = 0; i < m; ++i){
		if (input[i]=="Hajj"){
			output[i]="Hajj-e-Akbar";
		}
		else{
			output[i]="Hajj-e-Asghar";
		}
	}
	for (int i = 0; i < m; ++i){

		cout<<"Case "<<i+1<<": "<<output[i]<<endl;
	}
	return 0;
}