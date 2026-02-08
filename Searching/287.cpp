class Solution {
public:
    bool ans(vector<int>&nums,int mid){
        unordered_set<int>a;
        for(int i=0;i<=mid;i++){
            a.insert(nums[i]);
        }
        return a.size()<(mid+1);
    }
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1)
	  {
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;

    }
};
