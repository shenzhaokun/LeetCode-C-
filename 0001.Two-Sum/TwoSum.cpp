class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m_map;
        vector<int> res(2,0);
        for (int i = 0 ; i < nums.size(); ++i){
            if (m_map.count(target-nums[i])){
                res = {m_map[target-nums[i]], i};
            }
            m_map.insert(make_pair(nums[i], i));
        }
        return res;
    }
};
