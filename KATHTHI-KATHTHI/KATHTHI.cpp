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

int r,c;
char grid[mx][mx];
int dist[mx][mx];

int bfs0_1(int stx, int sty){
    deque<pii>dq;
    dq.push_front(pii(stx,sty));
    for(int i=0;i<=r;i++)for(int j=0;j<=c;j++)dist[i][j]=inf;
    dist[stx][sty]=0;
    while(!dq.empty()){
        pii t = dq.front();
        dq.pop_front();
        int ux = t.fs, uy = t.sc;
        for(int i=0;i<4;i++){
            int vx=ux+X[i],vy=uy+Y[i];
            if(vx<0 or vx>=r or vy<0 or vy>=c)continue;
//            cout<<grid[ux][uy]<<" "<<grid[vx][vy]<<" "<<vx<<" "<<vy<<" "<<endl;
            if(grid[ux][uy]==grid[vx][vy] and dist[vx][vy]>dist[ux][uy]){
                dist[vx][vy]=dist[ux][uy];
//                cout<<"here1"<<endl;
                dq.push_front(pii(vx,vy));
            }
            else if(grid[ux][uy]!=grid[vx][vy] and dist[vx][vy]>dist[ux][uy]+1){
                dist[vx][vy]=1+dist[ux][uy];
//                cout<<"here2"<<endl;
                dq.push_back(pii(vx,vy));
            }
        }
    }
    return dist[r-1][c-1];
}

int main() {
    #ifdef LOCAL
    freopen("D:/a.txt", "r", stdin);
    #endif // LOCAL

    int test;
    read(test);
    for(int C=1;C<=test;C++) {
            read(r);read(c);
            for(int i=0;i<r;i++){
                scanf("%s",grid[i]);
//                cout<<grid[i]<<endl;
            }
            int ans = bfs0_1(0,0);
            printf("%d\n",ans);
    }

    return 0;
}




