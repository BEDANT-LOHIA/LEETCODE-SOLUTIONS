class Solution {
public:
    int candy(vector<int>& ratings) {
       int i = 1;
       int sum  = 1;
       int n = ratings.size();
       while(i<n){
        if(ratings[i]==ratings[i-1]){
            sum += 1;
            i++;
            continue;
        }
        int peak = 1;
        while(i<n && ratings[i]>ratings[i-1]){
            peak = peak+1;
            sum = sum+peak;
            i++;
        }
        int down = 0;
        while(i<n && ratings[i]<ratings[i-1]){
            down = down+1;
            sum = sum+down;
            i++;
        }
        if(peak<=down)
        sum = sum + (down-peak+1);
       }
       return sum;
    }
};