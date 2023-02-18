#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    public:
        struct node<T> * First;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int iPos, T no);
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = new node<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct node<T> * newn = new node<T>;  

    newn ->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node<T> * temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct node<T> * temp = First;

    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    struct node<T> * temp = First;

    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;  
    }
}

template <class T>
void SinglyLL<T> :: InsertAtPos(int iPos, T no)
{
    T NodeCnt;
    T Cnt;
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    NodeCnt = Count();

    if ((iPos < 1) || (iPos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
    }
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == (NodeCnt + 1))
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new node<T>;  
        newn->data = no;
        newn->next = NULL;

        temp = First;
        for ( Cnt = 1; Cnt < iPos - 1; Cnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        
    }
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
{
    T NodeCnt;
    T Cnt;
    struct node<T> * temp1 = NULL;
    struct node<T> * temp2 = NULL;

    NodeCnt = Count();

    if ((iPos < 1) || (iPos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for ( Cnt = 1; Cnt < iPos - 1; Cnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

/*template <class T>
void SinglyLL<T> :: Display()
{
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}*/

template<class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    struct node<T> *  temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

int main()
{
    int iRet = 0;
    
    SinglyLL <char>cobj;
    cobj.InsertFirst('B');
    cobj.InsertFirst('A');
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL <int>iobj;
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL <float>fobj;
    fobj.InsertFirst(21.10f);
    fobj.InsertFirst(11.10f);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL <double>dobj;
    dobj.InsertFirst(21.10);
    dobj.InsertFirst(11.10);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.InsertLast('C');
    cobj.InsertLast('D');
    cobj.InsertLast('F');
    cobj.InsertLast('G');
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.InsertLast(51.5f);
    fobj.InsertLast(101.5f);
    fobj.InsertLast(111.5f);
    fobj.InsertLast(121.5f);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertLast(51.10);
    dobj.InsertLast(101.10);
    dobj.InsertLast(111.10);
    dobj.InsertLast(121.10);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.DeleteFirst();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.DeleteFirst();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.DeleteFirst();
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

        cobj.DeleteLast();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.DeleteLast();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.DeleteLast();
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

        cobj.InsertAtPos(4, 'E');
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.InsertAtPos(3, 61);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.InsertAtPos(3, 61.5);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertAtPos(3, 61.101);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.DeleteAtPos(4);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.DeleteAtPos(3);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.DeleteAtPos(3);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteAtPos(3);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.Display();
    iobj.Display();
    fobj.Display();
    dobj.Display();

    return 0;
}