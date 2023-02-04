//1 Nth root of an integer

	int NthRoot(int n, int m){    
	    if(n==1 || m==1 || m==0) return m;
	    long long int low = 1, high=m, mid=1, num=n, ans;
	    
	    while(high >= low){
	        mid = (low+high)/2, ans=1, num=n;
	        while(num--){
	            ans *= mid;
	            if(ans>m) break;
	        }
	        
	        if(ans == m) return mid;
	        else if(ans > m) high = mid-1;
	        else low = mid+1;
	    }
	    return -1;
	} 

//2 Matrix median

    int countSmallerThanMid(vector<int> &row, int mid){
        int l = 0, h = row.size() - 1;
        while (l <= h){
            int md = (l + h) >> 1;
            if (row[md] <= mid) l = md + 1;
            else h = md - 1;
        }
        return l;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int low = 1, high = 1e9;
        while (low <= high){
            int mid = (low + high) >> 1, cnt = 0;
            for (int i=0; i<R; i++){
                cnt += countSmallerThanMid(matrix[i], mid);
            }
            if (cnt <= (R*C)/2) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }

//3 Single element in a sorted array

    int singleNonDuplicate(vector<int>& nums){
        int low = 0, high = nums.size() - 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;                
            if (nums[mid] == nums[mid^1]) low = mid + 1;
            else high = mid - 1;
        }
        return nums[low];
    }

//4 Search in Rotated Sorted array

    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1, mid;

        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else{
                if(target >= nums[mid] && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }

//5 Median of 2 sorted arrays 
 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        
        int m = nums1.size(), n = nums2.size();
        int low=0,high=m,medianPos=((m+n)+1)/2;
        while(low<=high){
            int cut1 = (low+high)>>1;
            int cut2 = medianPos - cut1;
            
            int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
            int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1) {
                if((m+n)%2 != 0) return max(l1,l2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1+1;
        }
        return 0.0;
    }

//6 Kth element of two sorted arrays

    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        if(n>m) return kthElement(arr2, arr1, m, n, k);
        
        int low = max(0,k-m), high = min(k,n);
            
        while(low <= high) {
            int cut1 = (low + high) >> 1; 
            int cut2 = k - cut1; 
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
            int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
                
            if(l1 <= r2 && l2 <= r1) return max(l1, l2);
            else if (l1 > r2) high = cut1 - 1;
            else low = cut1 + 1; 
        }
        return 1; 
    }

//7  Allocate minimum number of pages

    int isPossible(int A[], int N, int pages, int students) {
        int cnt = 0;
        int sumAllocated = 0;
        for (int i = 0; i < N; i++) {
            if (sumAllocated + A[i] > pages) {
                cnt++;
                sumAllocated = A[i];
                if (sumAllocated > pages) return false;
            } 
            else sumAllocated += A[i];
        }
        if (cnt < students) return true;
        return false;
    }
    
    int findPages(int A[], int N, int M) {
        if (M > N) return -1;
        int low = A[0];
        int high = 0;

        for (int i = 0; i < N; i++) {
            high = high + A[i];
            low = min(low, A[i]);
        }

        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isPossible(A, N, mid, M)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

//8 Aggressive Cows

