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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pre2 = head->val, pre1 = head->next->val, now_idx = 2;
        head = head->next->next;
        int first_idx = -1, pre_idx = -1, mn = INT_MAX, cnt = 0;
        while(head){
            int now = head->val;
            head = head->next;
            if((pre2 > pre1 && now > pre1) || (pre2 < pre1 && now < pre1)){
                cnt ++;;
                if(first_idx == -1)
                    first_idx = now_idx;
                if(pre_idx != -1)
                    mn = min(mn, now_idx - pre_idx);
                pre_idx = now_idx;
            }
            pre2 = pre1;
            pre1 = now;
            now_idx ++;
        }
        if(cnt < 2)
            return {-1, -1};
        return {mn, pre_idx - first_idx};
    }
};
