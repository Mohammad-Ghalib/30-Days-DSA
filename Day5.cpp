//1 Reverse a LL

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *prev=NULL, *curr=head, *ahead;
        while(curr){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }

        return prev;
    }

//2 Middle of a LL

    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

//3 Merge two sorted LL

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) return l2; 
        if(l2 == NULL) return l1;

        if(l1->val > l2->val) std::swap(l1,l2);

        ListNode* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            ListNode* temp = NULL;

            while(l1 != NULL && l1->val <= l2->val) {
                temp = l1; 
                l1 = l1->next;
            }

            temp->next = l2;
            std::swap(l1,l2);
        }

        return res;
    }

//4 Remove nth node from back of LL

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *behind=head, *ahead=head;
        while(n--){
            ahead = ahead->next;
        }

        if(!ahead) return head->next;

        while(ahead->next){
            ahead = ahead->next;
            behind = behind->next;
        }

        behind->next = behind->next->next;

        return head;
    }

//5 Add 2 numbers as LL

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1=l1, *curr2=l2, *temp;
        ListNode *dummy = new ListNode(0);
        temp = dummy; 
        int carr=0, num, num1, num2;

        while(curr1 || curr2 || carr){
            num1 = curr1? curr1->val: 0;
            num2 = curr2? curr2->val: 0;
            num  = num1 + num2 + carr;

            carr = num/10;
            ListNode *node = new ListNode(num%10);
            temp->next = node;
            temp = temp->next;

            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
        }

        return dummy->next;
    }

//6 Delete given node in O(1)

    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    