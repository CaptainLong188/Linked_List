/*  You are given the head of a singly linked-list.

The positions of a linked list of length = 7 for example, can intially be represented as:

[0, 1, 2, 3, 4, 5, 6]

Reorder the nodes of the linked list to be in the following order:

[0, 6, 1, 5, 2, 4, 3]

Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:

[0, n-1, 1, n-2, 2, n-3, ...]

You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.*/

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

void reorderList(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head -> next;

    while(fast != nullptr && fast -> next != nullptr)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    ListNode* list2 = slow -> next;
    slow -> next = nullptr; // List 1 is complete
    ListNode* prev = nullptr;

    while(list2 != nullptr)
    {
        ListNode* nextNode = list2 -> next;
        list2 -> next = prev;
        prev = list2;
        list2 = nextNode;
    }
    
    ListNode* list1 = head;
    list2 = prev; // List 2 is complete

    while(list1 != nullptr && list2 != nullptr)
    {
        ListNode* next1 = list1 -> next;
        ListNode* next2 = list2 -> next;
        list1 -> next = list2;
        list2 -> next = next1;
        list1 = next1;
        list2 = next2;
    }
}

int main()
{
    ListNode a(2);
    ListNode b(4);
    ListNode c(6);
    ListNode d(8);
    ListNode e(10);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    reorderList(&a);
    printLinkedList(&a);
}