#include <bits/stdc++.h>
using namespace std;

void output(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void generateBinary(int arr[], int n, int i){
	if(i == n){
		output(arr, n);
		return ;
	}
	
	// gắn bằng 0 ở i -> tìm các hoán vị còn lại
	arr[i] = 0;
	generateBinary(arr, n, i+1);
	// gán = 1 ở i
	arr[i] = 1;
	generateBinary(arr, n, i+1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int arr[n];
	generateBinary(arr, n, 0);
	
	return 0;
}
