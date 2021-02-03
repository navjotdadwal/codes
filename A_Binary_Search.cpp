int x;
cin>>x;
bool flag=false;
int l=0,r=n-1;
while(l<=r)
{
  int mid=(l+r)/2;
  if(a[mid]==x)
  {
    cout<<"YES\n";
    flag=true;
    break;
  }
  else if(a[mid]>x)
    r=mid-1;
  else 
   l=mid+1;
}
if(!flag)
  cout<<"NO\n";
