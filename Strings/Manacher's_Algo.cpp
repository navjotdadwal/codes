// Manachar's Algorithm
vector<int> d1(N);  // for odd length pallindrome 
for(int i=0,l=0,r=-1;i<n;i++)
{
  int k=(i>r)?1:min(d1[l+r-i],r-i+1);
  while(i-k>=0 && i+k<n && s[i-k]==s[i+k])
    k++;
  d1[i]=k--;
  if(i+k>r)
  {
    l=i-k;
    r=i+k;
  }
}
vector<int> d2(N);  // for even length pallindrome
for(int i=0,l=0,r=-1;i<n;i++)
{
  int k=(i>r)?0:min(d2[l+r-i+1],r-i+1);
  while(i-k-1>=0 && i+k<n && s[i-k-1]==s[i+k])
    k++;
  d2[i]=k--;
  if(i+k>r)
  {
    l=i-k-1;
    r=i+k;
  }  
}
