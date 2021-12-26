class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& strt, string s) {
        int m=s.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int j=i;
            int x=strt[0], y=strt[1]; //starting coordinates
            while(j<m && x>=0 && x<n && y>=0 && y<n){
                char ch=s[j++];
                if(ch=='L'){
                    y--;
                    if(x>=0 && x<n && y>=0 && y<n)
                        ans[i]++;
                }
                else if(ch=='R'){
                    y++;
                    if(x>=0 && x<n && y>=0 && y<n)
                        ans[i]++;
                }
                else if(ch=='U'){
                    x--;
                    if(x>=0 && x<n && y>=0 && y<n)
                        ans[i]++;
                }
                else{ //down
                    x++;
                    if(x>=0 && x<n && y>=0 && y<n)
                        ans[i]++;
                }
            }
        }
        return ans;
    }
};