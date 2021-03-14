int getMin(int l,int r)
{
  int LB = l / BLK;  // LB->left block BLK->block size
  int RB = r / BLK;
  int mn = inf;
  if(LB == RB)
  for(int i=l;i<=r;i++)
  mn = min(ar[i] , mn);

  else 
  {
    for(int i=l;i<BLK*(LB+1);i++)
    mn = min(mn , ar[i]);
    
    for(int i=LB+1;i<RB;i++)
    mn = min(mn , F[i]);

    for(int i=BLK*RB;i<=r;i++)
    mn = min(mn , ar[i]);
  }
  
  return mn;
}
