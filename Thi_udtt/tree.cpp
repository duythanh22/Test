#include <bits/stdc++.h>
using namespace std;

int compare(int a, int b){
	return a > b;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
//	freopen("ptrees.inp", "r", stdin); 
//	freopen("ptrees.out", "w", stdout);

	vector <int> t;
	int n;
	cin >> n;
	
	t.resize(n+1);
	
	for(int i=1; i<=n; i++){
		cin >> t[i];
	}
	
	sort(t.begin()+1, t.end(), compare);
	int res = 0;
	
	for(int i=1; i<=n; i++){
		res = max(res, i + t[i] + 1);
	}
	cout << res;
	return 0;
}

/*
4
2 3 4 3

6
39 38 9 35 39 20
*/