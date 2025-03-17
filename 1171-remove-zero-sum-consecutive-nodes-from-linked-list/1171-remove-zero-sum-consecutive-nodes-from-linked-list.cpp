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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        unordered_map<int,ListNode*> map;
        map[0] = dummy;

        int prefixSum = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            prefixSum += temp->val;
            map[prefixSum] = temp;
            temp = temp->next;
        }

        prefixSum = 0;
        temp = dummy;
        while(temp != nullptr){
            prefixSum += temp->val;
            temp->next = map[prefixSum]->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};