// Set Matrix zeroes

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m =matrix[0].size(), col0=1;

        for(int i=0; i<n; i++){

            if(!matrix[i][0]) col0 = 0;

            for(int j=1; j<m; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=1; j--){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }

            if(!col0) matrix[i][0] = 0;
        }

    }

// Pascals Triangle

    vector<vector<int>> generatePascal(int numRows) {
        vector<vector<int>> ans(numRows);
 
        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1);
            for(int j=0; j<=i; j++){
                if(j==0 || j==i) ans[i][j] = 1;
                else{
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }

        return ans;
    }

//Next Permutation

    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;

        for(k=n-2; k>=0; k--){
            if(nums[k] < nums[k+1]) break;
        }

        if(k<0) reverse(nums.begin(), nums.end());
        else{
            for(l=n-1; l>k; l--){
                if(nums[l] > nums[k]) break;
            }

            swap(nums[k], nums[l]);
            reverse(nums.begin()+k+1, nums.end());
        }
    }

// Maximum subarray sum (Kadane's Algo)

    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), sum = 0, maxSum = nums[0];

        for(int i=0; i<n; i++){
                sum += nums[i];
                maxSum = max(sum, maxSum);
                if(sum <0) sum = 0;
        }

        return maxSum;
    }

// Sort an array of 0s, 1s and 2s

    void sortColors(vector<int>& nums) {
        int n=nums.size(), low=0, mid=0, high=n-1;

        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid++], nums[low++]);
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high--]);
            }
        }
    }

// Best time to buy and sell stock

    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0], ans = 0;

        for(int i=1; i<prices.size(); i++){
            mini = min(mini, prices[i]);
            ans  = max(ans, prices[i] - mini); 
        }

        return ans;
    }
