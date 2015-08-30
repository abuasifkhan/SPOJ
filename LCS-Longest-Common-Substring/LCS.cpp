//! Bismillahi-Rahamanirahim.
///

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
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 600010

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

struct state{
    state *par, *ch[26];
    int val, cnt; bool vis;
    state(){
        par=0; CLEAR(ch,0);
        val=cnt=vis=0;
    }
} node[2*mx], *root, *last;
int size;
char s[mx], ans[mx]; int anslen;

inline void init(){
    root = last = &node[0];
    size = 0;
}

inline void add(int c){
    state *p = last;  // p is last index.
    state *new_state = &node[++size];    // new_state is new node.
    new_state->val = p->val+1;     // new_state's value will be its parents value+1
    while(p and !p->ch[c])  // Climbing up the tree while there's no
                            // char c found.
        p->ch[c]=new_state, p=p->par;  // updating
    if(!p){
        new_state -> par = root; // p==null? then new_state's parent is root.
    }
    else{
        state *q = p->ch[c];  // q is same character
                                // child of c found above.
        if(q->val==p->val+1)    // if q is immediate child of p,
            new_state->par = q;        // this will be new_state's parent.

        else{   // cloning q. clone= clone node of q.
            state *clone = &node[++size];
            clone->val = p->val+1;     // clone's value = q's parent's value+1
            memcpy(clone->ch, q->ch, sizeof(q->ch)); // copy all q's child data
                                    // in clone's child.
            clone->par=q->par;         // clone's parent is q's parent.
            q->par=new_state->par=clone;      // updating q and new_state's parent to clone.
            while( p && p->ch[c]==q){
                p->ch[c]=clone, p=p->par;  // Climbing up the tree and
                                        // updating new child.
            }
        }
    }
    last=new_state;
}

string s1,s2;

int main() {
#ifdef LOCAL
    open
    double st=clock(),en;
#endif // LOCAL
    // Constrain
    // LDC
    init();
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++){
        add(s1[i]-'a');
    }
    int len=0,ans=0;
    state * go=root;
    for(int i=0;i<s2.size();i++){
        int c=s2[i]-'a';
        if(go->ch[c]){
            len++;
            go=go->ch[c];
        }
        else{
            while(go and !go->ch[c]) go=go->par;
            if(!go){
                go=root;
                len=0;
            }
            else{
                len=go->val+1;
                go=go->ch[c];
            }
        }
        ans=max(ans, len);
    }
    cout<<ans<<endl;

#ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
#endif // LOCAL
    return 0;
}





