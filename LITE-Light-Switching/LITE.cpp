//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/


/**................ Headers ................**/
#include <bits/stdc++.h>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1<<28)
#define ll long long
#define mod 1000000007
#define debug cout<<"ok"<<endl;
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

//Fast Reader
template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
// int X[]= {-1, 0, 1, 0};   //x 4 direction
// int Y[]= { 0, 1, 0, -1};  //y 4 direction

int n,q;
int tree[3*mx];
int lazy[3*mx];
void pushDown(int node, int l, int r){
    if(lazy[node]){
        int mid = MID(l,r);
        tree[node*2]=(mid-l+1)-tree[node*2];
        tree[node*2+1]=(r-mid)-tree[node*2+1];
        lazy[node*2]^=1;
        lazy[node*2+1]^=1;
        lazy[node]=0;
    }
}
void update(int node, int l, int r, int x, int y){
    if(l>r or l>y or r<x)return;

    if(l>=x and r<=y){
        tree[node]=(r-l+1)-tree[node];
        lazy[node]^=1;
        return;
    }
    pushDown(node,l,r);
    int mid=MID(l,r);
    update(node*2,l,mid,x,y);
    update(node*2+1,mid+1,r,x,y);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int x, int y){
    if(l>r or l>y or r<x)return 0;
    if(l>=x and r<=y)return tree[node];
    pushDown(node,l,r);
    int mid = MID(l,r);
    return query(node*2,l,mid,x,y)+query(node*2+1,mid+1,r,x,y);
}

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    read(n);read(q);
    while(q--){
        int t, l, r;read(t);read(l);read(r);
        if(!t){
            update(1,1,n,l,r);
        }
        else{
            int ans = query(1,1,n,l,r);
            printf("%d\n",ans);
        }
    }

    return 0;
}




