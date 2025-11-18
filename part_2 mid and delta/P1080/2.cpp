#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN=1010;
const int BASE=1e4;

struct bign{
    int a[MAXN<<2],len;
    // bign(int len=0){
    //     this->len=len;
    // }
    bign operator=(int rhs){
        len=0;
        if(rhs==0){
            len=1, a[1] = 0;
            return *this;
        }
        while(rhs){
            a[++len]=rhs%BASE;
            rhs/=BASE;
        }
        return *this;
    }
    bign operator=(const bign rhs){
        memcpy(a,rhs.a,sizeof(rhs.a));
        len=rhs.len;
        return *this;
    }
    void operator*=(const int rhs){
        for(int i=1;i<=len;i++)
            a[i]*=rhs;
        for(int i=1;i<=len;i++){
            a[i+1]+=a[i]/BASE;
            a[i]%=BASE;
            if(i>=len&&a[i+1])
                len++;
        }
    }
    bign operator/(const int rhs){
        bign c=*this;
        for(int i=c.len;i>0;i--){
            c.a[i-1]+=(c.a[i]%rhs)*BASE;
            c.a[i]/=rhs;
        } c.a[0] = 0;
        while(c.len&&!c.a[c.len])
            c.len--;
        if (!c.len) c.len++;
        return c;
    }
    void print(){
        printf("%d",a[len]);
        for(int i=len-1;i>0;i--)
            printf("%04d",a[i]);
        puts("");
    }
    bool operator>(const bign &rhs)const{
        if(len!=rhs.len)
            return len>rhs.len;
        for(int i=len;i;i--)
            if(a[i]!=rhs.a[i])
                return a[i]>rhs.a[i];
        return 0;
    }
}mul,ans;

struct node{
    int a,b;
    bool operator<(const node &rhs)const{
        return a*b<rhs.a*rhs.b||(a*b==rhs.a*rhs.b&&a<rhs.a);
    }
}p[MAXN];

int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=0;i<=n;i++) {
        scanf("%d%d",&p[i].a,&p[i].b);
    }
    std::sort(p+1,p+n+1);
    // for (int i = 1; i <= n; i++)
    //     printf("l:%d r:%d\n", p[i].a, p[i].b);
    mul=p[0].a;
    for(int i=1;i<=n;i++){
        bign tmp=mul/p[i].b;
        tmp.print();
        if(tmp>ans)
            ans=tmp;
        mul*=p[i].a;
    }
    ans.print();
    return 0;
}
