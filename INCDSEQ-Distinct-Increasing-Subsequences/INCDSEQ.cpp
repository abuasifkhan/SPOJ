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
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1ll<<28)
#define ll long long
#define mod 5000000
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 10010

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
//int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
//int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
int X[]= {-1, 0, 1, 0};   //x 4 direction
int Y[]= { 0, 1, 0, -1};  //y 4 direction

int n,k;
int arr[mx], b[mx];
int dp[55][mx];
bool flag[mx];

void update(int t[], int idx, int val){
    while(idx<=n){
        t[idx]=(t[idx]+val)%mod;
        idx += (idx & -idx);
    }
}

int query(int t[], int idx){
    int ret=0;
    while(idx){
        ret = (ret+t[idx])%mod;
        idx -= (idx & -idx);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("a.txt", "r", stdin);
#endif // LOCAL
    read(n);read(k);
    for(int i=0;i<n;i++){
        read(arr[i]);
        b[i]=arr[i];
    }
    sort(b,b+n);
    int m = unique(b,b+n)-b;
    for(int i=0;i<n;i++){
        int x = lower_bound(b,b+m,arr[i])-b+1;
        if(!flag[x]){
            flag[x]=true;
            update(dp[1],x,1);
        }
        for(int j=k;j>1;j--){
            update(dp[j], x, query(dp[j-1],x-1)+query(dp[j], x-1) - query(dp[j], x) );
        }
    }
    printf("%d\n",query(dp[k], n));
//    for(int i=1;i<=n;i++)dp[i][1]=1;
//    for(int len=2;len<=k;len++){
//        for(int idx=2;idx<=n;idx++){
//            for(int i=1;i<idx;i++){
//                if(arr[i]<arr[idx]){
//                    dp[idx][len]+=dp[i][len-1];
//                    dp[idx][len]%=mod;
//                }
//            }
//        }
//    }

    return 0;
}






