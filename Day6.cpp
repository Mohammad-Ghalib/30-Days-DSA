//1 Find intersection point of Y LL

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1=headA, *l2=headB;

        while(l1 != l2){
            l1 = l1? l1->next: headB;
            l2 = l2? l2->next: headA;
        }

        return l1;
    }

//2 Deyect a cycle in LL

    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        
        return false;
    }

//3 Reverse a LL in groups of k

    int lengthOfLinkedList(ListNode* head) {
        int length = 0;
        while(head != NULL) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        int length = lengthOfLinkedList(head);
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* pre = dummyHead;
        ListNode* cur;
        ListNode* nex;
        
        while(length >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            length -= k;
        }
        return dummyHead->next;
    }

//4 Check if a LL is palindrome

    ListNode* reverse(ListNode* head){
        
        if(!head || !head->next) return head;

        ListNode *prev=NULL, *curr=head, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    } 

    bool isPalindrome(ListNode* head) {

        if(!head || !head->next) return true;

        ListNode *slow=head, *fast=head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverse(slow->next);
        fast = head;

        while(slow){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }

//5 Find starting point of cycle in LL

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                fast = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }

//6 Flatten a LL

    Node* merge(Node *a, Node *b){
        Node *temp = new Node(0);
        Node *res = temp;
        
        while(a && b){
            if(a->data < b->data){
                temp->bottom = a;
                a = a->bottom;
            }
            else{
                temp->bottom = b;
                b = b->bottom;
            }
            
            temp = temp->bottom;
        }
        
        if(a) temp->bottom = a;
        else temp->bottom = b;
        
        return res->bottom;
    }   
        
    Node* flatten(Node *root){
        if(!root || !root->next) return root;
        
        root->next = flatten(root->next);
        root = merge(root, root->next);
        
        return root;
    }