void dfs(int v)
{
    tin[v] = timer++;
    col[v] = 1;
    for (int u : adj[v])
        if (col[u] == 0)
            dfs(u);
    color[v] = 2;
    tout[v] = timer++;
}
