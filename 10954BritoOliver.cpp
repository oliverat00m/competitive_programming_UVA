#include<iostream>
#include<vector>
#include<algorithm>
/* Oliver Brito
10954 - Add all */

using namespace std;
int main() {
	int cases;
	while (cin >> cases and cases != 0) {
		vector<int>num;
		for (int i = 0; i < cases; i++) {
			int aux;
			cin >> aux;
			num.push_back(aux);
		}
		int sum = 0;
		while(num.size()>1){
			sort(num.begin(), num.end());
			int aux = num[0] + num[1];
			sum += aux;
			num[1] = aux;
			num.erase(num.begin());
		}
		cout << sum << endl;
	}
}