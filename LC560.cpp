class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cur_sum = 0;
        unordered_map<int, int> d_{{0,1}};
        
        int res=0;
        for (int i=0; i<nums.size(); i++) {
            cur_sum+=nums[i];
            auto it = d_.find(cur_sum-k);
            if (it!=d_.end())
              res+=it->second;
            d_[cur_sum]==0?d_[cur_sum]=1:d_[cur_sum]++;
        }
        return res;
    }
};
