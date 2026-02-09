class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res =0;
        int left = 0;
        deque<int>mq,mn;
        for(int right =0;right<n;right++){
            while(!mq.empty()&&nums[mq.back()]<=nums[right]){
                mq.pop_back();
            }
            mq.push_back(right);
            while(!mn.empty()&&nums[mn.back()]>=nums[right]){
                mn.pop_back();
            }
            mn.push_back(right);
            while(left<=right&&(1LL*(right-left+1)*(nums[mq.front()]-nums[mn.front()])>k)){
                if(mq.front()==left){
                    mq.pop_front();
                }
                if(mn.front()==left){
                    mn.pop_front();
                }
                left++;
            }
            res+=(right-left+1);
        }
        return res;
    }
};
