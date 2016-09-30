/**============= Approach =================**
@Author: A Asif Khan Chowdhury
@Category:
/**========================================**/
 
 
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
#define open freopen("E:/a.txt", "r", stdin);
#define write freopen("E:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 100000007
#define mx 1000010
int X[]={-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]={-1, 0, +1, 1, 1, 0, -1, -1};
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
int n, tree[mx], ans[mx];
 
struct dQuery
{
    int st, en, typ, val;
};
 
bool comp (dQuery a, dQuery b){
    if(a.en==b.en) return a.typ<b.typ;
    return a.en<b.en;
}
 
void update(int idx, int val){
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}
int query (int idx){
    int ret=0;
    while(idx>=1){
        ret+=tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
int main()
{
	// open
	CLEAR(tree, 0);
	S(n);
	map<int, int>mp;
    vector<dQuery>stk;
	for(int i=1; i<=n; i++){
	    int a;S(a);
        dQuery t;
        t.st=t.en=i; t.val=a, t.typ=0;
        stk.pb(t);
	}
	int q;
	S(q);
    for(int i=1; i<=q; i++){
        int u,v,val; S(u); S(v);
        dQuery t;
        t.st=u, t.en=v, t.val=i, t.typ=1;
        stk.pb(t);
    }
    sort(stk.begin(), stk.end(), comp);
    for(int i=0; i<stk.size(); i++){
        dQuery tmp = stk[i];
        if(tmp.typ==0){
            if(mp[tmp.val]){
                update(mp[tmp.val], -1);
            }
            mp[tmp.val] = tmp.st;
            update(mp[tmp.val],1);
        }
        else{
            ans[tmp.val] = query(tmp.en)-query(tmp.st-1);
        }
    }
    for(int i=1; i<=q; i++) pf("%d\n", ans[i]);
    return 0;
}
 
