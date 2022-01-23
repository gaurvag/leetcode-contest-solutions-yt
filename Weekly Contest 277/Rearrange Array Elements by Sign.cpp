class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums){
        vector<int> a,b;  
        // a-> +ve integers
        // b-> -ve integers
        int n=nums.size();
        for(auto el:nums){
            if(el>0)
                a.push_back(el);
            else 
                b.push_back(el);
        }
        
        vector<int> ans;
        
        int i=0, j=0;
        // i -> a vector, j -> b vector
        int time=0;
        while(n--){
            if(!time)
                ans.push_back(a[i++]);
            else 
                ans.push_back(b[j++]); 
            time=1-time; //0 -> 1 -> 0 
        }
       return ans;
    }  
};