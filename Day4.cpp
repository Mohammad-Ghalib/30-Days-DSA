//1 2Sum

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++){
            if(mp[target-nums[i]]){
                return {mp[target-nums[i]]-1, i};
            }

            mp[nums[i]] = i+1;
        }

        return {};
    }

//2 4Sum

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            long long int target3 = (long long int)target - (long long int)nums[i];
            for(int j=i+1; j<n; j++){
                long long int target2 = target3 - (long long int)nums[j];
                int front = j+1, back = n-1;

                while(front < back){
                    long long int sum = (long long int)nums[front] + (long long int)nums[back];
                    if(sum < target2) front++;
                    else if(sum > target2) back--;
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[front]);
                        temp.push_back(nums[back]);
                        ans.push_back(temp);

                        while(front < back && nums[front] == nums[front+1]) front++;
                        while(front < back && nums[back] == nums[back-1]) back--;
                        front++;
                        back--;
                    }
                }

                while(j+1<n && nums[j+1] == nums[j]) j++;
            }

            while(i+1<n && nums[i+1] == nums[i]) i++;
        }

        return ans;
    }

//3 Longest consecutive sequence

    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        
        unordered_set<int> record(nums.begin(),nums.end());
        int res = 1;
        for(int n : nums){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }

//4 Largest subarry with 0 sum

    int maxLen(vector<int>&A, int n){   
        
        map<int, int> mp;
        int sum=0, ans=0;
        
        for(int i=0; i<n; i++){
            sum += A[i];
            if(sum==0) ans = i+1;
            else{
                if(mp.find(sum) != mp.end()) ans = max(ans, i-mp[sum]);
                else mp[sum] = i;
            }
        }
        
        return ans;
    }

//5 Count number of subarrays with a given XOR

    int solve(vector<int> &A, int B) {

        unordered_map<int,int>visited;
        int cpx = 0;
        long long c=0;
        for(int i=0;i<A.size();i++){
            cpx^=A[i];
            if(cpx==B) c++;
            int h = cpx^B;
            if(visited.find(h)!=visited.end()){
                c=c+visited[h];
            }
            visited[cpx]++;
        }
        return c;
    }

//6 Longest Substring without repeat

    int lengthOfLongestSubstring(string s) {
        
        vector < int > mp(256, -1);

        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while (right < n) {
            if (mp[s[right]] != -1)
            left = max(mp[s[right]] + 1, left);

            mp[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;   
    }
