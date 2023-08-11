#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(int argc, char const *argv[])
{
	int casos;
	cin>>casos;
	while(casos--){
		int n,s,q,total=0;
		cin>>n>>s>>q;
		stack<int>mochila;
		queue<int>paquetes[102];
		for (int i = 1; i <= n; ++i){
			int aux;
			cin>>aux;
			for (int j = 1; j <= aux; ++j){
				int aux2;
				cin>>aux2;
				paquetes[i].push(aux2);
				total++;
			}
		}
		int estacion=1,tiempo=0,conteo=0;
		for(estacion = 1; estacion<=n; ++estacion){
			// cout<<"Empezar"<<endl;
			
			while(!mochila.empty()){//vaciar mochila
				// cout<<"Vaciar mochila"<<endl;
				if(mochila.top()==estacion){//si pertenece a esa estacio
					mochila.pop();
					total--;
					tiempo++;
				}
				else if(paquetes[estacion].size()<q){//si se debe cargar en B
					paquetes[estacion].push(mochila.top());
					mochila.pop();
					tiempo++;
				}
				else break;
			}
			// cout<<"Salto"<<endl;
			while(mochila.size() != s && !paquetes[estacion].empty()){//llenar la mochila
				// cout<<"Entre"<<endl;
				mochila.push(paquetes[estacion].front());
				paquetes[estacion].pop();
				tiempo++;
			}

			if(estacion==n)estacion=0;
			if(total==0)break;	
			tiempo+=2;
		}
		cout<<tiempo<<endl;
	}

	return 0;
}