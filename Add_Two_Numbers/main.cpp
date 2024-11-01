/*
    You are given two non-empty linked lists, l1 and l2 where each represents a non-negative integer
    The digits are stored in reverse order, e.g the number 123 is represented as 3 -> 2 -> 1 in the linked list
    Each of the nodes contains a single digit.You may assume the two numbers do not contain any leading zero,
    except the number 0 itself.

    Return the sum of the two numbers as a linked list
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

int linkedListToInteger(ListNode* head)
{
    if (head == nullptr) {return 0;}

    ListNode* current = head;
    int num = 0;
    int exp = 1;

    while(current != nullptr)
    {
        num  += (current -> val) * exp;
        exp *= 10;
        current = current -> next;
    }

    return num;
}

ListNode* integerToLinkedList(int num)
{
    ListNode* head = new ListNode(num % 10);
    ListNode* current = head;
    num /= 10;

    while(num)
    {
        current -> next = new ListNode(num% 10);
        num /= 10;
        current = current -> next;
    }

    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    // This approach will overflow
    // int add = linkedListToInteger(l1) + linkedListToInteger(l2);
    // return integerToLinkedList(add);

    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int v1 = (l1 != nullptr) ? l1 -> val : 0;
        int v2 = (l2 != nullptr) ? l2 -> val : 0;
        int val = v1 + v2 + carry;

        carry = val / 10;
        val = val % 10;
        current -> next = new ListNode(val);
        current = current -> next;

        l1 = (l1 != nullptr) ? l1 -> next : nullptr;  
        l2 = (l2 != nullptr) ? l2 -> next : nullptr;  
    }

    return dummy -> next;
}

int main()
{
    ListNode a1(1);
    ListNode b1(2);
    ListNode c1(3);

    a1.next = &b1;
    b1.next = &c1;

    printLinkedList(&a1);

    ListNode a2(4);
    ListNode b2(5);
    ListNode c2(6);

    a2.next = &b2;
    b2.next = &c2;

    printLinkedList(&a2);

    printLinkedList(addTwoNumbers(&a1, &a2));

    return 0;
}