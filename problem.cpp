#include <bits/stdc++.h>
using namespace std;
template < class T> 
class node
{
    public:
    T data;
    node* next;
    node* previous;
};
template < class T >
class doubly_linked_list
{
    public:
    node< T > *head ;
    int sz ;
    doubly_linked_list()
    {
        head = NULL;
        sz =0;
    }
    node < T > *createnewnodes( T value)
    {
        node< T >* newnode = new node< T >;
        newnode->data = value;
        newnode->next = NULL;
        newnode->previous = NULL;
        return newnode;
    }

    void insertathead(T data)
    {
        sz++;
        node < T > *newnode = createnewnodes(data);
        if (head==NULL)
        {
            head = newnode ;
            return;
        }
        newnode->next = head;
        head = newnode;
    }
    void traverse()
    {
        node < T > *a = head;
        while(a!= NULL)
        {
            cout << a->data << " ";
            a = a->next;
        }
        cout <<"\n";        
    }
    void delete_at_head()
    {
        if (head == NULL)
        {
            return;
        }
        
        node < T > *a = head;
        node < T > *b= head->next;

        delete a;
        if (b!= NULL)
        {
            b->previous = NULL;
        }
        head = b;
        sz--;
    }
    int getsize()
    {
        return sz;
    }
};
template < class T >
class Stack
{
public:
    doubly_linked_list < T > dl;
    Stack()
    {

    }
    T top ()
    {
        if(dl.getsize()==0)
        {
            cout << "Stack is empty\n";
            T a;
            return a ;
        }
        return dl.head->data;
    }
    void push(T val)
    {
        dl.insertathead(val);
    }
    void pop()
    {
        if(dl.getsize()==0)
        {
            cout << "Stack is empty\n";
        }
        dl.delete_at_head();
    }
    int size()
    {
        return dl.getsize();
    }
    void travel ()
    {
        dl.traverse();
    }
};
int main()
{
    Stack <int > st ;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(7);
    st.travel();

    Stack < char > ch;
    ch.push('a');
    ch.push('b');
    ch.push('c');
    ch.push('d');
    ch.push('e');
    ch.travel();
    
    return 0;
}
