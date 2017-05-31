/*
    This solution is not created by myself.
    The original source is https://blog.csdn.net/u013368721/article/details/41381547
    If there is any copyright issue, I will delete the file.
*/
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 200005 ;
const int MAXE = 400005 ;
const int LOGN = 17 ;

struct Edge {
    int v , f , n ;
    Edge () {}
    Edge ( int v , int f , int n ) : v ( v ) , f ( f ) , n ( n ) {}
} ;

struct BCC {
    Edge E[MAXE] ;
    int H[MAXN] , cntE ;
    int dfn[MAXN] , low[MAXN] , dfs_clock ;
    int bcc[MAXN] ;
    int bcc_cnt ;
    int is[MAXN] ;
    int S[MAXN] , top ;
    int belong[MAXN] ;

    void clear () {
        top = 0 ;
        cntE = 0 ;
        bcc_cnt = 0 ;
        dfs_clock = 0 ;
        clr ( H , -1 ) ;
        clr ( is , 0 ) ;
        clr ( dfn , 0 ) ;
    }

    void addedge ( int u , int v ) {
        E[cntE] = Edge ( v , 0 , H[u] ) ;
        H[u] = cntE ++ ;
    }

    void tarjan ( int u , int fa = 0 ) {
        dfn[u] = low[u] = ++ dfs_clock ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( E[i].f ) continue ;
            E[i].f = E[i ^ 1].f = 1 ;
            S[top ++] = ( i >> 1 ) ;
            if ( !dfn[v] ) {
                tarjan ( v , u ) ;
                low[u] = min ( low[u] , low[v] ) ;
                if ( low[v] >= dfn[u] ) {
                    ++ bcc_cnt ;
                    ++ is[u] ;
                    while ( 1 ) {
                        int x = S[-- top] ;
                        belong[x] = bcc_cnt ;
                        if ( x == ( i >> 1 ) ) break ;
                    }
                }
            } else low[u] = min ( low[u] , dfn[v] ) ;
        }
        if ( fa == 0 ) -- is[u] ;
    }

    void find_bcc ( int n ) {
        For ( i , 1 , n ) if ( !dfn[i] ) tarjan ( i ) ;
        For ( i , 1 , n ) if ( is[i] ) bcc[i] = ++ bcc_cnt ;
    }
} Graph ;

Edge E[MAXE] ;
int H[MAXN] , cntE ;
int anc[MAXN][LOGN] ;
int dep[MAXN] ;
int vis[MAXN] , Time ;
int n , m , q ;

void clear () {
    cntE = 0 ;
    Time = 0 ;
    clr ( H , -1 ) ;
    clr ( vis , 0 ) ;
    anc[1][0] = -1 ;
    dep[1] = 0 ;
}

void addedge ( int u , int v ) {
    E[cntE] = Edge ( v , 0 , H[u] ) ;
    H[u] = cntE ++ ;
}

void dfs ( int u ) {
    vis[u] = Time ;
    for ( int i = H[u] ; ~i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( v == anc[u][0] ) continue ;
        anc[v][0] = u ;
        dep[v] = dep[u] + 1 ;
        dfs ( v ) ;
    }
}

void preprocess () {
    For ( i , 1 , Graph.bcc_cnt ) {
        rep ( j , 1 , LOGN ) {
            anc[i][j] = -1 ;
        }
    }
    rep ( j , 1 , LOGN ) {
        For ( i , 1 , Graph.bcc_cnt ) {
            if ( ~anc[i][j - 1] ) {
                anc[i][j] = anc[anc[i][j - 1]][j - 1] ;
            }
        }
    }
}

int query ( int x , int y , int log = 0 ) {
    if ( dep[x] < dep[y] ) swap ( x , y ) ;
    for ( log = 0 ; ( 1 << log ) <= dep[x] ; ++ log ) ;
    rev ( i , log , 0 ) {
        if ( dep[x] - ( 1 << i ) >= dep[y] ) {
            x = anc[x][i] ;
        }
    }
    if ( x == y ) return x ;
    rev ( i , log , 0 ) {
        if ( ~anc[x][i] && anc[x][i] != anc[y][i] ) {
            x = anc[x][i] ;
            y = anc[y][i] ;
        }
    }
    return anc[x][0] ;
}

void solve () {
    int u , v ;
    Graph.clear () ;
    clear () ;
    rep ( i , 0 , m ) {
        scanf ( "%d%d" , &u , &v ) ;
        Graph.addedge ( u , v ) ;
        Graph.addedge ( v , u ) ;
    }
    Graph.find_bcc ( n ) ;
    For ( x , 1 , n ) {
        u = x ;
        if ( !Graph.is[u] ) continue ;
        ++ Time ;
        for ( int i = Graph.H[u] ; ~i ; i = Graph.E[i].n ) {
            int v = Graph.belong[i >> 1] ;
            if ( vis[v] != Time ) {
                vis[v] = Time ;
                addedge ( v , Graph.bcc[u] ) ;
                addedge ( Graph.bcc[u] , v ) ;
            }
        }
    }
    ++ Time ;
    For ( i , 1 , Graph.bcc_cnt ) if ( vis[i] != Time ) dfs ( i ) ;
    preprocess () ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        scanf ( "%d%d" , &u , &v ) ;
        -- u ;
        -- v ;
        u = Graph.belong[u] ;
        v = Graph.belong[v] ;
        printf ( "%d\n" , ( dep[u] + dep[v] - 2 * dep[query ( u , v )] + 1 ) / 2 ) ;
    }
}

int main () {
    while ( ~scanf ( "%d%d" , &n , &m ) && ( n || m ) ) solve () ;
    return 0 ;
}
