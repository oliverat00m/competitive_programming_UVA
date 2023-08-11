#include<bits/stdc++.h>
/*Oliver Brito
10226 - Hardwood Species*/

using namespace std;
bool condition(pair<string, int>&a, pair<string, int>&b){
    return a.first<b.first;
}
int main() {
    
	int cases;
	cin>>cases;
    getchar();
    getchar();
	for (int i = cases; i!= 0; i--) {
	    map<string,int>trees;
	    string specie;
		while(getline(cin,specie) and specie!=""){
		    trees[specie]++;
		}
		
        float sum = 0;
    	vector<pair<string,int>> sorty;
    	for(auto& it : trees){
    	    sorty.push_back(it);
    	    sum+=(float)it.second;
    	}
    	
    	sort(sorty.begin(),sorty.end(),condition);
    	
    	for(auto&it : sorty){
    	    float aux = (100*(float)it.second)/sum;
    	    cout<<it.first<<" "<<setprecision(4)<<fixed<<aux<<endl;
    	}
        if(i!=1)cout << endl;
	}
    	
}