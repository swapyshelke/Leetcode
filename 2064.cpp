// 2064. Minimized Maximum of Products Distributed to Any Store


class Solution {
public:

    bool isPossible(int n, vector<int> &quantities, int mid) {
        int store = 0;

        for(auto x:quantities) {
            store += x/mid;
            if(x % mid) store++;
            if(store > n) return 0;
        }

        return store <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
       int maxi = 0;
       long long sum = 0;
       for(auto x:quantities){
        sum += x;
        maxi = max(maxi, x);
       }


       int s = sum / n, e = maxi, ans = -1;
       if(s==0) s=1;
       while(s <= e) {
        int mid = s + (e-s) / 2;
        if(isPossible(n, quantities, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
       }

       return ans;
    }
};
