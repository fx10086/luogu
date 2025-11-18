#include<bits/stdc++.h>

#define mem(x) memset(x,0,sizeof(x))

using namespace std;

int read(){
   int s = 0,w = 1;
   char ch = getchar();
   while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
   while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
   return s * w;
}

int n;
int a[1000010];
int dp[1000010][5];

signed main(){
	cin>>n;
	for(int i = 1;i <= n;i ++)a[i] = read();
	dp[1][0] = dp[1][1] = dp[1][2] = 2147483647;
	dp[1][a[1] + 1] = 0;
	for(int i = 2;i <= n;i ++){
		if(a[i] == -1){
			dp[i][0] = dp[i - 1][0];
			if(a[i - 1] == 1)dp[i][1] = min(dp[i - 1][0],dp[i - 1][1]) + 1;
			else dp[i][1] = 2147483647;
			if(a[i - 1] == 1)dp[i][2] = min(dp[i - 1][0],min(dp[i - 1][1],dp[i - 1][2])) + 2;
			else dp[i][2] = dp[i - 1][2] + 2;
		}
		if(a[i] == 0){
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = min(dp[i - 1][0],dp[i - 1][1]);
			if(a[i - 1] == 1)dp[i][2] = min(dp[i - 1][0],min(dp[i - 1][1],dp[i - 1][2])) + 1;
			else dp[i][2] = dp[i - 1][2] + 1;
		}
		if(a[i] == 1){
			dp[i][0] = dp[i - 1][0] + 2;
			if(a[i - 1] == -1)dp[i][1] = min(dp[i - 1][0],dp[i - 1][1]) + 1;
			else dp[i][1] = dp[i - 1][0] + 1;
			dp[i][2] = min(dp[i - 1][0],min(dp[i - 1][1],dp[i - 1][2]));
		}
	}
	if(min(dp[n][0],min(dp[n][1],dp[n][2])) < 2147483647)cout<<min(dp[n][0],min(dp[n][1],dp[n][2]));
	else cout<<"BRAK";
	return 0;
}
