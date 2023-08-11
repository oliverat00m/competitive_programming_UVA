#include<bits/stdc++.h>
using namespace std;
bool condicion(pair<string,string>&a, pair<string,string>&b){
	 return a.first<b.first;
}

string borrar(string a, string b){
	string aux = " ";
	aux+=b;
	aux+=" ";
	int index;
	while((index=a.find(aux))!=string::npos){
		a.replace(index,aux.length()," ");
	}
	int largo=0;
	for (int i = 0; i < b.length(); ++i){
		if(b[i]==a[i])largo++;
	}
	if(largo==b.size() && a[largo]==' ')a.replace(0,b.length()+1,"");

	largo=0;
	int cont = a.length()-1;
	for (int i = 0; i < b.length() ; ++i){
		if(a[a.length()-i-1]==b[b.length()-i-1])largo++;
	}
	if(largo==b.size() && a[a.length()-1-largo]==' ')a.replace(a.length()-b.length(),b.length()+1,"");
	return a;
}

string mayus(string a){
	for (int i = 0; i < a.length(); ++i){
		a[i]=toupper(a[i]);
	}
	return a;
}
string min(string a){
	for (int i = 0; i < a.length(); ++i){
		a[i]=tolower(a[i]);
	}
	return a;
}

int main(){
	map<string,string>frases;
	vector<string>excepciones;
	string s1;
	int n=0;
	while(cin>>s1 and s1!="::")excepciones.push_back(s1);
	cin.ignore();
	while(getline(cin,s1)){
		string aux = s1;
		for(int i = 0; i < excepciones.size(); i++)aux = borrar(aux, excepciones[i]);
		// cout<<aux<<endl;
		istringstream posibles(aux);
		while(posibles){
			string llave;
			posibles >> llave;
			llave = min(llave);
			s1 = min(s1);
			frases[llave]=s1;
		}
	}
	vector<pair<string,string>>orden;
	map<string,string>::iterator it;
	for(it=frases.begin();it!=frases.end();it++)orden.push_back(make_pair(it->first, it->second));
	sort(orden.begin(),orden.end(),condicion);


	for (int i = 1; i < orden.size(); ++i){
		// cout<<orden[i].first<<" "<<orden[i].second<<endl;
		int index;
		size_t count = 0, pos = 0;
		while ((pos = orden[i].second.find(orden[i].first, pos)) != string::npos) {
		    string temporal = orden[i].second, palabra = orden[i].first;
		    temporal.replace(pos,palabra.length(),mayus(palabra));
		    cout<<temporal<<endl;
		    pos += orden[i].first.size();
		}	
		
	}
	return 0;
}