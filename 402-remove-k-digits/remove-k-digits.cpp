class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        if(num.size() == k)
            return "0";
        for(int i=0;i<num.size();i++){
            while((!ans.empty()) && k>0 && (ans.back() > num[i])){
                ans.pop_back();
                k--;
            }
            if(ans.empty() && num[i] == '0')
                continue;
            ans.push_back(num[i]);
        }
        while(!ans.empty() && k>0){
            ans.pop_back();
            k--;
        }
        if(ans.empty())
            return "0";
        else
            return ans; 
    }
};