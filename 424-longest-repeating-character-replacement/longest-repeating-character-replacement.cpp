class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mpp(26,0);
        int n = s.size();
        int l =0;
        int r =0;
        int maxlen = 0;
        int maxfreq = 0;
        while(r<n){
            mpp[s[r] - 'A']++;
            maxfreq = max( mpp[s[r] - 'A'],maxfreq);
            if((r-l+1)-maxfreq > k){
                mpp[s[l] - 'A']--;
                l++;
            }
            if((r-l+1) - maxfreq <=k){
                maxlen = max(r-l+1,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};