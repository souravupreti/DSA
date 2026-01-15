class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }
        if(arr2.size()==0){
            for(int i=0;i<nums.size();i++){
                nums[i]=nums[i]*nums[i];
            }
            return nums;
        }
        if(arr1.size()==0){
            for(int i=0;i<nums.size();i++){
                nums[i]=nums[i]*nums[i];
            }
            reverse(nums.begin(),nums.end());
            return nums;
        }

        for(int i=0;i<arr1.size();i++){
            arr1[i]*=arr1[i];
        }
        for(int i=0;i<arr2.size();i++){
            arr2[i]*=arr2[i];
        }
        int i=0;
        int j=arr2.size()-1;

        while(i<arr1.size()&&j>=0){
            if(arr1[i]<arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j--;
            }
        }
        while(i<arr1.size()){
            ans.push_back(arr1[i]);
                i++;
        }
        while(j>=0){
            ans.push_back(arr2[j]);
                j--;
        }
        return ans;
    }
};