void dfs(int v)
{
  vis[v]=1;
  for(int to: adj[v])
  {
    if(!vis[to])
      dfs(to);  
  }  
}
int comp=0;
for(int i=1;i<=n;i++)
{
  if(!vis[i])
  {
    dfs(i);
    comp++;  
  }
}
