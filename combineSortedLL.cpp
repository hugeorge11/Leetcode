class Solution {
public:
    ListNode* rv;

    void customInsert(int insertVal) {
        ListNode* next;
        ListNode* curr;
        // note: insert after curr algo
        ListNode* newNode = new ListNode(insertVal);
        curr = rv;

        if (rv == nullptr) {
            // 0: insert into null
            rv = newNode;
            return;
        } else {
            // 1: insert before curr
            if (curr->val > insertVal) {
                newNode->next = curr;
                rv = newNode;
                cout << "ch";
                return;
            }
        }

        // note: find position
        while (true) {
            next = curr->next;
            if (next != nullptr) {
                if (next->val > insertVal) {
                    break;
                }
            } else {
                break;
            }
            curr = next;
        }

        // 2: insert after curr
        newNode->next = curr->next;
        curr->next = newNode;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        rv = list1;
        if (list2 == nullptr) return rv;
        ListNode* targetNode = list2;
        if (targetNode == nullptr) {
            return rv;
        }

        while (targetNode != nullptr) {
            customInsert(targetNode->val);
            targetNode = targetNode->next;
        }
        return rv;
    }
};
