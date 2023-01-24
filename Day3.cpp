//1 Search in a 2D matrix

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo=0, hi=m*n-1, mid;

        while(lo <= hi){
            mid = (lo+hi)/2;

            if(target > matrix[mid/n][mid%n]){
                lo = mid+1;
            }
            else if(target < matrix[mid/n][mid%n]){
                hi = mid -1;
            }
            else{
                return true;
            }
        }

        return false;
    }

//2 Pow(x,n)

    double myPow(double x, int n) {
        long long nn = n;
        if(n<0) nn = -1*nn;
        double ans = 1.0;

        while(nn){
            if(nn%2) ans *= x;
    
            x *= x;
            nn /= 2;
        }

        if(n<0) return 1.0/ans;
        return ans;
    }   

//3 Majority element occours more than n/2

    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=0;

        for(int i=0; i<nums.size(); i++){
            if(!count){
                element = nums[i];
            }

            if(nums[i] == element) count++;
            else count--;
        }

        return element;
    }

//4 Majority element occours more than n/3

    vector<int> majorityElement(vector<int>& nums) {
        int count1=0, count2=0, ele1=-1, ele2=-1; 

        for(int i=0; i<nums.size(); i++){
            if(ele1 == nums[i]) count1++;
            else if(ele2 == nums[i]) count2++;
            else if(!count1){
                ele1 = nums[i];
                count1 = 1;
            }
            else if(!count2){
                ele2 = nums[i];
                count2 = 1;
            }

            else{
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        count1 = count2 = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
        }

        if(count1 > nums.size()/3) ans.push_back(ele1);
        if(count2 > nums.size()/3) ans.push_back(ele2);

        return ans;
    }

//5 Unique paths

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(i==1 && j==1) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m][n];
    }

//6 Reverse pairs

    int Merge(vector < int > & nums, int low, int mid, int high) {
        int total = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            total += (j - (mid + 1));
        }

        vector < int > t;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                t.push_back(nums[left++]);
            } else{
                t.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            t.push_back(nums[left++]);
        }
        while (right <= high) {
            t.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = t[i - low];
        }
        return total;
    }

    int MergeSort(vector < int > & nums, int low, int high){

        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int inv = MergeSort(nums, low, mid);
        inv += MergeSort(nums, mid + 1, high);
        inv += Merge(nums, low, mid, high);
        return inv;
    }

    int reversePairs(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size()-1);
    }