//1 Implement Min/Max heap

//2 Kth Largest element

    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }

//3 Maximum Sum combination

    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> s;
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        pq.push({A[N-1]+B[N-1], {N-1, N-1}});
        s.insert({N-1, N-1});

        vector<int> ans;
        while(!pq.empty() && K--){

            auto it=pq.top();
            pq.pop();
            ans.push_back(it.first);
            
            int x=it.second.first, y=it.second.second;

            if(x>0 && s.find({x-1, y})==s.end() ){
                pq.push({A[x-1]+B[y],{x-1,y}});
                s.insert({x-1,y});
            }
            if(y>0 && s.find({x, y-1})==s.end() ){
                pq.push({A[x]+B[y-1],{x,y-1}});
                s.insert({x,y-1});
            }
        }

        return ans;
    }

//4 Find median from data stream

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }        
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top())/2.0;
    }

//5 Merge K sorted arrays

    class node{
        public:
        int val, arrPos, valPos;
        node(int v,int i,int j){
            val=v, arrPos=i, valPos=j;
        }
    };

    class compare{
        public:
        bool operator()(node*a,node*b){
            return a->val > b->val;
        }
    };

    class Solution{
        public:
        vector<int> mergeKArrays(vector<vector<int>> arr, int K){
            priority_queue<node*,vector<node*>,compare>pq;

            for(int i=0;i<K;i++){
                node*temp=new node(arr[i][0],i,0);
                pq.push(temp);
            }

            vector<int>ans;
            while(!pq.empty()){
                node*curr=pq.top();
                pq.pop();
                ans.push_back(curr->val);
                
                int i=curr->arrPos, j=curr->valPos;
                if(j+1<arr[i].size()){
                    node*t=new node(arr[i][j+1],i,j+1);
                    pq.push(t);
                }
            }
            return ans;
        }
    };

//6  K most frequent elements

    vector<int> topKFrequent(vector<int>& nums, int k) {

        if(nums.size() == k) return nums;
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> ans;
        map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }