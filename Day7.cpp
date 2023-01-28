//1 Rotate LL

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;

        ListNode *curr = head;
        int length=1;

        while(curr->next && length++) curr = curr->next;

        curr->next = head;
        k = length - (k%length);

        while(k--) curr = curr->next;

        head = curr->next;
        curr->next = NULL; 

        return head;
    }

//2 Clone LL with random and next pointer

    Node* copyRandomList(Node* head) {
        Node *newHead, *l1, *l2;
        if (!head) return NULL;
        for(l1 = head; l1; l1 = l1->next->next) {
            l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
        }
            
        newHead = head->next;
        for(l1 = head; l1; l1 = l1->next->next) {
            if (l1->random) l1->next->random = l1->random->next;
        }
            
        for(l1 = head; l1; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next) l2->next = l2->next->next;
        }

        return newHead;
    }

//3 3Sum

    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i=0; i<nums.size()-2; i++){
            
            if(i==0 || (i>0 && nums[i] != nums[i-1])){

                int low = i+1, high = nums.size()-1, sum = -nums[i]; 

                while(low<high){
                    if(nums[low] + nums[high] == sum){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[low]);
                        v.push_back(nums[high]);
                        ans.push_back(v);

                        while(low < high && (nums[low] == nums[low+1])) low++;
                        while(low < high && (nums[high] == nums[high-1])) high--;

                        low++;
                        high--;
                    }
                    else if (nums[low] + nums[high] > sum) high--;
                    else low++;
                }
            }
        }

        return ans;
    }

//4 Trapping rainwater

    int trap(vector<int>& height) {
        int n = height.size();
        int left=0, right=n-1, leftMax=0, rightMax=0, water=0;
        
        while(left<=right){
            
            if(height[left] <= height[right]){
                if(height[left] > leftMax) leftMax = height[left];
                else water += leftMax - height[left];
                left++;
            }
            else{
                if(height[right] > rightMax) rightMax = height[right];
                else water += rightMax - height[right];
                right--;
            }
        }
        
        return water;
    }

//5 Remove duplicate from sorted array

    int removeDuplicates(vector<int>& nums) {
        
        int i=0;
        
        for(int j=1; j<nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i+1;
    }

//6 Max consecutive ones

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0, ans=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]) curr++;
            else{
                ans = max(curr, ans);
                curr=0;
            }
        }
        return max(curr, ans);;
    }