class Solution
{
public:
    vector<int> recoverArray(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int n = a.size();

        set<int> pot;  //potential values of k
        
        int i = 0; 
        for (int j = 1; j < n; j++)
        {
            int sum = a[i] + a[j];
            int k = sum / 2 - a[i];
            if (sum % 2 == 0 && k > 0)
                pot.insert(k);
        }
        

        vector<int> st;
        for (auto el : pot)
            st.push_back(el);
        

        map<int, int> freq1, freq;
        
        for (auto el : a)
            freq1[el]++;
        

        for (auto k : st) //O(N) 
        {

            freq = freq1;
            vector<int> ans;

            for (int i = 0; i < n; i++) //O(NLOGN)
            {
                if (freq[a[i]])
                {
                    if (freq.find(a[i] + 2 * k) != freq.end() && freq[a[i] + 2 * k])
                    {
                        ans.push_back(a[i] + k);
                        freq[a[i]]--;
                        freq[a[i] + 2 * k]--;
                    }
                }
            }

            if (ans.size() == n / 2)
                return ans;
        }
        

        vector<int> x;
        return x;
        
    }
};