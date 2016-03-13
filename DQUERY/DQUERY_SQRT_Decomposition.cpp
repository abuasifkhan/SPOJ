/** ========================================**
 ** Bismillahi-Rahamanirahim.
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/

#include <bits/stdc++.h>

using namespace std;

#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define inf (1ll<<28)
#define ll long long
#define mod 1000000007
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

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
int arr[mx/2];
struct data{
    int l, r, idx, sq;
}inp[2*mx];

bool comp(data a, data b){
    if(a.sq==b.sq)return a.r<b.r;
    return a.sq<b.sq;
}
int total=0, curl=0,curr=0;
int ans[2*mx], freq[mx*10];

inline void add(int val){
    if(freq[val]==0){
//        cout<<val<<" add "<<total<<endl;
        total++;
    }
    freq[val]++;
}
inline void del(int val){
    freq[val]--;
    if(freq[val]==0){
        total--;
//        cout<<val<<" del "<<total<<endl;
    }
}

inline void calc(int l, int r){
    if(l>curl) for(int i=curl;i<l;i++)del(arr[i]);
    if(l<curl) for(int i=curl-1;i>=l;i--)add(arr[i]);
    if(r>curr) for(int i=curr+1;i<=r;i++)add(arr[i]);
    if(r<curr) for(int i=curr;i>r;i--)del(arr[i]);
    curl=l,curr=r;
}

int main() {
    std::ios::sync_with_stdio(false);

    #ifdef LOCAL
    freopen("C:/BIN/a.in", "r", stdin);
    // freopen("C:/BIN/b.out","w",stdout);
    #endif // LOCAL
    read(n);
    int block = sqrt(n)+1;
    for(int i=1;i<=n;i++)read(arr[i]);
    read(q);
    for(int i=0;i<q;i++){
        int l,r;
        read(l);read(r);
        int sq = l/block;
        inp[i] = {l,r,i,sq};
    }
    sort(inp,inp+q,comp);

    for(int i=0;i<q;i++){
        int l=inp[i].l, r=inp[i].r, idx=inp[i].idx;
        calc(l,r);
        ans[idx]=total;
    }
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);

    return 0;
}




