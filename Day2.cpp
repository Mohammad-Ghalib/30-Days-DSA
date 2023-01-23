// Rotate matrix

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }

// Merge intervals

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end());

        vector<int> tempInterval = intervals[0];

        for(auto it : intervals){
            if(it[0] <= tempInterval[1]){
                tempInterval[1] = max(it[1], tempInterval[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }

        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }

// Merge sorted array

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--]; 
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }

        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }

// Find duplicate number

    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return fast;
    }

// Repeat and missing number

    int *findTwoElement(int *arr, int n) {
        int xor1=0;
        for(int i=0; i<n; i++){
            xor1 = xor1^(i+1)^arr[i];
        }
        
        int setBit = xor1 & ~(xor1-1);
        
        int x=0, y=0;
        
        for(int i=0; i<n; i++){
            if(arr[i] & setBit) x = x^arr[i];
            else y = y^arr[i];
            
            if((i+1)  & setBit) x = x^(i+1);
            else y = y^(i+1);
        }
        
        int *ans = new int[2];
        
        for(int i=0; i<n; i++){
            if(arr[i] == x){
                ans[0] = x;
                ans[1] = y;
                return ans;
            }
            else if(arr[i] == y){
                ans[0] = y;
                ans[1] = x;  
                return ans;
            }
        } 
        
        return ans;
    }

// Count inversions using merge sort

    long long int merge( vector<long long>&nums, long long low , long long mid, long long high){
        long long  count =0,k=0;
        int l = low, r = mid+1, size = high-low+1;
        
        vector<long long>sorted(size);
        
        while(l<=mid and r<=high){
            if (nums[l]<= nums[r]){
                sorted[k++] = nums[l++];
            }
            else{
                sorted[k++] = nums[r++];
                count = count + (mid-l + 1);
            }
        }
        while(l<=mid){
            sorted[k++]= nums[l++];
        }
        while(r<=high){
            sorted[k++]= nums[r++];
        }
        
        for(k=0; k < size; k++){
            nums[k+low] = sorted[k];
        }
        
        return count;
    }

    long long int mergeSort(vector<long long>&nums, long long low , long long high){
        long long  inv_count = 0;
        if(low >= high) return 0;
        int mid = low+(high-low)/2;
        inv_count += mergeSort(nums,low,mid);
        inv_count += mergeSort(nums,mid+1,high);
        inv_count += merge(nums,low,mid,high);
        
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N){
        vector<long long>nums;
        for(int i=0;i<N;i++) 
            nums.push_back(arr[i]);
            
        return mergeSort(nums, 0, N-1);
    }
