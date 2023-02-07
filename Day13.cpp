//1 Implement a stack using arrays

    void MyStack :: push(int x){
        arr[++top] = x;
    }

    int MyStack :: pop(){
        if(top == -1) return -1;
        return arr[top--];
    }

//2 Implement a queue using arrays

    void MyQueue :: push(int x){
            arr[rear++] = x;
    }

    int MyQueue :: pop(){
            if(front == rear) return -1;
            return arr[front++];
    }

//3 Implement stack using queue

    queue<int> q;
    
    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=1; i<n; i++){
            q.push(q.front());
            q.pop();      
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {return q.front();}
    
    bool empty() {return q.empty();}

//4 Implement queue using stacks

    stack<int> in, out;

    void push(int x) {in.push(x);}
    
    int pop() {
        if(!out.empty()){
            int temp = out.top();
            out.pop();
            return temp;
        }
        
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        int temp = out.top();
        out.pop();
        return temp;         
    }
    
    int peek() {
        if(!out.empty()) return out.top();
        
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        return out.top(); 
    }
    
    bool empty() { return in.empty() & out.empty();}

//5 Check for balanced parentheses

    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else if(st.empty()) return false;
            else{
                if(s[i]==')' && st.top()=='(') st.pop();
                else if(s[i]=='}' && st.top()=='{') st.pop();
                else if(s[i]==']' && st.top()=='[') st.pop();
                else return false;
            }
        }
        return st.empty();
    }

//6 Next greater element

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]) st.pop();
            
            if(i<n){
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }

            st.push(nums[i%n]);
        }

        return ans;
    }

//7 Sort a stack

void insert(stack<int>& s, int x){
    
    if(s.empty() || x > s.top()){
        s.push(x);
        return;
    }
 
    int temp = s.top();
    s.pop();
    insert(s, x);
 
    s.push(temp);
}

void SortedStack :: sort() {
    
    if(!s.empty()){
        int temp = s.top();
        s.pop();
        sort();
        insert(s,temp);
    }
}