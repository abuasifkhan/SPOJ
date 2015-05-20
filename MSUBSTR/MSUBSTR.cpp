//!
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
 ** @Category:
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
#define pi 3.141592653589793
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};
char str[6020];
char inp[3010];
int len;
int P[6020];

void process(){
    for(int i=0;i<=2*len;i++){
        if(i%2==0)str[i]='|';
        else str[i]=inp[i/2];
    }
}
int Max;
void longestPal(){
    process();
    CLEAR(P,0);
    int C=0,R=0; // C = Center of longest palindrome so far;
                 // R = Last position of the longest palindrome so far;
    Max=0;
//    cout<<str<<endl;
    for(int i=1;i<2*len;i++){
        int i_mirror = 2*C-i;    // Mirror Index WRT C.
        P[i]=(R>i)?min(R-i, P[i_mirror]):0;  // If it exceeds R then zero. Else...
        while(i+1+P[i]<=2*len and i-1-P[i]>=0 and str[i+1+P[i]] == str[i-1-P[i]])
            P[i]++;
        if(i+P[i]>R){   /// Update C and R if i+P[i] exceeds R.
            R = i+P[i];
            C = i;
        }
        Max=max(P[i],Max);
    }
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        CLEAR(inp,0);CLEAR(str,0);
        cin>>inp;
        len=strlen(inp);
        longestPal();
        int cnt=0;
        for(int i=0;i<=2*len;i++){
            if(P[i]==Max)cnt++;
        }
        printf("%d %d\n",Max,cnt);
    }
    return 0;
}





