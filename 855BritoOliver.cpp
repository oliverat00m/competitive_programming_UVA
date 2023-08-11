#include<bits/stdc++.h>

/* Oliver Brito
855 - Lunch in Grid City*/

using namespace std;
int main(){
	int cases;
	cin>>cases;
	while(cases--){
		int t,t2,f;
		cin>>t>>t2>>f;
		vector<int>x;
		vector<int>y;
		for(int i = 0; i<f; i++){
			int a1,a2;
			cin>>a1>>a2;
			x.push_back(a1);
			y.push_back(a2);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		f--;
		cout<<"(Street: "<<x[f/2]<<", Avenue: "<<y[f/2]<<")"<<endl;
	}
	return 0;
}