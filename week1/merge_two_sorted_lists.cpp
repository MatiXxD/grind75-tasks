/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode *root = new ListNode(0);
  ListNode *curr = root;
  while (list1 && list2) {
    if (list1->val < list2->val) {
      curr->next = list1;
      list1 = list1->next;
    } else {
      curr->next = list2;
      list2 = list2->next;
    }
    curr = curr->next;
  }
  curr->next = list1 ? list1 : list2;
  return root->next;
}
