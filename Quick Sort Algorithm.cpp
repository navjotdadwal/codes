//  Quick Sort Algorithm

int partition(int low,int high)
{
  int i=low-1,pivot=high;
  for(int j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(arr[i],arr[j]);  
    } 
  }  
  swap(arr[i+1],arr[pivot]);
  return i+1;
}
void quick_sort(int low,int high)
{
  if(low<high)
  {
    int pivot=partition(low,high);

    quick_sort(low,pivot-1);
    quick_sort(pivot+1,high);  
  }  
}
