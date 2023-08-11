#include<iostream>
#include<map>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	map<vector<int>,long>mapa;
	long casos;
	while(true){
		mapa.clear();
		cin>>casos;
		if(casos==0)break;
		for (int i = 0; i < casos; ++i){
			vector<int>combinacion;
			for (int j = 0; j < 5; ++j){
				int aux;
				cin>>aux;
				combinacion.push_back(aux);
			}
			sort(combinacion.begin(),combinacion.end());
			// string llave = "";
			// for (int j = 0; j < 5; ++j)llave+=combinacion[j];
			//En primera instancia, habia hecho el codigo con strings, pero
			//nunca supe por que no lo aceptaba el juez. La solucion fue 
			//cambiar las llaves por vectores :)
			mapa[combinacion]++;
		}
		map<vector<int>, long>::iterator m = mapa.begin();
		long max=0,rep=0;
		while(m!=mapa.end()){//calcula el maximo
			if(m->second>max)max=m->second;
			m++;
		}
		m = mapa.begin();
		while(m!=mapa.end()){//calcula cuantas veces se repite
			if(m->second==max)rep++;
			m++;
		}
			

		cout<<rep*max<<endl;
	}
	return 0;
}