#include <bits/stdc++.h>
using namespace std;

void output(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void generate_per(int arr[], int n, int i){
	if(i == n-1){
		output(arr, n);
		return ;
	}
	
	for(int j=i; j<n; j++){
		swap(arr[i], arr[j]);
		
		generate_per(arr, n, i+1);
		
		swap(arr[i], arr[j]);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; i++){
		arr[i] = i;
	}
	
	generate_per(arr, n, 0);

	return 0;
}
