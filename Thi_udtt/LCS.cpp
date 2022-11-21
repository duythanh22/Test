#include<bits/stdc++.h>
using namespace std;

void lcs(string A, string B , int n, int m){
    int l[n+1][m+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0){
            	l[i][j]=0;
			}
            else if(A[i-1]==B[j-1]){
            	l[i][j]=1+l[i-1][j-1];
			}
            else{
            	l[i][j]=max(l[i-1][j],l[i][j-1]);
			}
        }
    }

    int index= l[n][m];
    int index1=index;
    i=n;
    j=m;
    char lcs[index+1];
    lcs[index]='\0';

    while(i>0&&j>0){
        if(A[i-1]==B[j-1]){
            lcs[index-1]=A[i-1];
            i--;j--;
            index--;
        }
        else if(l[i-1][j] > l[i][j-1])
            i--;
        else
            j--;
    }
    for(i=0;i<index1;i++){
    	cout<<lcs[i];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    // A = "AGGTAB";
    // B = "GXTXAYB";
    string A, B;
    cin >> A >> B;
    int n = A.size();
    int m =  B.size();
    lcs(A,B,n,m);

    return 0;
}