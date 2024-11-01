/*
    Given the beginning of a linked list head, return True if there is a cycle in the linked list.
    There is a cycle in a linked list if at least one node in the list can be visited again by following
    the next pointer. Internally, index determines the index of the beginning of the cycle, if it exists.
    The tail node of the linked list will set its next pointer to the index-th node. If index = -1, then
    the tail node points to null and no cycle exists. Note : index is not given to you as a parameter
*/

#include <iostream>
#include <unordered_set>

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

/*T.C : O(n) , S.C : O(n)*/
bool _hasCycle(ListNode* head)
{
    std::unordered_set<ListNode*> seen;
    ListNode* current = head;

    while(current != nullptr)
    {
        if(seen.count(current) >= 1)
        {
            return true;
        }

        seen.insert(current);
        current = current -> next;
    }

    return false;
}

/*T.C : O(n) , S.C : O(1)*/
bool hasCycle(ListNode* head)
{
    /*Floyd's Tortoise & Hare Algorithm*/
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != nullptr && fast -> next != nullptr)
    {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){ return true;}
    }

    return false;
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

    ListNode a2(1);
    ListNode b2(2);

    a2.next = &b2;  

    std::cout << std::boolalpha << hasCycle(&a1) << std::endl;
    std::cout << std::boolalpha << hasCycle(&a2) << std::endl;

    return 0;
}