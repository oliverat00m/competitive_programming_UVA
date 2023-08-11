#include<bits/stdc++.h>
using namespace std;
const int x[]= {-1, -1, -1,  0, 0,  1, 1, 1};
const int y[]= {-1,  0,  1, -1, 1, -1, 0, 1};
void borra(int aux[][25],int a, int b,int tam){
    aux[a][b]=0;
    for(int i = 0; i < 8;i++){
        int ax,by;
        ax=a+x[i];
        by=b+y[i];
        if((ax>=0 and by>=0 and ax<tam and by<tam)
        	and aux[ax][by]==1)borra(aux,ax,by,tam);
    }
}
int main(void){
	int n;
	int caso = 0;
	int war[25][25];
	while(cin>>n){
		for (int i = 0; i < n; ++i){
			string aux;
			cin>>aux;
			for(int j = 0; j < n; j++){
				war[i][j]=aux[j]-48;
			}
		}
		int cont = 0;
		for (int i = 0; i < n; ++i){
			for(int j = 0; j < n; j++){
                if(war[i][j]==1){
                    borra(war,i,j,n);
                    cont++;
                }
			}
		}
		cout<<"Image number "<<caso+1
		    <<" contains "<<cont
		                 <<" war eagles."<<endl;
		                 caso++;
	}
}