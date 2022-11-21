#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define e 1e-6

using namespace std;

typedef long double ld;


int n, f;

bool check(ld num, ld arr[]){		
	int fr = 0;
	if(num == 0){
		return false;
	}
	for(int i=0; i<n; i++){
		fr += (int)(arr[i]/num);
	}
	
	if(fr >= f){
		return true;
	}
	else{
		return false;
	}
}

ld find(ld arr[]){
	ld ini = 0,
		last = arr[n-1],
		max = 0.0;
		
	while(last - ini >= e){
		ld mid = (ini + last) / 2;
		
		if(check(mid, arr) == true){
			ini = mid;
		}
		else{
			last = mid;
		}
	}	
	return ini;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> n >> f;
		f++;
		int arr_p[n];
		for(int i=0; i<n; i++){
			cin >> arr_p[i];
		}
		
		ld arr[n];
		sort(arr_p, arr_p + n);
		
		for(int i=0; i<n; i++){
			arr[i] = arr_p[i] * arr_p[i] * M_PI;
		}
		
		ld res = find(arr);
		//cout << fixed << setprecision(6) << res << endl;
		printf("%.6Lf\n", res); 
	}
	

	return 0;
}
