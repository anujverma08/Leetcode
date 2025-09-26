/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> map;
        ListNode* tempA = headA;
        while(tempA){
            map[tempA]++;
            tempA = tempA->next;
        }   
        ListNode* tempB = headB;
        while(tempB){
            if(map[tempB] >= 1) return tempB;
            tempB = tempB->next;
        }
        return nullptr;
    }
};