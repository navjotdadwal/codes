const int N = 1e6;
vector<int> dist(N,inf);
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=n;j++)
  {
    for(int k=1;k<=n;k++)
    {
      dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
  }
}
