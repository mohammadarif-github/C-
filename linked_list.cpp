#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node *next;
};
class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }
    node *createnewnode(int value)
    {
        node *newnode = new node;
        newnode->value = value;
        newnode->next = NULL;
        return newnode;
    }
    void InsertAtHead(int value)
    {

        node *newnode = createnewnode(value);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }
    int getSize()
    {
        node *first = head;
        int count = 0;
        while (first != NULL)
        {
            first = first->next;
            count++;
        }
        return count;
    }
    void reverseLLPrint(node *head)
    {
        if (head != NULL)
        {
            reverseLLPrint(head->next);
            cout << head->value << " ";
        }
    }
    void printReverse()
    {
        node *a = head;
        reverseLLPrint(a);
        cout << "\n";
    }
    void Traverse()
    {
        node *a = head;
        while (a != NULL)
        {
            cout << a->value << " ";
            a = a->next;
        }
        cout << "\n";
    }
    int getValue(int index)
    {
        node *a = head;
        for (int i = 0; a != NULL; i++)
        {
            if (i == index)
            {
                return a->value;
            }
            a = a->next;
        }
        return -1;
    }
    void swapFirst()
    {
        node* first = head;
        int temp =first->next->value;
        first->next->value = first->value ;
        first->value = temp;
    }
};

int main()
{
    LinkedList l;
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(5);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    cout<<l.getValue(2)<<"\n";

    cout<<l.getValue(6)<<"\n";

    l.printReverse();
    l.Traverse();
    l.swapFirst();
    l.Traverse();
    l.printReverse();

    return 0;
}
