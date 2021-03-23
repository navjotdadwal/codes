void dfs(int v)
{
  vis[v]=1;
  for(int to: adj[v])
  {
    if(!vis[to])
      dfs(to);  
  }
}
