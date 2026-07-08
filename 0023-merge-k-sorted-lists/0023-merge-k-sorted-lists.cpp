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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(auto it : lists)
        {
           ListNode* tmp = it;
           while(tmp)
           {
            v.push_back(tmp->val);
            tmp = tmp->next;
           }
        }
        if(v.empty())return {};
        sort(v.begin(),v.end());
        ListNode *head = new ListNode(v[0]);
        ListNode *tmp = head;
        for(int i=1; i<v.size(); i++)
        {
            ListNode *ele = new ListNode(v[i]);
            tmp->next = ele;
            tmp = tmp->next;
        }
        return head;
    }
};