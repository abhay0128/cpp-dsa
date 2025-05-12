#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* random;
    
        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

class CopyListRand {
public:
    Node* copyRandomList(Node* head) {
        if (head==nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> map;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        map[head] = newHead;
        while(oldTemp != nullptr) {
            Node* copyNode =  new Node(oldTemp->val);
            map[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        oldTemp = head;
        newTemp = newHead;
        while(oldTemp != nullptr) {
            newTemp->random = map[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
    
};

int main() {
    // Example usage of the Solution class
    // Create a linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next; // 1's random points to 2
    head->next->random = head; // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2
    CopyListRand sol;
    Node* copiedList = sol.copyRandomList(head);
    // Print the copied list
    Node* temp = copiedList;
    while (temp != nullptr) {
        cout << "Value: " << temp->val;
        if (temp->random != nullptr) {
            cout << ", Random Value: " << temp->random->val;
        } else {
            cout << ", Random Value: nullptr";
        }
        cout << endl;
        temp = temp->next;
    }
    return 0;
}