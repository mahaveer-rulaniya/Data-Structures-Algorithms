class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        unordered_map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                auto itr = mp.find(target-nums[i]);
                res.push_back(itr->second);
                
                res.push_back(i);
                break;
            }
            
            mp.insert({nums[i], i});
        }
        
        return res;
    }
};