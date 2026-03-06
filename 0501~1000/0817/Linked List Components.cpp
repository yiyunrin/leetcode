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
    int numComponents(ListNode* head, vector<int>& nums) {
        bitset<10000> num;
        for(int i = 0;i < nums.size();i ++)
            num[nums[i]] = 1;
        bool ok = false;
        int ans = 0;
        while(head){
            if(num[head->val] == 0){
                if(ok)
                    ans += 1;
                ok = false;
            }
            else
                ok = true;
            head = head->next;
        }
        if(ok)
            ans += 1;
        return ans;
    }
};
