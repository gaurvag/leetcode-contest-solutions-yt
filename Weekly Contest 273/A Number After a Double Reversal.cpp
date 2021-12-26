class Solution {
public:
    bool isSameAfterReversals(int num){
        
        string str=to_string(num);
        
        reverse(str.begin(), str.end());
        
        int x=stoi(str); //reversed1
        
        str=to_string(x);
        
        reverse(str.begin(), str.end());
        
        x=stoi(str); //reversed2
        
        return x==num;
    }
};