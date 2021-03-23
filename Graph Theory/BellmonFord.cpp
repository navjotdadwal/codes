for (int i = 1; i <= n; i++) 
  dist[i] = INF;
distance[x] = 0;
for (int i = 1; i <= n-1; i++) 
{
  for (auto e : edges) 
  {
    int a, b, w;
    tie(a, b, w) = e;
    dist[b] = min(dist[b], dist[a]+w);
  }
}
