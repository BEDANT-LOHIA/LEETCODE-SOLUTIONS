class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans =1;
        vector<int>answer;
        answer.push_back(1);
        for(int col=1;col<=rowIndex;col++){
            ans = ans*(rowIndex+1-col);
            ans = ans/col;
            answer.push_back(ans);
        }
        return answer;
    }
};