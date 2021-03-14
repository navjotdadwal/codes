const int N = 2e5 + 5;  
// query structure
struct query{
  int l;
  int r;
  int idx;
};  

int ar[N],ans[N];
int fre[N];
int cnt=0;

// Sorting 
int BLK = 700;
bool comp(query a, query b)
{
  if(a.L/BLK != b.L/BLK)
  return a.L/BLK <= b.L/BLK;

  else 
  return a.R <= b.R;
}
void add(int pos)
{
  fre[ar[pos]]++;
  if(fre[ar[pos]]==1)
  cnt++;
}
void remove(int pos)
{
  fre[ar[pos]]--;
  if(fre[ar[pos]]==0)
  cnt--;
}
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      int n,q;
      cin>>n;
      for(int i=0;i<n;i++)
        cin>>ar[i];
      cin>>q;
      for(int i=0;i<q;i++)
      {
        cin>>Q[i].l>>Q[i].r;
        Q[i].idx=i;
        Q[i].l--,Q[i].r--;
      }       
      sort(Q,Q+q,comp);

      int ML=0,MR=-1;
      for(int i=0;i<q;i++)
      {
        int L=Q[i].l;
        int R=Q[i].r;
        
        while(MR<R)
          MR++,add(MR);
        while(ML>L)
          ML--,add(ML);

        while(ML<L)
          remove(ML),ML++;
        while(MR>R)
          remove(MR),MR--;
        
        ans[Q[i].i]=cnt;
      }
      for(int i=0;i<q;i++)
        cout<<ans[i]<<"\n";
    }
    return 0;
}
