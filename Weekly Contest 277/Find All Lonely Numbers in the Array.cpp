class Solution {
public:
    vector<int> findLonely(vector<int>& a){
        map<int, int> freq;
        for(auto el:a)
            freq[el]++;
        
        vector<int> ans;
        
        for(auto &el:freq){
            int x=el.first;
            if(el.second==1){
               if(freq.find(x+1)==freq.end() && freq.find(x-1)==freq.end())   
                   ans.push_back(x);
            }
        }
        return ans;
    }
};