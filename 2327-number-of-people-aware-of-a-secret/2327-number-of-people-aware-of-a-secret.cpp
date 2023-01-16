class Solution {
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>person(n+1,0);
        person[1]=1;
        long long numberOfPeopleSharingSecret=0;
        for(int i=2;i<=n;i++){
            if(i-delay>=0){
                numberOfPeopleSharingSecret=(numberOfPeopleSharingSecret+ person[i-delay])%mod;
            }
            if(i-forget>=0){
                numberOfPeopleSharingSecret=(numberOfPeopleSharingSecret- person[i-forget]+mod)%mod;
            }
            person[i]=numberOfPeopleSharingSecret;
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+person[i])%mod;
        }
        return ans;
    }
};