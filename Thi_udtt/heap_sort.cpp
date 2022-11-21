#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void siftDown(int arr[], int n, int index){
	int max = index;
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if(left < n && arr[left] < arr[max]){
		max = left;
	}
	if(right < n && arr[right] < arr[max]){
		max = right;
	}
	if(max != index){
		swap(arr[max], arr[index]);
		siftDown(arr, n, max);
	}
}

void heapSort(int arr[], int n){
	for(int i = n/2-1; i>=0; i--){
		siftDown(arr, n, i);
	}
	for(int i=n-1; i>=1; i--){
		swap(arr[0], arr[i]);
		siftDown(arr, n, 0);
	}
}

void input(int arr[], int n){
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
}

void output(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int arr[n];
	input(arr, n);
	output(arr, n);
	heapSort(arr, n);
	output(arr, n);

	return 0;
}


// thuật toán sắp xếp vun đống tăng dần (heap sort), triển khia bằng mảng
// arr: mảng dầu vào với n phần tử
/*
	function heapsort(arr, n)
		tạo maxheap từ mảng đầu vào
		for( i: n/2-1 -> 0):
			siftdown(arr, n, i)	// sàng xuống
		// tiến hành đưa lần lần lượt các ptu ở đầu heap về đúng vị trí
		for(i: n-1 -> 1):
			swap(arr[0], arr[i])		tráo đổi
			siftdown(arr, i, 0) 		// tiếp tục sàng
*/

/*
	Hàm sàng
	function sifdown(arr, n, index)		// cho index là đỉnh ban đầu
		max = index		// giả sử index là vị trí max ban đầu, gán = max
		left = index*2+1		//	vị trí con trái
		right = index*2+2		// vị trí con phải
	if: left < n && arr[left] > arr[max])	// nếu tồn tại con trái lớn hơn cha
		max = left;							// gán lại max
		
	if: right < n && arr[right] > arr[max]	// nếu tồn tại con phải lớn hơn cha
		max = right;						// gán lại max
	
	if: max != index					// nếu đỉnh cha ban đầu không là lớn nhất
		swap(arr[index], arr[max]);		// đổi chỗ, đưa max lên làm đỉnh
		siftdown(arr, n, max);			// đệ quy, xử lý các node kế tiếp
		
		
*/
