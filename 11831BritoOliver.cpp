//11831 Sticker Collector Robot - Oliver Brito

#include<bits/stdc++.h>
using namespace std;
int main(void){
	int m=1,n=1,orden=1;
	while(m!=0 and n!=0 and orden!=0){
		cin>>m>>n>>orden;
		if(m==0 and n==0 and orden==0)break;
		char arena[m][n];
		int a,b;
		int dir = 0; //arriba es 0, der 1, abajo 2, izq 3
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				while(true){
					cin>>arena[i][j];
					if(arena[i][j]!='\n')break;
				}
				if(arena[i][j]=='N'){dir=0;a=i;b=j;}
				if(arena[i][j]=='S'){dir=2;a=i;b=j;}
				if(arena[i][j]=='L'){dir=1;a=i;b=j;}
				if(arena[i][j]=='O'){dir=3;a=i;b=j;}
			}
		}
		char arr;
		int count=0;
		for(int i = 0; i < orden; i++){
			cin>>arr;
			if(arr=='D'){dir++;if(dir==4)dir=0;}
			else if(arr=='E'){dir--;if(dir==-1)dir=3;}
			else if(arr=='F'){
					if(dir==0 && arena[a-1][b]!='#' && a<m && b<n)a--;
					else if(dir==1 && arena[a][b+1]!='#' && a<m && b<n && a>=0 &&b>=0)b++;
					else if(dir==2 && arena[a+1][b]!='#' && a<m && b<n && a>=0 &&b>=0)a++;
					else if(dir==3 && arena[a][b-1]!='#' && a<m && b<n && a>=0 &&b>=0)b--;
			}
			if(a==m)a--;
			if(b==n)b--;
			if(a==-1)a++;
			if(b==-1)b++;
			if(arena[a][b]=='*'){
				count++;
				arena[a][b]='.';
			}
		}
		cout<<count<<endl;
	}
}