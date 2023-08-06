//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int A[], int low, int mid, int high)
    {
         // Your code here
         int i=low;
         int j=mid+1;
         int idx=0;
         int temp[high-low+1];
         
         while(i<=mid && j<=high)
         {
             if(A[i]<=A[j])
             {
                 temp[idx++]=A[i++];
             }
             else
             {
                 temp[idx++]=A[j++];
             }
         }
         while(j<=high)
         {
             temp[idx++]=A[j++];
         }
         while(i<=mid )
         {
             temp[idx++]=A[i++];
         }
         
         idx=0;
         for(int k=low ; k<=high ; k++)
         {
             A[k]=temp[idx++];
         }
    }
    public:
    void mergeSort(int arr[], int l, int h)
    {
        //code here
        if(l<h)
        {
            int mid=l+(h-l)/2;
            
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,h);
            merge(arr,l,mid,h);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends