const int N = 200001;
int t[4*N];
void update(int v,int tl,int tr,int id,int val)  // tl and tr is the node range
{
  if(tl==id && tr==id)
  {
    t[v]=val;
      return;
  }
  if(id>tr || id<tl)  // outside node range
  {
    return;
  }
  int tm=(tl+tr)/2;   // tl->tm and tm+1->tr
  update(2*v,tl,tm,id,val);
  update(2*v+1,tm+1,tr,id,val);
  t[v] = t[2*v] + t[2*v+1];
}
int query(int v,int tl,int tr,int l,int r) // l and r is the query range
{
  // Case 1 - No Overlap
  if(tl>r || tr<l) 
    return 0;
  // Case 2 - Full Overlap
  if(l<=tl && tr<=r)
    return t[v];
  // Case 3 - Partial overlap
  int tm=(tl+tr)/2;
  int ans=0;
  ans+=query(2*v,tl,tm,l,r);
  ans+=query(2*v+1,tm+1,tr,l,r);
  return ans;
}
