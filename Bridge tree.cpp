// finding bridges and marking them
void dfs(int v, int p) {
    tin[v] = minAncestor[v] = ++timer;
    used[v] = 1;
    for(auto &e: g[v]) {
        int to, id;
        tie(to, id) = e;
        if(to == p) continue;
        if(used[to]) {
            minAncestor[v] = min(minAncestor[v], tin[to]);
        } else {
            dfs(to, v);
            minAncestor[v] = min(minAncestor[v], minAncestor[to]);
            if(minAncestor[to] > tin[v]) {
                isBridge[id] = true;
            }
        }
    }
}

// giving each bridge component its component id
void dfs1(int v, int p) {
    used[v] = 1;
    comp[v] = compid;
    for(auto &e: g[v]) {
        int to, id;
        tie(to, id) = e;
        
        if(isBridge[id]) { // avoid traversing from this edge. so we get full component.
            continue;
        }
        if(used[to]) {
            continue;
        }
        dfs1(to, v);
    }
}

// Traverse every edge, if it is a bridge, connect the two components via an edge.
for(int i = 1; i <= M; ++i) {
    if(isBridge[i]) {
         int u, v;
         tie(u, v) = edges[i];
         // connect two componets using edge.
         tree[comp[u]].push_back(comp[v]);
         tree[comp[v]].push_back(comp[u]);
    }
}

// full code
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
#define all(x) (x).begin(),(x).end()
#define int long long int
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define F first
#define S second
#define inf 1e18
#define vi vector<int>
#define Point complex<int>
#define X real()
#define Y imag()
#define pii pair<int,int>
#define num0Beg(x) __builtin_clz(x) // no. of zero in beginning of bit representation
#define num0end(x) __builtin_ctz(x) // no. of zero in the end
#define numOf1(x) __builtin_popcount(x) // no. of ones in bit rep.
#define parity(x) __builtin_parity(x) // parity of 1
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 100010;
vector<pii> g[N];
vector<int> tree[N];
int tin[N],minAncestor[N],used[N],isBridge[N],comp[N],timer,compid=1;
void dfs(int v, int p) {
    tin[v] = minAncestor[v] = ++timer;
    used[v] = 1;
    for(auto &e: g[v]) {
        int to, id;
        tie(to, id) = e;
        if(to == p) continue;
        if(used[to]) {
            minAncestor[v] = min(minAncestor[v], tin[to]);
        } else {
            dfs(to, v);
            minAncestor[v] = min(minAncestor[v], minAncestor[to]);
            if(minAncestor[to] > tin[v]) {
                isBridge[id] = true;
            }
        }
    }
}
void dfs1(int v, int p) {
    used[v] = 1;
    comp[v] = compid;
    for(auto &e: g[v]) {
        int to, id;
        tie(to, id) = e;
        
        if(isBridge[id]) { // avoid traversing from this edge. so we get full component.
            continue;
        }
        if(used[to]) {
            continue;
        }
        dfs1(to, v);
    }
}
vector<pii> edges(N);
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      int n,m;
      cin>>n>>m;
      int a,b;
      cin>>a>>b;
      for(int i=1;i<=m;i++)
      {
        int u,v;
        cin>>u>>v;
        g[u].pb({v,i});
        g[v].pb({u,i});
        edges[i]={u,v};
      }
      dfs(1,0);
      for(int i=0;i<=n;i++) used[i]=0;
      for(int i=1;i<=n;i++)
      {
        if(!used[i])
        {
          dfs1(i,0);
          compid++;  
        }  
      }
      for(int i = 1; i <= m; ++i) 
      {
        if(isBridge[i]) 
        {
          int u, v;
          tie(u, v) = edges[i];
          // connect two componets using edge.
          tree[comp[u]].push_back(comp[v]);
          tree[comp[v]].push_back(comp[u]);
        }
      }
      a=comp[a],b=comp[b];
      vector<int> dist(n+1,inf),vis(n+1,0);
      dist[a]=0;
      queue<int> q;
      q.push(a);
      vis[a]=1;
      while(!q.empty())
      {
        int src=q.front();
        q.pop();
        for(int to: tree[src])
        {
          if(!vis[to])
          {
            vis[to]=1;
            dist[to]=dist[src]+1;
            q.push(to);
          }
        }
      }
      cout<<dist[b];     
    }
    return 0;
}
