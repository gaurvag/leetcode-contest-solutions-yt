#define ll long long
class Solution {
public:
    vector<long long> getDistances(vector<int>& a){
        map<ll, vector<ll>> idx;
        map<ll, vector<ll>> presum;
        int n=a.size();
        
        for(int i=0;i<n;i++){
            idx[a[i]].push_back(i);
        }    
  
        for(auto &el:idx){
            vector<ll> sum=el.second;
            int ln=sum.size();
            for(int i=1;i<ln;i++)
                sum[i]+=sum[i-1];
            presum[el.first]=sum;
        }

        vector<ll> ans(n,0);
        
        for(int i=0;i<n;i++){
            
            int el=a[i];
            int id=upper_bound(idx[el].begin(), idx[el].end(), i) - idx[el].begin();
           
            ll sum1=0, sum2=presum[el].back();
            
            ll cnt1=id-1, cnt2=presum[el].size()-id;
            
            if(id-2>=0)
              sum1=presum[el][id-2];
            
            if(id-1>=0)
              sum2-=presum[el][id-1];
            
            ans[i]=((cnt1*i)-sum1) + (sum2 - (cnt2*i)); 
            
        }
        return ans;
    }
};