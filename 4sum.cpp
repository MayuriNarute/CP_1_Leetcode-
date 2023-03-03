class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
     vector<vector<int>>ansbda;
    if (nums.empty())
        return ansbda;
    int i,j;
    sort(nums.begin(),nums.end());
    for( i=0;i<n;i++){
        long long target_3 = target - nums[i];
        for(j=i+1;j<n;j++ ){
            long long target2 = target_3 - nums[j];
            int left=j+1;
            int right=n-1;
            while(left<right){
                long long  two_Sum=nums[left]+nums[right];
                if(two_Sum<target2)
                    left++;
                else if(two_Sum>target2)
                    right--;
                else {
                    vector<int>ans(4,0);
                    ans[0]=nums[i];
                    ans[1]=nums[j];
                    ans[2]=nums[left];
                    ans[3]=nums[right];
                    ansbda.push_back(ans);
                    
                    while((left<right)&&(nums[left]==ans[2]))
                        left++;
                    while((left<right)&&(nums[right]==ans[3]))
                        right--;
                }
            }
            while(j+1<n&&nums[j+1]==nums[j])
                j++;
            while(i+1<n&&nums[i+1]==nums[i])
                i++;
        }
    }
    return ansbda;
}
};
