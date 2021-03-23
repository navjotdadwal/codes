vector<int> cut_vertex;
void dfs(int v,int p)
{
  vis[v]=1;
  tin[v]=low[v]=timer++;
  int child=0;
  for(int to: adj[v])
  {
    if(to==p) continue;
    if(vis[to])
    {
      low[v]=min(low[v],tin[to]);
    } 
    else 
    {
      dfs(to);  
      low[v]=min(low[v],low[to]);
      if(low[to]<=tin[v] && p!=-1)
        cut_vertex.pb(v);
      child++;
    } 
  }
  if(p==-1 && child>1)
    cut_vertex.pb(v);
}
for(int i=1;i<=n;i++)
{
  if(!vis[i])
  {
    dfs(i,-1);
  }
}
