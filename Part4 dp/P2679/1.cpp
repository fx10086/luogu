#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int n, m, k;
string a, b;
int f[1005][205]; // f[i][j]([k]): A匹配到i，B匹配到j，(找了k个子串) 的方案数
int g[1005][205]; // f[i][j]([k+1]): f的滚动数组，相当于f的下一行
int s[1005][205]; // 预处理出 从A[i],B[j]起，有多少个字符连续

void solve()
{
	cin >> n >> m >> k >> a >> b;
	
	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= m; j ++){
			for(int t = 1; i + t <= n && j + t <= m; t ++){
				if(a[i + t - 1] == b[j + t - 1]) s[i][j] ++;
				else break; // 因为是找连续**子串**，不连续直接退出
			}
		}
	}
	
	f[0][0] = 1;
	f[1][1] = -1;
	for(int kk = 0; kk <= k; kk ++){ // 因为要滚掉这一维，所以把这层放到最外边
		for(int i = 0; i <= n; i ++){
			for(int j = 0; j <= m; j ++){
				if(i > 0 && j > 0){ // 还原dp数组，前缀和是差分的逆运算
					(f[i][j] += f[i - 1][j - 1]) %= mod;
				}
				
				(f[i + 1][j] += f[i][j]) %= mod;
				(f[i + 2][j + 1] += mod - f[i][j]) %= mod;
				
				if(s[i][j] > 0){ // 这里其实有没有都行，因为是0的话后面差分就减回来了
					int p = s[i][j];
					(g[i+1][j+1] += f[i][j]) %= mod;
					(g[i+p+1][j+p+1] += mod - f[i][j]) %= mod; // 避免减出负数，加上一个mod
					// f[i+1 ~ i+p][j+1 ~ j+p]([kk+1]) += f[i][j]([kk])
				}
			}
		}
		
		if(kk == k){ // 注意这里先输出，不然一会f就要和g交换了，答案就不准了
			cout << f[n][m] << '\n';
		}
		
		// swap要想达到O(1)，可以选择用指针交换，也可以用vector（vector内部就是用的指针交换）
		swap(f, g); // 因为g是下一行，所以把f赋值为下一行（swap两个数组复杂度O(n^2)）
		memset(g, 0, sizeof g); // 清空g数组
	}
}

signed main()
{
	ios :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	solve();
	return 0;
}
