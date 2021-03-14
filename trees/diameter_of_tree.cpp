int diam = 0,depth[N];
int dfs(int x, int p)
{
  int len = 0;
  for(int y : adj[x])
  {
    if(y != p)
    {
      depth[y] = depth[x] + 1;
      int cur = 1 + dfs(y, x);
      diam = max(diam, cur + len);
      len = max(len, cur);
    }
  }
  return len;
}
