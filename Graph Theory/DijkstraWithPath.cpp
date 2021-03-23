const int N = 1e6;
vector<int> dist(N,inf),par(N,-1);
void dijkstra(int src)
{  
  set<pair<int,int>> s;
  s.insert({0,src});  
  dist[src]=0;
  while(!s.empty())
  {
    int v=(*s.begin()).S,d=(*s.begin()).F;
    s.erase(s.begin());
    for(auto it: adj[v])
    {
      int to=it.F,currd=it.S;
      if(dist[to]>dist[v]+currd)
      {
        if(s.count({dist[to],to}))
          s.erase(s.find({dist[to],to}));
        dist[to]=dist[v]+currd;
        s.insert({dist[to],to});  
        par[to]=v;
      }  
    }
  }
}
vector<int> path;
for (int v = t; v != s; v = par[v])
  path.push_back(v);
path.push_back(s);
reverse(path.begin(), path.end());
