#include<iostream>
#include<stack>

using namespace std;
int main(int argc, char const *argv[])
{
	int coches;
	bool resultado;
	while(cin>>coches and coches!=0){
		bool ciclo = true;
		while(ciclo){
			resultado = true;
			int aux = 0,m=1;
			stack<int> tren;
			for (int i = 0; i < coches; ++i){
				int pedido;
				cin>>pedido;
				if(pedido==0){
					cout<<endl;
					ciclo = false;
					break;
				}								//3 5 4 2 1
				if(pedido>aux){
					while(m!=pedido){
						tren.push(m);
						m++;
					}
					aux = pedido;
					m++;
				}
				else{
					if(tren.top()==pedido){
						tren.pop();
						aux=pedido;
					}
					else resultado = false;
				}
			}
			if(ciclo){
				if(resultado)cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
		}
	}
	return 0;
}