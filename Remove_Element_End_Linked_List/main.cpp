/*  You are given the beginning of a linked list head, and an integer n.

Remove the nth node from the end of the list and return the beginning of the list.*/

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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* current = head;
    ListNode* prev1 = nullptr;

    while(current != nullptr)
    {
        ListNode* nextNode = current -> next;
        current -> next = prev1;
        prev1 = current;
        current = nextNode; 
    }

    current = prev1;
    ListNode* prev2 = nullptr;

    while(current != nullptr)
    {
        if(n == 1)
        {
            current = current -> next;
        }
        else
        {
            ListNode* nextNode = current -> next;
            current -> next = prev2;
            prev2 = current;
            current = nextNode;
        }
        --n;
    }

    return prev2;
}

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    printLinkedList(removeNthFromEnd(&a, 2));
}