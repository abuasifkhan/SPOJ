/** ========================================**
 ** Bismillahi-Rahamanirahim.
 ** @Author: A Asif Khan Chowdhury
 /** ========================================**/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <strings.h>
#include <cstdio>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, ll>
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

int n;

int a[4*mx];

int main() {
#ifdef DEBUG
    freopen("/Users/abuasifkhan/Desktop/Programming/ProblemSolving/ProblemSolving/a.in", "r", stdin);
    //    freopen("/Users/abuasifkhan/Desktop/Programming/ProblemSolving/ProblemSolving/b.out", "w", stdout);
#endif
    
    read(n);
    for(int i=0;i<n;i++){
        read(a[i]);
    }
    
    set<pii>pos;
    set<pii>::iterator it1,it2;
    ll cumSum=0;
    
    for(int i=0;i<n;i++){
        if(i==0){
            printf("%d\n",0);
            pos.insert(pii(a[i],1ll));
        }
        else{
            it1 = pos.lower_bound(pii(a[i],0ll));
            it2 = pos.upper_bound(pii(a[i],0ll));
            pii l=pii(0,0), r=pii(0,0);
            
            
            if(it2==pos.end()) r.first=-1;
            else r=*it2;
            if(it1!=pos.begin()) it1--;
            l = *it1;
            
//            cout<<l.second<<" "<<r.second<<endl;
            
            
            if(a[i]>l.first && a[i]<r.first){
                if(r.second>l.second){
                    cumSum+=r.second;
                    pos.insert(pii(a[i],r.second+1));
                }
                else{
                    cumSum+=l.second;
                    pos.insert(pii(a[i],l.second+1));
                }
            }
            else if (a[i]<r.first){
                cumSum+=r.second;
                pos.insert(pii(a[i],r.second+1));
                
            }
            else{
                cumSum+=l.second;
                pos.insert(pii(a[i],l.second+1));
            }
            printf("%lld\n",cumSum);
        }
    }
    
    return 0;
}


