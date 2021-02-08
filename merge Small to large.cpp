//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/separating-numbers-6fe976a9/submissions/

// merge small to large + offline queries + DSU
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
 
const int N = 3e5 + 5;
vector<pii> edges(N);
int color[N];
map<int,int> mp[N];
int parent[300001],rak[300001];
void make_set(int v)     // making a new set
{
  parent[v]=v;
  rak[v]=0;
}
int find_set(int v)  // finding the leader of the set containing v
{
  if(parent[v]==v)
    return v;
  else
    return parent[v]=find_set(parent[v]);
}
int union_set(int u,int v)   // DOING UNION BY RANK
{
  if(mp[u].size()<mp[v].size())
    swap(u,v);
  int res=0;
  for(auto it: mp[v])
  {
    if(mp[u].find(it.F)!=mp[u].end())
      res+=it.S*mp[u][it.F],mp[u][it.F]+=it.S;
    else 
      mp[u][it.F]+=it.S;
  }
  parent[v]=u;
  return res;
}
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      int n;
      cin>>n;
      for(int i=1;i<=n;i++)
        make_set(i);
      for(int i=1;i<=n-1;i++) 
      {
        int a,b;
        cin>>a>>b;
        edges[i]={a,b};
      }      
      for(int i=1;i<=n;i++)
        cin>>color[i],mp[i][color[i]]++;
      vector<int> q(n-1);
      for(int i=0;i<n-1;i++)
        cin>>q[i];
      vector<int> ans;
      for(int i=n-2;i>=0;i--)
      {
        int u=edges[q[i]].F,v=edges[q[i]].S;
        u=find_set(u),v=find_set(v);
        ans.pb(union_set(u,v));
      }
      reverse(ans.begin(),ans.end());
      for(int el: ans)  cout<<el<<"\n";
    }
    return 0;
}
