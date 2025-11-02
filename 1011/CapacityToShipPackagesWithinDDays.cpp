class Solution {
public:
    // binary search
    // we need x, f(x) and target
    // x -> variable that we need to find (weight capacity)
    // f(x) -> monotonic function (as weight increases, days decrease)
    // target = left boundary of days
    // first we write a function for f(x)
    // this functions finds how many days it takes with a given weight cap
    // and weights array
    int function(vector<int>& weights, int cap){
        int days = 0;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++){
            if ((sum + weights[i]) <= cap){
                sum += weights[i];
            }else{
                days++;
                sum = weights[i];
            }
        }
        return days + 1;
    }
    // now we want to find minimum weight cap that will ship within some days
    int shipWithinDays(vector<int>& weights, int days) {
        // smallest weight should be largest value in weights array
        // largest should be the sum
        int l = 0;
        int r = 1;
        for (int w : weights) {
            l = std::max(l, w);
            r += w;
        }
        while(l <= r){
            int mid = l + (r - l)/2;
            if (function(weights, mid) > days){
                // [left, mid - 1]
                l = mid + 1;
            }else if (function(weights, mid) < days){
                // [mid + 1, right]
                r = mid - 1;
            }else if (function(weights, mid) == days){
                // we want to find left boundary
                r = mid - 1;
            }
        }
        
        return l;
    }
};