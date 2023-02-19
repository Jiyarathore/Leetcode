//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    //comparotor function for sorting jobs
    static bool comp(Job a, Job b){
        return (a.profit>b.profit);
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        //sort all jobs according to decreasing order of profit
        sort(arr, arr+n, comp);
        
        // int result[n]; // to store result ( sequence of jobs)
        bool slot[n]; //to keep track of free time slots
        
        int day=0,profit =0;
        
        //initialase all slots to be free
        for(int i=0;i<n;i++){
            slot[i]=false;
        }
        
        //Iterate through all given jobs
        for(int i=0;i<n;i++){
            // find a free slot for this job (Note that we start from last possible slot)
            
            for(int j=min(n , arr[i].dead)-1;j>=0;j--){
                // free slot found
                
                if(slot[j]==false){
                    // result[j]=i; // add this job to result;
                    
                    day+=1;
                    profit+=arr[i].profit;
                    slot[j]=true; // make thsi slot occupied
                    break;
                }
            }
        }
        
        return {day, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends