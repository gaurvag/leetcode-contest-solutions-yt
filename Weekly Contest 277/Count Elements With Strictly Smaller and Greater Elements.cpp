class Solution {
public:
    int countElements(vector<int>& a){
        map<int, int> freq;
        for(auto el:a)
            freq[el]++;
        vector<int> b;
        for(auto el:freq)
            b.push_back(el.second);
        int ln=b.size();
        int ans=0;
        for(int i=1;i<ln-1;i++)
            ans+=b[i];
        return ans;
    }
};