#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	long t[100000],m=0,x=1;
	while(cin>>x and x!=0){
		t[m]=x;
		m++;
	}
	for (int i = 0; i < m; ++i){
		long num = t[i],bin[100000],cn=0,j=0;
		while(num!=0){
			bin[j]=num%2;
			num=num/2;
			j++;
		}
		cout<<"The parity of ";
		for (int i = j-1; i >= 0; --i){
			cn=cn+bin[i];
			cout<<bin[i];
		}
		cout<<" is "<<cn<<" (mod 2)."<<endl; //paridad
	}

	return 0;
} 