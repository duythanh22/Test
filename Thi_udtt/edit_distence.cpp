#include<bits/stdc++.h>
using namespace std;

int DP[100][100];

void findEdit(string str1, string str2) {

	int len1 = str1.length();
	int len2 = str2.length();
	int i, j;
	DP[len1 + 1][len2 + 1];

	for (i = 0; i <= len1; i++){
		DP[i][0] = i;
	}
	for (j = 0; j <= len2; j++){
		DP[0][j] = j;
	}

	for (i = 1; i <= len1; i++){
		for (j = 1; j <= len2; j++){
		  	if (str1[i - 1] == str2[j - 1]){
		     	DP[i][j] = DP[i - 1][j - 1];
			}
		    else{
		     	DP[i][j] = (min(min(DP[i - 1][j - 1], DP[i - 1][j]), DP[i][j - 1])) + 1;
			}
	  	}
	}
	while (len1 && len2){
		if (str1[len1 - 1] == str2[len2 - 1]) {

	     	len1--;
	     	len2--;
	  	}

	  	else if (DP[len1][len2] == DP[len1-1][len2-1] + 1) {

	     	cout <<"\nThay '" << str1[len1-1] <<"' bang '" << str2[len2-1];
	     	len1--;
	     	len2--;
	  	}

	  	else if (DP[len1][len2] == DP[len1-1][len2] + 1) {

			cout << "\nXoa "<< str1[len1-1] << "'";
			len1--;
	  	}
	  	else if (DP[len1][len2] == DP[len1][len2-1] + 1){
	  		cout << "\nThem '" << str2[len2-1] <<"'";
		    len2--;
	  	}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str1 = "abcdef";
	string str2 = "axcdfdh";
	cout << "Chuoi 1: " <<  str1 << endl;
	cout << "Chuoi 2: " << str2 << endl;
	cout <<"Chinh sua chuoi thu nhat thanh chuoi thu 2: ";
	findEdit(str1, str2);

	return 0;
}

