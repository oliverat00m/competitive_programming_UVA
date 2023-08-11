//318 Domino Effect - Oliver Brito

#include<bits/stdc++.h>
using namespace std;
int main(void){
	int V, P, cont = 1;
	while(cin>>V>>P and V!=0){

		int graph[V][V];
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				graph[i][j] = -1;
			}
		}
		for (int i = 0; i < P; ++i){
			int from,to,seg;
			cin>>from>>to>>seg;
			graph[from-1][to-1]=seg;
			graph[to-1][from-1]=seg;
		}
		int dist[V];
		bool visited[V];
		for (int i = 0; i < V; ++i){
			dist[i]=99999999;
			visited[i]=false;
		}
		dist[0]=0;
		
		for (int m = 0; m < V-1; ++m){
			int tim=99999999,nodo=1;
			for (int i = 0; i < V; ++i){
				if(dist[i] < tim and !visited[i]){
					nodo = i;
					tim = dist[i];
				}
			}
			visited[nodo]=true;
			for (int i = 0; i < V; ++i){
				if(graph[nodo][i]!=-1)dist[i]=min(dist[i],tim+graph[nodo][i]);
			}
			int k,k2=-1;
			double t_max = -1;
			for (int i = 0; i < V; ++i){
				if(dist[i] > t_max){
					t_max = dist[i];
					k = i;
				}
			}
			for (int i = 0; i < V; ++i){
				for (int j = i+1; j < V; ++j){
					double temp = (graph[i][j]-dist[i]+dist[j])/2.0;
					double meet = temp + dist[i];
					if(temp > 0 and temp < graph[i][j] and meet > t_max){
						t_max = meet;
						k=i;
						k2=j;
					}
				}
			}
		}
		k++;k2++;
		cout<<"System #"<<cont++<<endl;
	    cout << fixed << setprecision(1);
	    if(k2==0)cout<< "The last domino falls after " <<t_max<< " seconds, at key domino " <<k<<"."<<endl<<endl;
	    else cout<< "The last domino falls after " <<t_max<< " seconds, between key dominoes " <<k<<" and "<<k2<<"."<<endl<<endl;
	}
}