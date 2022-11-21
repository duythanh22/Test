#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void showResult(int arr[], int r){
	cout << "[ ";
	for(int i=0; i<r; i++){
		cout << arr[i] + 1 << " ";
	}
	cout << " ]\n";

}


// c: col index
// i: row index

bool isCheck(int c, int arr[]){
	for (int i = 0; i<c; i++){
//		if(arr[i] == arr[c]){
//			return false;
//		}
//		if(arr[i] == (arr[c] - (c-i))){
//			return false;
//		}
//		if(arr[i] == (arr[c] + (c-i))){
//			return false;
//		}
		if((arr[i] == arr[c]) || (abs(arr[c] - arr[i]) == abs(c - i))) {
			return false;
		}
	}
	return true;
}


bool Try_BackTrack_Q(int arr[], int r, int c){
	if(c >= r){
		showResult(arr, r);
		cnt++;
		return false;
	}
	for(int i=0; i<r; i++){
		arr[c] = i;
		if(isCheck(c, arr)){
			if(Try_BackTrack_Q(arr, r, c+1)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n;
	cout << "Nhap kich thuoc: ";
	cin >> n;
	int arr[n];

	if(cnt == 0){
		cout << "Cac ket qua tim duoc:\n";
		Try_BackTrack_Q(arr, n, 0);
		cout << "So ket qua tim duoc: " << cnt << endl;
	}
	else{
		cout << "Khong co loi giai.";
	}

	return 0;
}