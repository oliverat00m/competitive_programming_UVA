#include <bits/stdc++.h>
using namespace std;

//10698 Football Sort
//Oliver Brito


map<string,int>indice;
struct equipo{
	int puntos=0,golesda=0,golesre=0,partidas=0,id=0;
	string nombre;
};

bool condicion(equipo &a, equipo &b){
	a.id=a.golesda+a.puntos;
	b.id=b.golesda+b.puntos;
	if(a.puntos!=b.puntos)return a.puntos>b.puntos;
	if(a.golesda!=b.golesda)return a.golesda>b.golesda;
	string aux1,aux2;
	aux1=a.nombre;
	aux2=b.nombre;
	for (int i = 0; i < min(aux1.size(),aux2.size()); ++i)
		if(tolower(aux1[i])!=tolower(aux2[i]))return tolower(aux2[i]) > tolower(aux1[i]);
	return aux1.size()>aux2.size();
}
int main(int argc, char const *argv[]){
	int neq,nparti;
	while(true){
		cin>>neq>>nparti;
		if(neq==0&&nparti==0)break;
		vector<equipo>partidos;
		for (int i = 0; i < neq; ++i){
			equipo aux;
			string temp;
			cin>>temp;
			aux.nombre=temp;
			partidos.push_back(aux);
			indice[temp]=i;
		}
		for (int i = 0; i < nparti; ++i){
			char basura;
    		string equipo1,equipo2;
    		int gol1,gol2;
    		cin>>equipo1>>gol1>>basura>>gol2>>equipo2;
    		int eq1=indice[equipo1];
    		int eq2=indice[equipo2];
    		if(gol1>gol2){partidos[eq1].puntos+=3;}
    		else if(gol2>gol1){partidos[eq2].puntos+=3;}
    		else{partidos[eq1].puntos+=1; partidos[eq2].puntos+=1;}
    		//goles dados
    		partidos[eq1].golesda+=gol1;
    		partidos[eq2].golesda+=gol2;
    		//goles recibidos
    		partidos[eq1].golesre+=gol2;
    		partidos[eq2].golesre+=gol1;
    		//partidas
    		partidos[eq1].partidas++;
    		partidos[eq2].partidas++;
    		//indice
    	}
    	sort(partidos.begin(),partidos.end(),condicion);
    	int rank = 0;
		for(int i=0;i<partidos.size();i++) {
			if (i == 0 || partidos[i].puntos != partidos[i-1].puntos || partidos[i].golesda != partidos[i-1].golesda){
			rank = i + 1;
			printf("%2d. ", rank);
			}
			else printf("    ");


			printf("%15s %3d %3d %3d %3d %3d ", partidos[i].nombre.c_str(), partidos[i].puntos, partidos[i].partidas, partidos[i].golesda, partidos[i].golesre, partidos[i].golesda - partidos[i].golesre);

			if (partidos[i].partidas == 0) printf("%6s\n", "N/A");
			else printf("%6.2f\n", partidos[i].puntos * 100.0 / (3.0 * partidos[i].partidas));

        }
        indice.clear();

	}
	return 0;
}