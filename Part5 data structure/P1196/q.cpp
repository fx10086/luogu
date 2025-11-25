#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=30005;
int read(){
    int rv=0,fh=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') fh=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        rv=(rv<<1)+(rv<<3)+c-'0';
        c=getchar();
    }
    return rv*fh;
}
int fa[MAXN],dis[MAXN],t,num[MAXN];
int find(int x){
    if(x!=fa[x]){
        int k=fa[x];
        fa[x]=find(fa[x]);
        dis[x]+=dis[k];
        //num[x]=num[fa[x]];
    }
    return fa[x];
}
void merge(int x,int y){
    int r1=find(x),r2=find(y);
    if(r1!=r2){
        fa[r1]=r2;
        dis[r1]=dis[r2]+num[r2];
        num[r2]+=num[r1];
        num[r1]=num[r2];
    }
}
int query(int a,int b){
    int r1=find(a),r2=find(b);
    if(r1!=r2){
        return -1;
    }else {
        return abs(dis[a]-dis[b])-1;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    t=read();
    for(int i=1;i<=MAXN;i++) {fa[i]=i;num[i]=1;}
    for(int i=1;i<=t;i++){
        char c;
        scanf(" %c ",&c);
        int a=read(),b=read();
        if(c=='M'){
            merge(a,b);
        }else {
            printf("%d\n",query(a,b));
        }
    }
    
   // fclose(stdin);
    return 0;
}
