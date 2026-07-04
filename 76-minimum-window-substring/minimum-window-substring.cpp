class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sindex = -1;
        int minlen = INT_MAX;
        int n = s.size();
        int m = t.size();
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n){
           if(mpp[s[r]]>0){
            cnt++;
           }
           mpp[s[r]]--;
           while(cnt == m){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    sindex = l;
                }
            mpp[s[l]]++;
            if(mpp[s[l]]>0)
                cnt--;
            l++;
           }
           r++;
        }
        return sindex == -1 ? "" : s.substr(sindex,minlen);
    }
};