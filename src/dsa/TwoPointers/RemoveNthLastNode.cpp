#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* removeNthLastNode(ListNode* head, int n) {
    ListNode* right = head;
    ListNode* left = head;

    for (int i = 0; i < n; ++i) {
        right = right->next;
    }

    if (right == nullptr) {
        return head->next;
    }

    while (right->next != nullptr) {
        right = right->next;
        left = left->next;
    }

    left->next = left->next->next;
    return head;
}

// Utility to create linked list from vector
ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Utility to print linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> inputs = {
        {23, 89, 10, 5, 67, 39, 70, 28},
        {34, 53, 6, 95, 38, 28, 17, 63, 16, 76},
        {288, 224, 275, 390, 4, 383, 330, 60, 193},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {69, 8, 49, 106, 116, 112, 104, 129, 39, 14, 27, 12}
    };

    vector<int> n = {4, 1, 6, 9, 11};

    for (size_t i = 0; i < inputs.size(); ++i) {
        ListNode* head = createLinkedList(inputs[i]);
        cout << (i + 1) << ".\tLinked List:\t\t";
        printLinkedList(head);
        cout << "\tn = " << n[i] << endl;
        head = removeNthLastNode(head, n[i]);
        cout << "\tUpdated Linked List:\t";
        printLinkedList(head);
        cout << string(100, '-') << endl;
    }

    return 0;
}