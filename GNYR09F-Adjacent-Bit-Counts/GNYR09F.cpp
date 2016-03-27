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
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 1010

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

 int dp[110][2][110];
 int t,n,K;

 ll rec(int pos, int prev, int made){
    if(pos==n){
        return (made==K);
    }
    int &ret = dp[pos][prev][made];
    if(ret!=-1)return ret;
    ret = rec(pos+1,0,made) + rec(pos+1,1,made+prev);
    return ret;
 }

 int main() {
    #ifdef LOCAL
    freopen("a.txt", "r", stdin);
    #endif // LOCAL

    int test;
    read(test);
//    CLEAR(dp,-1);
    for(int C=1;C<=test;C++) {
        read(t);read(n);read(K);
        CLEAR(dp,-1);
        int ans = rec(0,0,0);
        printf("%d %d\n",t,ans);
    }

    return 0;
}



