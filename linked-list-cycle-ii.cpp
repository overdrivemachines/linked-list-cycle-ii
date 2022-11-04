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
  vector<int> v1 = {5, 32, 1, 45, 93, 75, 89};
  vector<int> v2 = {3, 68, 0, -4};
  vector<int> v3 = {6, 95, -5, 0, 56};

  int pos1 = 3, pos2 = 1;
  ListNode* list1 = createLinkedList(v1, pos1);
  ListNode* list2 = createLinkedList(v2, pos2);
  ListNode* list3 = createLinkedList(v3, -1);

  ListNode* cycleNode = detectCycle(list3);
  cout << "cycle node: " << cycleNode->val << endl;

  // printLinkedList(list1);
  // printLinkedList(list2);

  return 0;
}

ListNode* detectCycle(ListNode* head) {
  ListNode* node = head;  // traverse linked list
  ListNode* nodeNext;
  bool hasCycle = false;
  int count = 0;

  for (int i = 0; node != nullptr; i++, node = node->next) {
    cout << node->val << "->";
    nodeNext = node->next;
    node = head;

    for (int j = 0; j < i; j++) {
      if (nodeNext == node) {
        return node;
      }
      node = node->next;
    }
    // node = node->next;
    if (i >= 4) {
      exit(0);
    }
  }

  if (node == nullptr) {
    cout << "\nNo cycles found\n";
  }
  return node;
}

// Create Linked list given a vector of int values
// pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
// returns pointer to head of linked list
ListNode* createLinkedList(vector<int> values, int pos) {
  int count = 0;
  ListNode *head, *tailNext, *temp;
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

  temp = head;
  head = head->next;
  delete (temp);

  if (pos > 0) {
    // make tail node's next point to a node having index pos
    node->next = tailNext;
  } else if (pos == 0) {
    node->next = head;
  }

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