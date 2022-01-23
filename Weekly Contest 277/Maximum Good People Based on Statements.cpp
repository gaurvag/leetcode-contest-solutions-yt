#define vvi vector<vector<int>>


int n;
// 2^n * (n^2) 

class Solution {
public:
    bool check(int x, vvi &a){
        for(int i=0;i<n;i++){
            //if the ith person is good, as we have assumed in the permutation we are having in x
            if(x&(1<<i)){ 
                for(int j=0;j<n;j++)
                    // jth person is bad
                    if(a[i][j]==0){ 
                        //but we have assumed jth person to be good
                        if(x&(1<<j)) 
                            return false;
                    }
                    else if(a[i][j]==1){ //jth person is good
                        //but we have again assumed jth person to be bad in our perm. rep. by x
                        if(!(x&(1<<j)))
                            return 0;
                    }
            }
        }
        return 1;
    }
    
    int maximumGood(vvi& a){
        n=a.size(); // number of people
        int ans=0; 
        int limit=(1<<n);
        // 2^n number of permutations
        for(int i=0;i<limit;i++)
            // i -> binary representation of it is telling about the permutation
            if(check(i,a)){
                int cnt=0, x=i;
                // finding no. of 1s in binary rep. of i
                while(x){
                    x=x&(x-1);
                    cnt++;
                }
                ans=max(ans, cnt);
            }
        return ans;
    }
};