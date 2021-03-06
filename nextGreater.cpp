vector<int> nextgreater(vector<int> h)
{
  vector<int> v(h.size()+1,-1);
  stack<int> st;
  for(int i=(int)h.size()-1;i>=0;i--)
  {
    while(!st.empty() && h[st.top()]<=h[i])
       st.pop();
    if(!st.empty())
       v[i]=st.top();
    st.push(i);
  }
  return v;
}
