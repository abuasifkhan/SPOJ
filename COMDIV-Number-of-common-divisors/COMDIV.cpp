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

vector<ll>prime;
bitset<1000000>p;

void seive(){
    p.set();
    p[1]=1;
    for(ll i=2;i<=1000000;i++){
        if(p[i]){
            prime.pb(i);
            for(ll j=i*i;j<=1000000;j+=i)
                p[j]=0;
        }
    }
}

int a, b;

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL
    seive();

    int test;
    read(test);
    for(int C=1;C<=test;C++) {
        read(a);read(b);
        int gcd = __gcd(a,b);
//        cout<<gcd<<endl;
        if(gcd==1){
            printf("%d\n",1);
            continue;
        }
        ll ans = 1;
        for(int i=0;prime[i]*prime[i]<=gcd;i++){
            int cnt=0;
            while(gcd%prime[i]==0){
                cnt++;
                gcd/=prime[i];
            }
            ans *= (cnt+1);
        }
        if(gcd>1)ans*=2;
        printf("%lld\n",ans);
    }
    return 0;
}




