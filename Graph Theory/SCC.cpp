void dfs1(int v) 
{
  vis[v]=1;
  for (int to: g[v])
  {
    if (!vis[to])
      dfs1(to);
  }
  order.push_back(v);
}
void dfs2 (int v) 
{
  vis[v]=1;
  component.push_back(v);
  for (int to: gr[v])
  {
    if (!vis[to])
      dfs2 (to);
  }
}

int main() 
{
  int n;
  ... reading n ...
  for (;;) 
  {
    int a, b;
    ... reading next edge(a,b) ...
    g[a].push_back(b);
    gr[b].push_back(a);
  }
  vis.assign (n,0);
  for (int i=0; i<n; ++i)
    if (!used[i])
      dfs1 (i);
  vis.assign (n, false);
  for(int i=0; i<n; ++i) 
  {
    int v = order[n-1-i];
    if (!used[v]) 
    {
      dfs2 (v);
    ... printing next component ...
    component.clear();
    }
  }
}
