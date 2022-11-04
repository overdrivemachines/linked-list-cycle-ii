#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> values, int pos);
void printLinkedList(ListNode* head);
ListNode* detectCycle(ListNode* head);

int main(int argc, char const* argv[]) {
  vector<int> v1 = {5, 32, 1, 2, 93, 75, 89};
  vector<int> v2 = {3, 2, 0, -4};

  int pos1 = 3, pos2 = 1;
  ListNode* list1 = createLinkedList(v1, pos1);
  ListNode* list2 = createLinkedList(v2, pos2);

  // printLinkedList(list1);
  // printLinkedList(list2);

  return 0;
}

ListNode* detectCycle(ListNode* head) {
  ListNode* node;
  return node;
}

// Create Linked list given a vector of int values
// returns pointer to head of lined list
ListNode* createLinkedList(vector<int> values, int pos) {
  int count = 0;
  ListNode *head, *tailNext;
  ListNode* node = new ListNode(0);
  head = node;
  for (int value : values) {
    node->next = new ListNode(value);
    node = node->next;

    if (count == pos) {
      tailNext = node;
    }
    count++;
  }
  node->next = tailNext;

  cout << "tail value: " << node->val << endl;
  cout << "tail next: " << node->next->val << endl;

  head = head->next;
  return head;
}

// Prints Linked List
// e.g. 5->8->3->NULL
void printLinkedList(ListNode* head) {
  ListNode* node = head;

  while (node != nullptr) {
    cout << node->val << "->";
    node = node->next;
  }
  cout << "NULL\n";
}