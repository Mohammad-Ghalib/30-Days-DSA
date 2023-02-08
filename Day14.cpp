//1  Next smaller element

    vector<int> help_classmate(vector<int> arr, int n){ 
        stack<int> st;
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() >= arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    } 

//2 LRU cache

    class LRUCache {
    public:
        class node {
            public:
                int key, val;
                node* next;
                node* prev;
                node(int k, int v) {
                    key = k;
                    val = v; 
                }
        };
        
        node* head = new node(-1,-1);
        node* tail = new node(-1,-1);
        
        int cap;
        unordered_map<int, node*>m;
        
        LRUCache(int capacity) {
            cap = capacity;    
            head->next = tail;
            tail->prev = head;
        }
        
        void addnode(node* newnode) {
            node* temp = head->next;
            newnode->next = temp;
            newnode->prev = head;
            head->next = newnode;
            temp->prev = newnode;
        }
        
        void deletenode(node* delnode) {
            node* delprev = delnode->prev;
            node* delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
        }
        
        int get(int key_) {
            if (m.find(key_) != m.end()) {
                node* resnode = m[key_];
                int res = resnode->val;
                m.erase(key_);
                deletenode(resnode);
                addnode(resnode);
                m[key_] = head->next;
                return res; 
            }
        
            return -1;
        }
        
        void put(int key_, int value) {
            if(m.find(key_) != m.end()) {
                node* existingnode = m[key_];
                m.erase(key_);
                deletenode(existingnode);
            }
            if(m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
            }
            
            addnode(new node(key_, value));
            m[key_] = head->next; 
        }
    };

//3 LFU cache

    class LFUCache {
        int cap;
        int size;
        int minFreq;
        unordered_map<int, pair<int, int>> m; //key to {value,freq};
        unordered_map<int, list<int>::iterator> mIter; //key to list iterator;
        unordered_map<int, list<int>>  fm;  //freq to key list;

        public:
        LFUCache(int capacity) {
            cap=capacity;
            size=0;
        }
        
        int get(int key) {
            if(m.count(key)==0) return -1;
            
            fm[m[key].second].erase(mIter[key]);
            m[key].second++;
            fm[m[key].second].push_back(key);
            mIter[key]=--fm[m[key].second].end();
            
            if(fm[minFreq].size()==0 ) 
                minFreq++;
            
            return m[key].first;
        }
        
        void put(int key, int value) {
            if(cap<=0) return;
            
            int storedValue=get(key);
            if(storedValue!=-1)
            {
                m[key].first=value;
                return;
            }
            
            if(size>=cap )
            {
                m.erase( fm[minFreq].front() );
                mIter.erase( fm[minFreq].front() );
                fm[minFreq].pop_front();
                size--;
            }
            
            m[key]={value, 1};
            fm[1].push_back(key);
            mIter[key]=--fm[1].end();
            minFreq=1;
            size++;
        }
    };

//4 Largest histogram in rectangle

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), ans=0;
        vector<int> leftSmallInd(n), rightSmallInd(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) leftSmallInd[i] = 0;
            else leftSmallInd[i] = st.top() + 1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) rightSmallInd[i] = n-1;
            else rightSmallInd[i] = st.top() - 1;
            st.push(i);

            ans = max(ans, (rightSmallInd[i] - leftSmallInd[i] + 1)* heights[i]); 
        }

        return ans;
    }

//5 Sliding window maximum

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]); 
        }

        return ans;
    }

