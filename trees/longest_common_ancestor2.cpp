int level[N],tout[N],tin[N],dtime;
vector<vector<int>> p;
void dfs(int n,int par)
{
    tin[n]=dtime++;
    level[n]=(par==-1)?0:1+level[par];
 
    p[n][0]=par;
    for(int i=1;i<=20;i++)
    {
        if(p[n][i-1]!=-1)
        {
            p[n][i]=p[p[n][i-1]][i-1];
        }
    }
 
    for(int c:adj[n])
    {
        if(c==par) continue;
        dfs(c,n);
    }
 
    tout[n]=dtime++;
}
bool isanc(int u,int v)
{
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}
 
int calc_LCA(int u,int v)
{
    if(isanc(u,v)) return u;
    if(isanc(v,u)) return v;
    for(int i=20;i>=0;i--)
    {
        if(p[u][i]!=-1 && !isanc(p[u][i],v)) u=p[u][i];
    }
    return p[u][0];
}
