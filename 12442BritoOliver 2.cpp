// UVA 12442 Forwarding Emails - Oliver Brito

#include<bits/stdc++.h>
using namespace std;
array<int,50010>p;
array<int,50010>fw;
array<bool,50010>visited;

int dfs(int c){
     int sum = 0;
	visited[c]=true;//nodo visitado
	if(!visited[p[c]]&& p[c]!=-1){//si no he visitado el siguiente
		sum+=(dfs(p[c])+1);
	}
	visited[c]=false;
     fw[c]=sum;
	return sum;
}

int main(){
	int casos;
	cin>>casos;
	for (int i = 0; i < casos; ++i){
          p.fill(-1);
          fw.fill(-1);
          visited.fill(false);
		int mar;
		cin>>mar;
		for(int j = 0; j<mar; j++){
			int aux1,aux2;
			cin>>aux1>>aux2;
			p[aux1]=aux2;
		}
		int max=-1,ind=-1;
		//recorrer grafo
		
		for (int j = 1; j <= mar; ++j){
			if(fw[j]==-1)dfs(j);
			if(max<fw[j]){
				max=fw[j];
				ind=j;
			}

		}
		
		cout<<"Case "<<i+1<<": "<<ind<<endl;
	}
}

