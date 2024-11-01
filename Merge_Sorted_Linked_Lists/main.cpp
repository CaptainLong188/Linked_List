/*  
    You're given the heads of two sorted linked lists list1 and list2
    Merge the two lists into one sorted liked list and return the head of the new sorted linked list
    The new list should be made up of nodes from list1 and list2
*/

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val{x}, next(next) {} 
};

void printLinkedList(ListNode* head)
{
    ListNode* current = head;

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if(list1 == nullptr){return list2;}
    if(list2 == nullptr){return list1;}

    ListNode* current1 = list1;
    ListNode* current2 = list2;
    ListNode* head = list1;
    ListNode* tail = list1;
    
    if(current1 -> val <= current2 -> val)
    {
        current1 = current1 -> next;
    }
    else
    {
        head = tail = list2;
        current2 = current2 -> next;
    }

    while(current1 != nullptr && current2 != nullptr)
    {
        if(current1 -> val <= current2 -> val)
        {
            tail -> next = current1;
            current1 = current1 -> next;
        }
        else
        {
            tail -> next = current2;
            current2 = current2 -> next;
        }

        tail = tail -> next;
    }

    if(current1 != nullptr)
    {
        tail -> next = current1;
    }
    else
    {
        tail -> next = current2;
    }

    return head; 
}

int main()
{
    ListNode a1(1);
    ListNode b1(4);
    ListNode c1(5);

    a1.next = &b1;
    b1.next = &c1;

    printLinkedList(&a1);

    ListNode a2(1);
    ListNode b2(2);
    ListNode c2(3);

    a2.next = &b2;
    b2.next = &c2;

    printLinkedList(&a2);
    printLinkedList(mergeTwoLists(&a1, &a2));   
}