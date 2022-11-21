#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
	int size1 = m - l + 1;
	int size2 = r - m;
	int l_arr[size1];
	int r_arr[size2];
	
	for(int i=0; i<size1; i++){
		l_arr[i] = arr[i+l];
	}
	for(int j=0; j<size2; j++){
		r_arr[j] = arr[m+j+1];
	}
	
	int i=0, j=0, k=l;
	while(i<size1 && j<size2){
		if(l_arr[i] <= r_arr[j]){
			arr[k++] = l_arr[i++];
		}
		else{
			arr[k++] = r_arr[j++];
		}
	}
	while(i < size1){
		arr[k++] = l_arr[i++];
	}
	while(j < size2){
		arr[k++] = r_arr[j++];
	}
	
}

void mergeSort(int arr[], int l, int r){
	int m;
	if(l < r){
		m = (l+r)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
	
}

void input(int arr[], int n){
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
}

void output(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] <<  " ";
	}
	cout << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int arr[n];
	
	input(arr, n);
	output(arr, n);
	
	mergeSort(arr, 0, n-1);
	
	output(arr, n);
	return 0;
}


// thuật toán sắp xếp trộn: trộn 2 mảng đã sắp xếp
// mảng arr: là mảng đầu vào
// l, m, r: là chỉ số các phần tử đầu, giũa và cuối
/*
	function: arr, l, m, r:
		size1 = m-l-1:kích thước mảng con 1
		size2 = r-m: kích thước mảng con 2
		l_arr, r_arr: tạo 2 mảng trái và phải
		for: i=0->size1-1:
			l_arr[i] = arr[l+i]   // chép dữ liệu sang mảng con trái
		for: j=0->size2-1:
			r_arr[i] = arr[m+j+1] // chép dữ liệu sang mảng con phải
		i=0, j=0, k = l				// các biến 
		while(i<size1 && j<size2):  // tiến hành trộn
			if l_arr[i] <= r_arr[j]
				arr[k++] = l_arr[i]
			else
				arr[k++] = r_arr[j]
		while(i<size1):				// chép lại các phần tử của mảng con trái
			arr[k++] = l_arr[i]
		while(j<size2)				// chép lại các phần tử của mảng con phải
			arr[k++] = r_arr[j]
*/ 
	
// thuật toán trộn đệ quy 
// arr: mảng đầu vào
// l: chỉ số đầu. r: chỉ số cuối
/*
	function: megerSort(arr, l, r):
		if: l < r
			m = (l+r)/2	// chỉ số giữa
		mergeSort(arr, l, m)	// đệ quy nửa trái mảng
		mergeSort(arr, m+1, r) 	// đẹ quy nửa phải mảng
		merge(arr, l, m, r)		// trộn mảng KQ
		
*/