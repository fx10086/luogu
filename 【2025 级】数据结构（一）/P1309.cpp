#include<bits/stdc++.h>
using namespace std;

struct Player{
	int s;
	int w;
	int id;
}k[200005];

bool cmp(Player p1, Player p2){ 
	if(p1.s != p2.s) 
        return p1.s > p2.s; 
	else 
        return p1.id < p2.id; 
}

int main(){
	int n, r, q;
	cin >> n >> r >> q;
    for(int i = 1; i <= 2 * n; ++i)
    	cin >> k[i].s,
    	k[i].id = i;
	for(int i = 1; i <= 2 * n; ++i)
	    cin >> k[i].w;	
	
	for(int i = 1; i <= r; ++i){
	    stable_sort(k + 1, k + 2 * n + 1, cmp);
		for(int j = 1; j <= 2 * n; j += 2){ 
            if(k[j].w > k[j + 1].w) 
                ++k[j].s; 
            else 
                ++k[j + 1].s;
		}
	}
	stable_sort(k + 1, k + 2 * n + 1, cmp); 
	cout << k[q].id;
	return 0;
}