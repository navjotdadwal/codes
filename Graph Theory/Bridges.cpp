set<pair<int,int>> s;
void dfs(int v,int p)
{
  vis[v]=1;
  tin[v]=low[v]=timer++;
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
      if(low[v]<tin[to])
        s.insert({to,v});
    } 
  }
}
for(int i=1;i<=n;i++)
{
  if(!vis[i])
  {
    dfs(i);
  }
}
