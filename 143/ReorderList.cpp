/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // create stack to hold pointers in reverse order (LIFO)
        std::stack<ListNode*> reverse;
        ListNode* p = head;
        while(p != nullptr){
            reverse.push(p);
            p = p->next;
        }
        // now combint the singly linked list and stack
        p = head;
        while(!reverse.empty()){
            ListNode* stack_val = reverse.top();
            reverse.pop();
            ListNode* next = p->next;
            if (stack_val == next || stack_val == p){
                stack_val->next = nullptr;
                break;
            } 
            p->next = stack_val;
            stack_val->next = next;
            p = next;
        }
    }
};