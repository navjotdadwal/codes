const int N = 1e5 + 5;

int t[4*N];
// this stores the sum

bool lazy[4*N]; // tells if certain node is storing unpropagated node or not
int upd[4*N]; // the value of unpropagated updates

// this is the process of telling the man to remember the val
void apply(int v,int tl,int tr,int val)
{
  t[v]+=val*(tr-tl+1);  // set correct information at the node
  if(tl!=tr) // if it is non lazy mark it lazy
  {
    lazy[v]=1;
    upd[v]+=val;  
  }
}
// assigning the task to his employees
void pushdown(int v,int tl,int tr)
{
  if(lazy[v])  // if it is lazy propagate it 
    lazy[v]=0;  // not lazy anymore
  int tm=(tl+tr)/2;     
  apply(2*v,tl,tm,upd[v]);  // propagate on the left child
  apply(2*v+1,tm+1,tr,upd[v]);  //  propagate on the right child 
  upd[v]=0;  // update done
}
// l,r is the updaet range
// val is the update val, add this  to all leaves in the range [l,r]
void update(int v,int tl,int tr,int l,int r,int val)  // tl and tr is the node range
{
  if(tl>r || tr<l)  // no overlap
    return;
  if(l<=tl && tr<=r)  // fully within
  {
    apply(v,tl,tr,val);  
    return;
  }
  // partial overlap
  pushdown(v,tl,tr); // we remove the lazy tag before going down
  // why? so the children have correct information

  int tm=(tl+tr)/2;
  update(2*v,tl,tm,l,r,val);
  update(2*v+1,tm+1,tr,l,r,val);

  t[v]=t[2*v]+t[2*v+1];  // store correct val at this node
}
int query(int v,int tl,int tr,int l,int r) // l and r is the query range
{
  // Case 1 - No Overlap
  if(tl>r || tr<l) 
    return 0;
  // Case 2 - Full Overlap
  if(l<=tl && tr<=r)
    return t[v];
  
  pushdown(v,tl,tr); // we are removing the lazy tag before going down
  // why? so that the children have correct information
  // Case 3 - Partial overlap
  int tm=(tl+tr)/2;
  int ans=0;
  ans+=query(2*v,tl,tm,l,r);
  ans+=query(2*v+1,tm+1,tr,l,r);
  return ans;
}
