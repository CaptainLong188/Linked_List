/*  Question: Given the beginning of a singly linked list head, reverse the list, and return
    the new beginning of the list*/

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

ListNode* reverseLinkedList(ListNode *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }

    ListNode *prev = nullptr; 
    ListNode *current = head;

    while(current != nullptr)
    {
        ListNode *nextNode = current -> next;
        current -> next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main()
{
    ListNode a(0);
    ListNode b(1);
    ListNode c(2);
    ListNode d(3);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    printLinkedList(&a);
    printLinkedList(reverseLinkedList(&a));
}