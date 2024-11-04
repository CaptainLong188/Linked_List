/*
    Given the beginning of a linked list head, return the node where the cycle begins.
    If there's no cycle return null.
    There is a cycle in a linked list if at least one node in the list can be visited again by following
    the next pointer. Internally, index determines the index of the beginning of the cycle, if it exists.
    The tail node of the linked list will set its next pointer to the index-th node. If index = -1, then
    the tail node points to null and no cycle exists. Note : index is not given to you as a parameter
*/

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val{x}, next(next) {} 
};

void printLinkedList(ListNode *head)
{
    ListNode *current = head;

    while(current != nullptr)
    {
        if(current -> next == nullptr) 
        {
            std::cout << current -> val << std::endl;
        }
        else
        {
            std::cout << current -> val << " -> ";
        }

        current = current -> next;
    }
}


/*T.C : O(n) , S.C : O(1)*/
ListNode* detectCycle(ListNode* head)
{
    /*Floyd's Tortoise & Hare Algorithm*/
    ListNode* slow1 = head;
    ListNode* fast = head;
    bool hasCycle = false;    

    while (fast != nullptr && fast -> next != nullptr)
    {
        slow1 = slow1 -> next;
        fast = fast -> next -> next;

        if(slow1 == fast)
        {
            hasCycle = true;
            break;
        }
    }
    
    if(hasCycle)
    {
        ListNode* slow2 = head;

        while(slow1 != slow2)
        {
            slow1 = slow1 -> next;
            slow2 = slow2 -> next;
        }

        return slow1;
    }

    return nullptr;
}

int main()
{

    ListNode a1(1);
    ListNode b1(2);
    ListNode c1(3);
    ListNode d1(4);

    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    d1.next = &b1;

    ListNode* n1 = detectCycle(&a1);
    std::cout << (n1 -> val) << std::endl;

    ListNode a2(1);
    ListNode b2(2);

    a2.next = &b2;
    b2.next = &a2; 
    ListNode* n2 = detectCycle(&a2);
    std::cout << (n2 -> val) << std::endl;

    return 0;
}