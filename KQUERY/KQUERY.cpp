/** ========================================**
 ** Bismillahi-Rahamanirahim.               **
 ** @Author: A Asif Khan Chowdhury          **
 ** ========================================**/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <strings.h>
#include <cmath>
#include <cstdio>
#include <set>
#include <list>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;

#define Set(N, j) (N|(1ll<<j))
#define reset(N, j) (N&~(1ll<<j))
#define Check(N, j) (bool)(N&(1ll<<j))
#define toggle(N, j) (N^(1ll<<j))
#define turnOff(N, j) (N & ~(1ll<<j))

#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1ll<<28)
#define ll long long
#define ull unsigned ll
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while((~c&&c<'0')||c>'9') {
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

struct query{
	int l,r,k,idx;
};

bool Qcomp(const query &a,const query &b){
	return a.k < b.k;
}

bool comp(const pair<int,int> &a,const pair<int,int> &b){
	return a.first < b.first;
}


void update(vector<int> &tree,int idx,int maxIdx,int val){
	while( idx <= maxIdx){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int get(vector<int> &tree,int idx){
	int ans = 0;
	while( idx){
		ans += tree[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

int main() {
#ifdef DEBUG
    freopen("C:/Users/abu.chowdhury/Desktop/programming/input.in","r",stdin);
//    freopen("C:/Users/abu.chowdhury/Desktop/programming/output.out","w",stdout);
#endif

    int n, k;
    read(n);
    vector <pii> a(n);
    for(int i=0;i<n;i++){
        read(a[i].fs);
        a[i].sc=i+1;
    }

    sort(a.rbegin(), a.rend(), comp);

    read(k);
    vector<query>q(k);

    for(int i=0;i<k;i++){
        read(q[i].l);
        read(q[i].r);
        read(q[i].k);
        q[i].idx=i;
    }

    sort(q.rbegin(),q.rend(),Qcomp);

    vector<int>tree(n+1,0),ans(k);

    int idxA=0;
    for(int i=0;i<k;i++){
        while(idxA<n && a[idxA].first>q[i].k){
            update(tree, a[idxA].second,n,1);
            idxA++;
        }
        ans[q[i].idx] = get(tree, q[i].r)-get(tree, q[i].l-1);
    }
    for(int i=0;i<k;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}










