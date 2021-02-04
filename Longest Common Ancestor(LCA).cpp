const int N = 3e5 + 5; 
vector<int> adj[N];
int p[N][35],dp[N][35],A[N][35],level[N];
void dfs(int v,int par)
{
  p[v][0]=par;
  level[v]=level[par]+1;
  for(int i=0;i<=30;i++)
    dp[v][i]+=dp[par][i]+A[v][i];
  for(int to: adj[v])
  {
    if(to==par) continue;
    dfs(to,v);  
  }  
}
void precompute(int n)
{ 
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=18;j++)
      p[i][j]=p[p[i][j-1]][j-1];  
  }  

int calc_LCA(int x,int y)
{
  if(level[x]>level[y]) swap(x,y);
  int diff=level[y]-level[x];
  for(int i=0;i<=30;i++)
  {
    if((diff)&(1<<i))
      y=p[y][i];  
  }
  if(y==x)
    return y;
  for(int i=0;i<=30;i++)
  {
    if(p[x][i]!=p[y][i])
      x=p[x][i],y=p[y][i];  
  }  
  return p[x][0];
}