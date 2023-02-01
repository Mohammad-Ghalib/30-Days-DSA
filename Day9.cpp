//1 Subset sums

    void solve(int ind, vector<int>& arr, vector<int>& ans, int sum){
        if(ind<0){
            ans.push_back(sum);
            return;
        }
        
        solve(ind-1, arr, ans, sum+arr[ind]);
        solve(ind-1, arr, ans, sum);
    }

    vector<int> subsetSums(vector<int> arr, int N){
        int n = arr.size();
        vector<int> ans;
        solve(n-1, arr, ans, 0);
        return ans;
    }

//2 Subsets II

    void solve(int ind, vector<int>& nums, vector<int>& temp, set<vector<int>>& ans){
        if(ind<0){
            ans.insert(temp);
            return;
        }

        solve(ind-1, nums, temp, ans);
        temp.push_back(nums[ind]);
        solve(ind-1, nums, temp, ans);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end(), greater<int>());

        solve(n-1, nums, temp, ans);

        return vector(ans.begin(), ans.end());        
    }

//3 Combination sum I

    void solve(int ind, int tar, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans){

        if(tar==0){
            ans.push_back(temp);
            return;
        }
        if(ind<0) return;

        if(candidates[ind] <= tar){
            temp.push_back(candidates[ind]);
            solve(ind, tar-candidates[ind], candidates, temp, ans);
            temp.pop_back();
        }

        solve(ind-1, tar, candidates, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();

        solve(n-1, target, candidates, temp, ans);
        return ans;
    }

//4 Combination sum II

    void solve(int ind, int tar, vector<int>& candidates, vector<int> temp, set<vector<int>>& ans){

        if(tar==0){
            ans.insert(temp);
            return;
        }
        if(ind<0) return;

        if(candidates[ind] <= tar){
            temp.push_back(candidates[ind]);  
            solve(ind-1, tar-candidates[ind], candidates, temp, ans);
            temp.pop_back();

            int i=ind-1; 
            while(i>=0 && candidates[i] == candidates[ind]) i--;
            solve(i, tar, candidates, temp, ans);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end(), greater<int>());

        solve(n-1, target, candidates, temp, ans);
        return vector(ans.begin(), ans.end());
    }

//5 Palindrome partitining

    bool isPal(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    void solve(int ind, string s, vector<string>& temp, vector<vector<string>>& ans){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPal(s, ind, i)){
                temp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(0, s, temp, ans);
        return ans;
    }

//6 Kth permutation sequence

    string getPermutation(int n, int k) {
        int fact = 1;
        vector < int > numbers;

        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }

        numbers.push_back(n);
        string ans = "";
        k = k - 1;
        
        while (true) {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0) break;

            k = k % fact;
            fact = fact / numbers.size();
        }

        return ans;
    }