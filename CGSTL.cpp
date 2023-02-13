#include <iostream>
using namespace std;
/******************************************************************************************************

     Name of the Project : Customized Generalized Standard Template Library
     Name of the Structure : nodeS
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This is the structure for singly linear and circular linked list

****************************************************************************************************/

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Library
     Name of the Structure : nodeD
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This is the structure for doubly linear and circular linked list

****************************************************************************************************/

template <class T>
struct nodeD
{
    T data;
    struct nodeD<T> *next;
    struct nodeD<T> *prev;
};

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Class : singlyLinear
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This is the class for singly linear linked list

****************************************************************************************************/

template <class T>
class singlyLinear
{
public:
    struct nodeS<T> *Head;
    singlyLinear();
    void insertFirst(T no);
    void insertLast(T no);
    int Count();
    void Display();
    void insertAtPos(int Pos, T no);
    void deleteFirst();
    void deleteLast();
    void deleteAtPos(int pos);
    void ReverseElement();
    void ReverseElementByRecursion(struct nodeS<T> *temp);
    int checkFirstOccurance(T no);
    int checkLastOccurance(T no);
    T largestElement();
    T smallestElement();
    singlyLinear<int> displayPerfectNo();
    singlyLinear<int> displayPrimeNo();
    T displayAddition();
    T displaySecondMax();
    singlyLinear<int> evenNo();
    singlyLinear<int> oddNo();
    singlyLinear<int> displayAdditionOfDigit();
    bool searchElement(T no);
    int frequencyOfElement(T no);
};

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Constructor : singlyLinear
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This is the Constructor for singly linear linked list

****************************************************************************************************/

template <class T>
singlyLinear<T>::singlyLinear()
{
    Head = NULL;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertFirst
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : [IN] T no
     Description: This function insert an element at first position of singly Linear linked list.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::insertFirst(T no)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = no;
    newn->next = NULL;
    if (Head == NULL)
    {
        Head = newn;
    }

    else
    {
        newn->next = Head;
        Head = newn;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertLast
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : [IN] T no
     Description: This function insert an element at last position of singly Linear linked list.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::insertLast(T no)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct nodeS<T> *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : Count
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function counts the number of elements in singly Linear linked list.

****************************************************************************************************

template <class T>
int singlyLinear<T>::Count()
{
    int Count = 0;
    struct nodeS<T> *temp = Head;
    while (temp != NULL)
    {
        Count++;
        temp = temp->next;
    }
    return Count;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : Display
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function displays elements of singly Linear linked list.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::Display()
{
    struct nodeS<T> *temp = Head;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertAtPos
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : [IN] T no ,int pos
     Description: This function insert an element at specific position of singly Linear linked list.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::insertAtPos(int pos, T no)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    int nodeCnt = Count();
    if (pos < 1 || pos > nodeCnt + 1)
    {
        return;
    }
    if (pos == 1)
    {
        insertFirst(no);
    }
    else if (pos == nodeCnt + 1)
    {
        insertLast(no);
    }
    else
    {
        int iCnt = 1;
        struct nodeS<T> *temp = Head;
        while (iCnt < pos - 1)
        {
            temp = temp->next;
            iCnt++;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteFirst
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function delete an element of first position in singly Linear linked list.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::deleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct nodeS<T> *temp = Head;
        Head = Head->next;
        delete temp;
        temp = NULL;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteLast
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function delete an element of last position from singly Linear linked list.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::deleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        struct nodeS<T> *temp = Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteAtPos
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : int pos
     Description: This function deletes an element at specific position from singly Linear linked list.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::deleteAtPos(int pos)
{
    int nodeCnt = Count();
    if (pos < 0 || pos > nodeCnt)
    {
        return;
    }
    if (pos == 1)
    {
        deleteFirst();
    }
    else if (pos == nodeCnt)
    {
        deleteLast();
    }
    else
    {
        struct nodeS<T> *temp1 = Head;
        struct nodeS<T> *temp2 = NULL;
        int iCnt = 1;
        while (iCnt < pos - 1)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        temp2 = NULL;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : ReverseElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function reverse an elements of singly Linear linked list.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::ReverseElement()
{
    struct node *temp1 = Head;
    struct node *temp2 = Head;
    int iCnt = 0;
    int Arr[Count()];
    while (temp1 != NULL)
    {
        Arr[iCnt++] = temp1->data;
        temp1 = temp1->next;
    }

    iCnt--;
    while (temp2 != NULL)
    {
        temp2->data = Arr[iCnt--];
        temp2 = temp2->next;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : reverseElementByRecursion
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : [In] struct nodeS<T> *first
     Description: This function reverse an elements of singly Linear linked list using recursion.

****************************************************************************************************/

template <class T>
void singlyLinear<T>::ReverseElementByRecursion(struct nodeS<T> *first)
{
    if (first == NULL)
    {
        cout << "There are no such elements in linked list." << endl;
    }

    else
    {
        Reverse(first->next);
        printf("|%d|->", first->data);
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkFirstOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T iData
     Description: This function returns the first occurance index of given element of singly Linear linked list.

****************************************************************************************************/

template <class T>
int singlyLinear<T>::checkFirstOccurance(T iData)
{
    int iCount = 0, iTemp = -1;
    struct nodeS<T> *first = Head;
    if (first == NULL)
    {
        printf("there are no elements:\n");
    }
    else
    {
        for (iCount = 1; first != NULL; iCount++)
        {
            if (first->data == iData)
            {
                iTemp = iCount;
                break;
            }
            first = first->next;
        }
    }
    if (iTemp == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iTemp;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkLastOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T iData
     Description: This function returns the last occurance index of given element of singly Linear linked list.

****************************************************************************************************/

template <class T>
int singlyLinear<T>::checkLastOccurance(T iData)
{
    int iCount = 0, iTemp = -1;
    int index = 1;
    struct nodeS<T> *first = Head;
    if (first == NULL)
    {
        printf("there are no elements:\n");
    }
    else
    {
        for (iCount = 1; first != NULL; iCount++)
        {
            if (first->data == iData)
            {

                iTemp = iCount;
            }
            index++;
            first = first->next;
        }
    }
    if (iTemp == -1)
    {
        cout << "No element is present in linkedlist" << endl;
    }
    return iTemp;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : largestElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the largest element of singly Linear linked list.

****************************************************************************************************/

template <class T>
T singlyLinear<T>::largestElement()
{
    struct nodeS<T> *first = Head;
    int iMax = first->data;
    if (first == NULL)
    {
        printf("oops! no any nodes here\n");
    }
    else
    {
        while (first != NULL)
        {
            if (first->data > iMax)
            {
                iMax = first->data;
            }
            first = first->next;
        }
    }
    return iMax;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : smallestElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns  smallest element from singly Linear linked list.

****************************************************************************************************/

template <class T>
T singlyLinear<T>::smallestElement()
{
    struct nodeS<T> *first = Head;
    int iMin = first->data;
    if (first == NULL)
    {
        printf("No any elements here\n");
    }
    else
    {
        while (first != NULL)
        {
            if (first->data < iMin)
            {
                iMin = first->data;
            }
            first = first->next;
        }
    }
    return iMin;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayPerfectNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains perfect number from
     given singly Linear linked list.

****************************************************************************************************/

template <>
singlyLinear<int> singlyLinear<int>::displayPerfectNo()
{
    int iCnt = 1;
    struct nodeS<int> *first = Head;
    singlyLinear<int> obj;
    if (first == NULL)
    {
        printf("Ooops! Linked list is empty:\n");
        return obj;
    }
    else
    {
        while (first != NULL)
        {
            int perNo = 0;
            for (iCnt = 1; iCnt <= (first->data) / 2; iCnt++)
            {
                if ((first->data) % iCnt == 0)
                {
                    perNo = perNo + iCnt;
                }
            }
            if (perNo == first->data)
            {
                obj.insertLast(perNo);
            }
            first = first->next;
        }
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayPrimeNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains prime number from given
                singly Linear linked list.

****************************************************************************************************/

template <>
singlyLinear<int> singlyLinear<int>::displayPrimeNo()
{
    struct nodeS<int> *first = Head;
    singlyLinear<int> obj;
    int iCnt = 0, iTemp = 1;
    int iNum = first->data;
    if (first == NULL)
    {
        cout << "No elements in linked list." << endl;
    }
    else
    {
        while (first != NULL)
        {
            if (first->data == 2)
            {
                obj.insertLast(first->data);
            }
            for (iCnt = 2; iCnt < (iNum) / 2; iCnt++)
            {
                iNum = first->data;
                if (iNum % iCnt == 0)
                {
                    iTemp = 0;
                    break;
                }
                else
                {
                    iTemp = first->data;
                }
            }

            if (iTemp != 0)
            {
                obj.insertLast(iTemp);
            }
            first = first->next;
        }
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkFirstOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the addition of all elements from singly Linear linked list.

****************************************************************************************************/

template <class T>
T singlyLinear<T>::displayAddition()
{
    struct nodeS<T> *first = Head;
    int iSum = 0;
    if (first == NULL)
    {
        printf("There are no elements in linked list:\n");
    }
    else
    {
        while (first != NULL)
        {
            iSum = iSum + (first->data);
            first = first->next;
        }
    }
    return iSum;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displaySecondMax
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the second maximum element from singly Linear linked list.

****************************************************************************************************/

template <class T>
T singlyLinear<T>::displaySecondMax()
{
    struct nodeS<T> *first = Head;
    if (first == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    int iMax1 = 0, iMax2 = 0;
    if (first == NULL)
    {
        printf("There are no any elements:\n");
    }
    else
    {
        while (first != NULL)
        {
            if ((first->data) > iMax1)
            {
                iMax2 = iMax1;
                iMax1 = first->data;
            }
            else if ((first->data) > iMax2)
            {
                iMax2 = first->data;
            }
            first = first->next;
        }
    }

    return iMax2;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayAdditionOfDigit
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters :None
     Description: This function returns the addition of digit of each element from singly Linear linked list.

****************************************************************************************************/

template <class T>
singlyLinear<int> singlyLinear<T>::displayAdditionOfDigit()
{
    struct nodeS<T> *first = Head;
    if (first == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    singlyLinear<T> obj;
    int iTemp = 0, iRem = 0, iSum = 0;
    if (first == NULL)
    {
        printf("There are no elemnets here:\n");
    }
    else
    {
        while (first != NULL)
        {
            iSum = 0;
            iTemp = first->data;
            while (iTemp != 0)
            {
                iRem = iTemp % 10;
                iSum = iSum + iRem;
                iTemp = iTemp / 10;
            }
            obj.insertLast(iSum);
            first = first->next;
        }
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : evenNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the even numbers from singly Linear linked list.

****************************************************************************************************/

template <>
singlyLinear<int> singlyLinear<int>::evenNo()
{
    singlyLinear<int> obj;
    bool flag = false;
    struct nodeS<int> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            flag = true;
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : oddNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the odd elements from singly Linear linked list.

****************************************************************************************************/

template <>
singlyLinear<int> singlyLinear<int>::oddNo()
{
    singlyLinear<int> obj;
    bool flag = false;
    struct nodeS<int> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (temp != NULL)
    {
        if ((temp->data) % 2 != 0)
        {
            flag = true;
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "There are no odd elements." << endl;
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : searchElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns true or false if given number is present or not in singly
                 Linear linked list.

****************************************************************************************************/

template <class T>
bool singlyLinear<T>::searchElement(T no)
{
    struct nodeS<T> *temp = Head;
    bool flag = false;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    while (temp != NULL)
    {
        if (temp->data == no)
        {
            flag = true;
            break;
        }
        temp = temp->next;
    }
    return flag;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : frequencyOfElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns the frequency of given element from singly Linear linked list.

****************************************************************************************************/

template <class T>
int singlyLinear<T>::frequencyOfElement(T no)
{
    struct nodeS<T> *temp = Head;
    bool flag = false;
    int Counter = 0;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    while (temp != NULL)
    {
        if (temp->data == no)
        {
            flag = true;
            Counter++;
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "There is no such Element" << endl;
    }
    return Counter;
}

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the class : singlyCL
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters : None
    Description: This class represents the singly circular linked list.

****************************************************************************************************/

template <class T>
class singlyCL
{
public:
    struct nodeS<T> *Head;
    struct nodeS<T> *Tail;

    singlyCL();
    void Display();
    int Count();
    void insertFirst(T no);
    void insertLast(T no);
    void insertAtPos(int pos, T no);
    void deleteFirst();
    void deleteLast();
    void deleteAtPos(int pos);

    int checkFirstOccurance(T no);
    int checkLastOccurance(T no);
    T largestElement();
    T smallestElement();
    singlyCL<int> displayPerfectNo();
    singlyCL<int> displayPrimeNo();
    T displayAddition();
    T displaySecondMax();
    singlyCL<int> evenNo();
    singlyCL<int> oddNo();
    singlyCL<int> addDigitOfEachElement();
    bool searchElement(T no);
    int frequencyOfElement(T no);
};

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Constructor : singlyCL
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters :None
    Description: This is the constructor of singly circular linked list.

****************************************************************************************************/

template <class T>
singlyCL<T>::singlyCL()
{
    Head = NULL;
    Tail = NULL;
}

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Function : Display
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters : None
    Description: This function displays the elements of singly circular linked list.

****************************************************************************************************/

template <class T>
void singlyCL<T>::Display()
{
    struct nodeS<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty:\n";
        return;
    }
    else
    {
        do
        {
            cout << "|" << temp->data << "|->";
            temp = temp->next;
        } while (temp != Tail->next);
        cout << "NULL\n";
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : Count
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the number of elements of singly circular linked list.

****************************************************************************************************/

template <class T>
int singlyCL<T>::Count()
{
    struct nodeS<T> *temp = Head;
    int iCnt = 0;
    if (temp == NULL)
    {
        cout << "There are no nodes in linked list";
        return 0;
    }
    else
    {
        do
        {
            iCnt++;
            temp = temp->next;
        } while (temp != Tail->next);
    }
    return iCnt;
}

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Function : insertFirst
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters : T no
    Description: This function inserts the element at first position of singly circular linked list.

****************************************************************************************************/

template <class T>
void singlyCL<T>::insertFirst(T no)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (Head == NULL && Tail == NULL)
    {
        Head = Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
}

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Function : insertLast
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters : T no
    Description: This function inserts the element at last position of singly
                 circular linked list.

****************************************************************************************************/

template <class T>
void singlyCL<T>::insertLast(T no)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    struct nodeS<T> *temp = Tail;
    if (Head == NULL && Tail == NULL)
    {
        Head = Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
}

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Function : insertAtPos
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters : T no,int pos
    Description: This function inserts an element at specific position to singly
                circular linked list.

****************************************************************************************************/

template <class T>
void singlyCL<T>::insertAtPos(int pos, T no)
{
    int nodeCnt = 0;
    nodeCnt = Count();

    if (pos < 1 || pos > nodeCnt + 1)
    {
        cout << "invalid positions\n";
        return;
    }
    int checkFirstOccurance(int no);
    if (pos == 1)
    {
        insertFirst(no);
    }
    else if (pos == nodeCnt + 1)
    {
        insertLast(no);
    }
    else
    {
        struct nodeS<T> *newn = new struct nodeS<T>;
        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> *temp = Head;

        int iCnt = 1;
        while (iCnt < pos - 1)
        {
            temp = temp->next;
            iCnt++;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    Tail->next = Head;
}

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Function : deleteFirst
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters : None
    Description: This function deletes first element from singly circular linked list.

****************************************************************************************************/

template <class T>
void singlyCL<T>::deleteFirst()
{
    if (Head == NULL)
    {
        cout << "Already linked list is empty:\n";
        return;
    }
    else if (Head == Tail)
    {
        delete Head;

        Head = NULL;
    }
    else
    {
        struct nodeS<T> *temp = Head;
        Head = Head->next;
        delete temp;
        temp = NULL;
    }
    Tail->next = Head;
}

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Function : deleteLast
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters :None
    Description: This function deletes the last element from singly circular linked list.

****************************************************************************************************/

template <class T>
void singlyCL<T>::deleteLast()
{
    if (Head == NULL)
    {
        cout << "There are no nodes in linked list:\n";
        return;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct nodeS<T> *temp = Head;
        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        bool searchElement(T no);
        int frequencyOfElement(T no);
        Tail = temp;
        delete temp->next;
        temp->next = NULL;
    }
    Tail->next = Head;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteAtPos
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : int pos
     Description: This function deletes the element of specific position from singly circular linked list.

****************************************************************************************************/

template <class T>
void singlyCL<T>::deleteAtPos(int pos)
{
    int nodeCnt = 0;
    nodeCnt = Count();
    if (pos < 0 || pos > nodeCnt)
    {
        cout << "Invalid choice:\n";
        return;
    }
    if (pos == 1)
    {
        deleteFirst();
    }
    else if (pos == nodeCnt)
    {
        deleteLast();
    }
    else
    {
        struct nodeS<T> *temp1 = Head;
        struct nodeS<T> *temp2 = NULL;
        int iCnt = 1;
        while (iCnt < pos - 1)
        {
            temp1 = temp1->next;
            iCnt++;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        temp2 = NULL;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkFirstOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns the first occurance index of given element singly circular linked list.

****************************************************************************************************/

template <class T>
int singlyCL<T>::checkFirstOccurance(T no)
{
    int iCount = 1, iPos = -1;
    struct nodeS<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        if (temp->data == no)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        temp = temp->next;
    } while (temp != Tail->next);
    if (iPos == -1)
    {
        cout << "There is no such element in linked list." << endl;
    }
    return iPos;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkLastOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns the last occurance index of given element
                    singly circular linked list.

****************************************************************************************************/

template <class T>
int singlyCL<T>::checkLastOccurance(T no)
{
    int iCount = 1, iPos = -1;
    struct nodeS<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        if (temp->data == no)
        {
            iPos = iCount;
        }
        iCount++;
        temp = temp->next;
    } while (temp != Tail->next);
    if (iPos == -1)
    {
        cout << "There is no such element in linked list" << endl;
    }
    return iPos;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : largestElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the largest element from singly circular linked list.

****************************************************************************************************/

template <class T>
T singlyCL<T>::largestElement()
{
    struct nodeS<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    T max = temp->data;
    do
    {
        if ((temp->data) > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    } while (temp != Tail->next);
    return max;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : smallestElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the smallest element from singly circular linked list.

****************************************************************************************************/

template <class T>
T singlyCL<T>::smallestElement()
{
    struct nodeS<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    T min = temp->data;
    do
    {
        if ((temp->data) < max)
        {
            min = temp->data;
        }
        temp = temp->next;
    } while (temp != Tail->next);
    return min;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayPerfectNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains perfect number from given
                  singly circular linked list.

****************************************************************************************************/

template <>
singlyCL<int> singlyCL<int>::displayPerfectNo()
{
    struct nodeS<int> *temp = Head;
    singlyCL<int> obj;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        int iNum = temp->data, iSum = 0;

        for (int i = 1; i <= iNum / 2; i++)
        {

            if (iNum % i == 0)
            {
                iSum = iSum + i;
            }
        }
        if (iSum == temp->data)
        {
            obj.insertLast(iSum);
        }
        temp = temp->next;
    } while (temp != Tail->next);
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayAddition
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the addition of element from singly circular
                  linked list.

****************************************************************************************************/

template <class T>
T singlyCL<T>::displayAddition()
{
    struct nodeS<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    T iSum;
    do
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    } while (temp->next != Head);
    return iSum;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displaySecondMax
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the second maximum element from singly
                     circular linked list.

****************************************************************************************************/

template <class T>
T singlyCL<T>::displaySecondMax()
{
    struct nodeS<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    T max1, max2;
    do
    {
        if (temp->data > max1)
        {
            max2 = max1;
            max1 = temp->data;
        }
        else if (temp->data > max2)
        {
            max2 = temp->data;
        }
        temp = temp->next;
    } while (temp != Tail->next);
    return max2;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : addDigitOfEachElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains addition of each digit
                 of that element from  singly circular linked list.

****************************************************************************************************/

template <>
singlyCL<int> singlyCL<int>::addDigitOfEachElement()
{
    struct nodeS<int> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    singlyCL<int> obj;
    do
    {
        int iNum = temp->data;
        int iSum = 0, iDigit = 0;
        while (iNum != '\0')
        {
            iDigit = iNum % 10;
            iSum = iSum + iDigit;
            iNum = iNum / 10;
        }
        obj.insertLast(iSum);
        temp = temp->next;
    } while (temp != Tail->next);

    return obj;
}

/******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Function : evenNo(onlu applicable for integers)
    Name of the Author : Payal Shrikrushna Deshpande
    Date : 13 April 2022
    Parameters : None
    Description: This function returns the linked list which contains even numbers from given
                singly circular linked list.

****************************************************************************************************/

template <>
singlyCL<int> singlyCL<int>::evenNo()
{
    struct nodeS<int> *temp = Head;
    bool flag = false;
    singlyCL<int> obj;
    if (temp == NULL && Tail == NULL)
    {
        cout << "There are no elements in linked list ." << endl;
        return obj;
    }

    do
    {
        if ((temp->data) % 2 == 0)
        {
            flag = true;
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    } while (temp != Tail->next);
    if (flag == false)
    {
        cout << "No Even elements in linked list." << endl;
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : oddNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns linked list which contains odd numbers from given
                singly circular linked list.

****************************************************************************************************/

template <>
singlyCL<int> singlyCL<int>::oddNo()
{
    struct nodeS<int> *temp = Head;
    singlyCL<int> obj;
    bool flag = false;
    if (temp == NULL && Tail == NULL)
    {
        cout << "There are no elements in linked list ." << endl;
        return obj;
    }

    do
    {
        if ((temp->data) % 2 != 0)
        {
            flag = true;
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    } while (temp != Tail->next);
    if (flag == false)
    {
        cout << "No Even elements in linked list." << endl;
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : searchElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns boolean value depends upon number is present or not in
                 singly circular linked list.

****************************************************************************************************/

template <class T>
bool singlyCL<T>::searchElement(T no)
{
    struct nodeS<T> *temp = Head;
    bool flag = false;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    do
    {
        if (temp->data == no)
        {
            flag = true;
            break;
        }
        temp = temp->next;
    } while (temp != Tail->next);
    return flag;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayPrimeNo(only applicable for int datatype)
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains prime numbers from given
                  singly circular linked list.

****************************************************************************************************/

template <>
singlyCL<int> singlyCL<int>::displayPrimeNo()
{
    bool flag = false;
    struct nodeS<int> *temp = Head;
    singlyCL<int> obj;
    do
    {
        for (int iCnt = 2; iCnt < (temp->data) / 2; iCnt++)
        {
            if (temp->data % iCnt == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    } while (temp != Tail->next);
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : frequencyOfElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns the frequency of given element from singly circular
                 linked list.

****************************************************************************************************/

template <class T>
int singlyCL<T>::frequencyOfElement(T no)
{
    struct nodeS<T> *temp = Head;
    int Counter = 0;
    bool flag = false;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    do
    {
        if (temp->data == no)
        {
            flag == true;
            Counter++;
        }
        temp = temp->next;
    } while (temp != Tail->next);
    if (flag == false)
    {
        cout << "There is no such element in linked list" << endl;
    }
    return Counter;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Class : doublyLL
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This is the class of doubly linear linked list.

****************************************************************************************************/

template <class T>
class doublyLL
{
public:
    struct nodeD<T> *Head;
    doublyLL();
    void display();
    int count();
    void insertFirst(T no);
    void insertLast(T no);
    void insertAtPos(int pos, T no);

    void deleteFirst();
    void deleteLast();
    void deleteAtPos(int pos);
    int checkFirstOccurance(T no);
    int checkLastOccurance(T no);
    int largestElement();
    T smallestElement();
    doublyLL<int> displayPerfectNo();
    doublyLL<int> displayPrimeNo();
    int displayAddition();
    int displaySecondMax();
    doublyLL<int> evenNo();
    doublyLL<int> oddNo();
    doublyLL<int> addDigitOfEachElement();
    bool searchElement(T no);
    int frequencyOfElement(T no);
};

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Constructor : doublyLL
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This is the constructor of doubly Linear linked list.

***************************************************************************************************/

template <class T>
doublyLL<T>::doublyLL()
{
    Head = NULL;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : display
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function displays the elements of doubly  Linear linked list.

****************************************************************************************************/

template <class T>
void doublyLL<T>::display()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty:\n";
        return;
    }
    else
    {
        struct nodeD<T> *temp = Head;
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : count
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function counts the number of elements from doubly Linear linked list.

****************************************************************************************************/

template <class T>
int doublyLL<T>::count()
{
    int iCnt = 0;
    if (Head == NULL)
    {
        cout << "Linked list is empty:\n";
        return 0;
    }
    else
    {
        struct nodeD<T> *temp = Head;

        while (temp != NULL)
        {
            iCnt++;
            temp = temp->next;
        }
    }
    return iCnt;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertFirst
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function inserts an element at first position of doubly
                    Linear linked list.

****************************************************************************************************/

template <class T>
void doublyLL<T>::insertFirst(T no)
{
    struct nodeD<T> *newn = new struct nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
        Head->prev = NULL;
        Head->next = NULL;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertLast
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function inserts an element at last position of  doubly Linear
                  linked list.

****************************************************************************************************/

template <class T>
void doublyLL<T>::insertLast(T no)
{
    struct nodeD<T> *newn = new struct nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
        Head->next = NULL;
        Head->prev = NULL;
    }
    else
    {
        struct nodeD<T> *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertAtPos
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no,int pos
     Description: This function inserts an element at specific position in doubly Linear
                  linked list.

****************************************************************************************************/

template <class T>
void doublyLL<T>::insertAtPos(int pos, T no)
{
    int nodeCnt = 0;
    nodeCnt = count();

    if (pos < 1 || pos > nodeCnt + 1)
    {
        cout << "Invalid position:\n";
        return;
    }
    if (pos == 1)
    {
        insertFirst(no);
    }
    else if (pos == nodeCnt + 1)
    {
        insertLast(no);
    }
    else
    {
        struct nodeD<T> *newn = new struct nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        struct nodeD<T> *temp = Head;
        int iCnt = 1;
        while (iCnt < pos - 1)
        {
            temp = temp->next;
        }
        newn->next = temp->next;

        temp->next = newn;
        newn->prev = temp;
        newn->next->prev = newn;
    }
}

/******************************************************************************************************

         Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
         Name of the Function : deleteFirst
         Name of the Author : Payal Shrikrushna Deshpande
         Date : 13 April 2022
         Parameters : None
         Description: This function deletes first element of doubly Linear linked list.

****************************************************************************************************/

template <class T>
void doublyLL<T>::deleteFirst()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty:\n";
        return;
    }
    if (count() == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct nodeD<T> *temp = Head;
        Head = Head->next;
        delete temp;
        Head->prev = NULL;
        temp = NULL;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkFirstOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T iData
     Description: This function deletes the last element of doubly Linear linked list.

****************************************************************************************************/

template <class T>
void doublyLL<T>::deleteLast()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty:\n";
        return;
    }
    else if (count() == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct nodeD<T> *temp = Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteAtPos
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T iData
     Description: This function deletes the element from given position in Doubly Linear linked list.

****************************************************************************************************/

template <class T>
void doublyLL<T>::deleteAtPos(int pos)
{
    int nodeCnt = 0;
    nodeCnt = count();

    if (pos < 1 || pos > nodeCnt)
    {
        cout << "Invalid Positions:\n";
        return;
    }
    if (pos == 1)
    {
        deleteFirst();
    }
    else if (pos == nodeCnt)
    {
        deleteLast();
    }
    else
    {
        struct nodeD<T> *temp1 = Head;
        struct nodeD<T> *temp2 = NULL;
        int iCnt = 1;
        while (iCnt < pos - 1)
        {
            temp1 = temp1->next;
            iCnt++;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp2->prev;
        delete temp2;
        temp2 = NULL;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkFirstOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns the first occurance index of given element
      doubly Linear linked list.

****************************************************************************************************/

template <class T>
int doublyLL<T>::checkFirstOccurance(T no)
{
    struct nodeD<T> *temp = Head;
    int iTemp = -1, iCounter = 1;

    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }

    while (temp != NULL)
    {
        if (temp->data == no)
        {
            iTemp = iCounter;
            break;
        }
        iCounter++;
        temp = temp->next;
    }
    if (iTemp == -1)
    {
        cout << "There is no any elements in linked list" << endl;
    }
    return iTemp;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkLastOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns the last occurance index of given element
                 doubly Linear linked list.

****************************************************************************************************/

template <class T>
int doublyLL<T>::checkLastOccurance(T no)
{
    struct nodeD<T> *temp = Head;
    int iTemp = -1, iCounter = 1;

    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }

    while (temp != NULL)
    {
        if (temp->data == no)
        {
            iTemp = iCounter;
        }
        iCounter++;
        temp = temp->next;
    }
    if (iTemp == -1)
    {
        cout << "There is no any elements in linked list" << endl;
    }
    return iTemp;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : largestElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the largest element of doubly Linear linked list.

****************************************************************************************************/

template <class T>
int doublyLL<T>::largestElement()
{
    struct nodeD<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "linked list is empty" << endl;
    }
    int max = 0;
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : smallestElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns smallest element of doubly Linear linked list.

****************************************************************************************************/

template <class T>
T doublyLL<T>::smallestElement()
{
    struct nodeD<T> *temp = Head;
    T min;
    if (temp == NULL)
    {
        cout << "linked list is empty" << endl;
    }

    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayPerfectNo(only applicable for int datatype)
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains perfect no from doubly Linear linked list.

****************************************************************************************************/

template <>
doublyLL<int> doublyLL<int>::displayPerfectNo()
{
    struct nodeD<int> *temp = Head;
    doublyLL<int> obj;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
        return obj;
    }

    else
    {
        while (temp != NULL)
        {
            int iSum = 0;
            for (int i = 1; i <= (temp->data) / 2; i++)
            {
                if (temp->data % i == 0)
                {
                    iSum = iSum + i;
                }
            }
            if (iSum == temp->data)
            {
                obj.insertLast(temp->data);
            }
            temp = temp->next;
        }
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayPrimeNo(only applicable for int datatype)
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains prime no from doubly Linear linked list.

****************************************************************************************************/

template <>
doublyLL<int> doublyLL<int>::displayPrimeNo()
{
    struct nodeD<int> *temp = Head;
    doublyLL<int> obj;
    if (temp == NULL)
    {
        cout << "Linked list is empty ." << endl;
        return obj;
    }
    else
    {
        while (temp != NULL)
        {
            int flag = -1;
            if (temp->data == 2)
            {
                flag = -1;
            }
            else
            {
                for (int i = 2; i <= (temp->data) / 2; i++)
                {
                    if (temp->data % i == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag != 1)
            {
                obj.insertLast(temp->data);
            }
            temp = temp->next;
        }
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayAddition
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the addition of elements from doubly Linear linked list.

****************************************************************************************************/

template <class T>
int doublyLL<T>::displayAddition()
{
    int iSum;
    struct nodeD<T> *temp = Head;
    if (temp == NULL)
    {
        cout << "linked list is empty" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            iSum = iSum + (temp->data);
            temp = temp->next;
        }
    }
    return iSum;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displaySecondMax
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the second maximum number from doubly Linear linked list.

****************************************************************************************************/

template <class T>
int doublyLL<T>::displaySecondMax()
{
    struct nodeD<T> *temp = Head;
    int max1 = -1, max2;
    if (temp == NULL)
    {
        cout << "Linked list is empty " << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data > max1)
            {
                max2 = max1;
                max1 = temp->data;
            }
            else if (temp->data > max2)
            {
                max2 = temp->data;
            }
            temp = temp->next;
        }
    }
    return max2;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function :evenNo(only applicable for int datatype)
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains even no from doubly Linear linked list.

****************************************************************************************************/

template <>
doublyLL<int> doublyLL<int>::evenNo()
{
    doublyLL<int> obj;
    bool flag = false;
    struct nodeD<int> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            flag = true;
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : oddNo(only applicable for int datatype)
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains odd no from doubly Linear linked list.

****************************************************************************************************/

template <>
doublyLL<int> doublyLL<int>::oddNo()
{
    doublyLL<int> obj;
    bool flag = false;
    struct nodeD<int> *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (temp != NULL)
    {
        if ((temp->data) % 2 != 0)
        {
            flag = true;
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "There are no odd elements." << endl;
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : searchElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns the boolean value depends upon number is present or not in doubly Linear linked list.

****************************************************************************************************/

template <class T>
bool doublyLL<T>::searchElement(T no)
{
    struct nodeD<T> *temp = Head;
    bool flag = false;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    while (temp != NULL)
    {
        if (temp->data == no)
        {
            flag = true;
            break;
        }
        temp = temp->next;
    }
    return flag;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : frequencyOfElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns the frequency of given element from doubly Linear linked list.

****************************************************************************************************/

template <class T>
int doublyLL<T>::frequencyOfElement(T no)
{
    struct nodeD<T> *temp = Head;
    bool flag = false;
    int Counter = 0;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    while (temp != NULL)
    {
        if (temp->data == no)
        {
            flag = true;
            Counter++;
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "There is no such Element" << endl;
    }
    return Counter;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Class : doublyCL
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This is the class for doubly circular linked list.

****************************************************************************************************/

template <class T>
class doublyCL
{
public:
    struct nodeD<T> *first;
    struct nodeD<T> *last;

    doublyCL();
    void Display();
    int Count();
    void insertFirst(T no);
    void insertLast(T no);
    void insertAtPos(T no, int pos);
    void deleteFirst();
    void deleteLast();
    void deleteAtPos(int pos);
    int checkFirstOccurance(T no);
    int checkLastOccurance(T no);
    int largestElement();
    T smallestElement();
    doublyCL<int> displayPerfectNo();
    doublyCL<int> displayPrimeNo();
    T displayAddition();
    T displaySecondMax();
    doublyCL<int> evenNo();
    doublyCL<int> oddNo();
    doublyCL<int> addDigitOfEachElement();
    bool searchElement(T no);
    int frequencyOfElement(T no);
};

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Constructor : doublyCL
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This is the Constructor of class doubly circular linked list.

****************************************************************************************************/

template <class T>
doublyCL<T>::doublyCL()
{
    first = NULL;
    last = NULL;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : Display
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function displays the elements of doubly circular linked list.

****************************************************************************************************/

template <class T>
void doublyCL<T>::Display()
{
    if (first == NULL)
    {
        cout << "empty doubly circular linked list:\n";
        return;
    }
    else
    {
        struct nodeD<T> *temp1 = first;
        struct nodeD<T> *temp2 = last;
        do
        {
            cout << "|" << temp1->data << "|->";
            temp1 = temp1->next;
        } while (temp1 != temp2->next);
        cout << "NULL\n";
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function: Count
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function return the number of elements of doubly circular linked list.

****************************************************************************************************/

template <class T>
int doublyCL<T>::Count()
{
    if (first == NULL && last == NULL)
    {
        cout << "there are no nodes in linked list:\n";
        return 0;
    }
    else
    {
        struct nodeD<T> *temp1 = first;
        struct nodeD<T> *temp2 = last;
        int cnt = 0;
        do
        {
            cnt++;
            temp1 = temp1->next;
        } while (temp1 != temp2->next);
        return cnt;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertFirst
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function insert an element at first position to doubly circular linked list.

****************************************************************************************************/

template <class T>
void doublyCL<T>::insertFirst(T no)
{
    struct nodeD<T> *newn = new nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    if (first == NULL)
    {
        first = last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
        // last->next = first;
    }
    first->prev = last;
    last->next = first;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertLast
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function insert an element at Last position to doubly
                   circular linked list.

****************************************************************************************************/

template <class T>
void doublyCL<T>::insertLast(T no)
{
    struct nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertAtPos
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no,int pos
     Description: This function insert an element at specific position to
                doubly circular linked list.

****************************************************************************************************/

template <class T>
void doublyCL<T>::insertAtPos(T no, int pos)
{
    int nodeCnt = Count();
    if (pos < 1 || pos > nodeCnt + 1)
    {
        cout << "invalid choice:\n";
        return;
    }
    if (pos == 1)
    {
        insertFirst(no);
    }
    else if (pos == nodeCnt + 1)
    {
        insertLast(no);
    }
    else
    {
        struct nodeD<T> *newn = new nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        struct nodeD<T> *temp = first;
        int iCnt = 1;
        while (iCnt < pos - 1)
        {
            temp = temp->next;
            iCnt++;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    last->next = first;
    first->prev = last;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteFirst
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function deletes an element at first position from doubly circular linked list.

****************************************************************************************************/

template <class T>
void doublyCL<T>::deleteFirst()
{
    if (first == NULL && last == NULL)
    {
        cout << "linked list is empty:\n";
        return;
    }
    else
    {
        struct nodeD<T> *temp = first;
        first = first->next;
        delete temp;
        last->next = first;
        first->prev = last;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteLast
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function deletes an element at Last position from doubly circular linked list.

****************************************************************************************************/

template <class T>
void doublyCL<T>::deleteLast()
{
    if (first == NULL && last == NULL)
    {
        cout << "invalid position";
        return;
    }
    else
    {
        struct nodeD<T> *temp = first;
        struct nodeD<T> *temp2 = last;
        while (temp->next->next != last)
        {
            temp = temp->next;
        }
        delete temp2;
        last = temp->next;
        last->next = first;
        first->prev = last;
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteAtPos
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : int pos
     Description: This function deletes an element at specific position from doubly circular linked list.

****************************************************************************************************/

template <class T>
void doublyCL<T>::deleteAtPos(int pos)
{
    int nodeCnt = Count();
    if (pos < 1 || pos > nodeCnt)
    {
        cout << "invalid choice\n";
        return;
    }
    if (pos == 1)
    {
        deleteFirst();
    }
    else if (pos == nodeCnt)
    {
        deleteLast();
    }
    else
    {
        int iCnt = 1;
        struct nodeD<T> *temp = first;
        struct nodeD<T> *temp2 = NULL;
        while (iCnt < pos - 1)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        delete temp2;
        temp2 = NULL;
    }
    last->next = first;
    first->prev = last;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function :checkFirstOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function return first ocuurance of given element from doubly circular linked list.

****************************************************************************************************/

template <class T>
int doublyCL<T>::checkFirstOccurance(T no)
{
    int iCount = 1, iPos = -1;
    struct nodeD<T> *temp = first;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        if (temp->data == no)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        temp = temp->next;
    } while (temp != last->next);
    if (iPos == -1)
    {
        cout << "There is no such element in linked list." << endl;
    }
    return iPos;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : checkLastOccurance
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function returns last occurance of given element from doubly circular linked list.

****************************************************************************************************/

template <class T>
int doublyCL<T>::checkLastOccurance(T no)
{
    int iCount = 0, iPos = -1;
    struct nodeD<T> *temp = last;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    else
    {
        do
        {
            if (temp->data == no)
            {
                iPos = iCount;
                break;
            }
            iCount++;
            temp = temp->prev;
        } while (temp != first->prev);
    }
    if (iPos == -1)
    {
        return iPos;
    }
    else
    {
        return (Count() - iPos);
    }
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : largestElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters :None
     Description: This function returns the largset element from doubly circular linked list.

****************************************************************************************************/

template <class T>
int doublyCL<T>::largestElement()
{
    struct nodeD<T> *temp = first;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    T max = temp->data;
    do
    {
        if ((temp->data) > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    } while (temp != last->next);
    return max;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : smallestElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function return smallest element from doubly circular linked list.

****************************************************************************************************/

template <class T>
T doublyCL<T>::smallestElement()
{
    struct nodeD<T> *temp = first->next;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    T min = temp->data;
    do
    {
        if ((temp->data) < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    } while (temp != last->next);
    return min;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayPerfectNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function return linked list which contains perfect  numbers from given doubly circular linked list.

****************************************************************************************************/

template <class T>
doublyCL<int> doublyCL<T>::displayPerfectNo()
{
    struct nodeD<T> *temp = first;
    doublyCL obj;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        int iNum = temp->data, iSum = 0;

        for (int i = 1; i <= iNum / 2; i++)
        {

            if (iNum % i == 0)
            {
                iSum = iSum + i;
            }
        }
        if (iSum == temp->data)
        {
            obj.insertLast(iSum);
        }
        temp = temp->next;
    } while (temp != last->next);
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayAddition
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters :None
     Description: This function return the addition of elements from doubly circular linked list.

****************************************************************************************************/

template <class T>
T doublyCL<T>::displayAddition()
{
    struct nodeD<T> *temp = first;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    T iSum = 0;
    do
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    } while (temp->next != first);
    return iSum;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displaySecondMax
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the second maximum element from doubly circular linked list.

****************************************************************************************************/

template <class T>
T doublyCL<T>::displaySecondMax()
{
    struct nodeD<T> *temp = first;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    T max1 = 0.0, max2 = 0.0;
    do
    {
        if (temp->data > max1)
        {
            max2 = max1;
            max1 = temp->data;
        }
        else if (temp->data > max2)
        {
            max2 = temp->data;
        }
        temp = temp->next;
    } while (temp != last->next);
    return max2;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : displayPrimeNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains prime no from  doubly circular linked list.

****************************************************************************************************/

template <>
doublyCL<int> doublyCL<int>::displayPrimeNo()
{
    bool flag = false;
    struct nodeD<int> *temp = first;
    doublyCL<int> obj;
    do
    {
        for (int iCnt = 2; iCnt < (temp->data) / 2; iCnt++)
        {
            if (temp->data % iCnt == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    } while (temp != last->next);
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : addDigitOfEachElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns linked list which contains addition of digit of each element from doubly circular linked list.

****************************************************************************************************/

template <>
doublyCL<int> doublyCL<int>::addDigitOfEachElement()
{
    struct nodeD<int> *temp = first;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    doublyCL<int> obj;
    do
    {
        int iNum = temp->data;
        int iSum = 0, iDigit = 0;
        while (iNum != '\0')
        {
            iDigit = iNum % 10;
            iSum = iSum + iDigit;
            iNum = iNum / 10;
        }
        obj.insertLast(iSum);
        temp = temp->next;
    } while (temp != last->next);

    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : evenNo(only applicable for int datatype)
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters :None
     Description: This function returns the linked list which conatins even numbers from doubly circular linked list.

****************************************************************************************************/

template <>
doublyCL<int> doublyCL<int>::evenNo()
{
    struct nodeD<int> *temp = first;
    bool flag = false;
    doublyCL obj;
    if (temp == NULL && last == NULL)
    {
        cout << "There are no elements in linked list ." << endl;
        return obj;
    }

    do
    {
        if ((temp->data) % 2 == 0)
        {
            flag = true;
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    } while (temp != last->next);
    if (flag == false)
    {
        cout << "No Even elements in linked list." << endl;
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : oddNo
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains odd numbers from doubly circular linked list.

****************************************************************************************************/

template <>
doublyCL<int> doublyCL<int>::oddNo()
{
    struct nodeD<int> *temp = first;
    doublyCL<int> obj;
    bool flag = false;
    if (temp == NULL && last == NULL)
    {
        cout << "There are no elements in linked list ." << endl;
        return obj;
    }

    do
    {
        if ((temp->data) % 2 != 0)
        {
            flag = true;
            obj.insertLast(temp->data);
        }
        temp = temp->next;
    } while (temp != last->next);
    if (flag == false)
    {
        cout << "No Even elements in linked list." << endl;
    }
    return obj;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : searchElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function searches given element from doubly circular linked list.

****************************************************************************************************/

template <class T>
bool doublyCL<T>::searchElement(T no)
{
    struct nodeD<T> *temp = first;
    bool flag = false;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    do
    {
        if (temp->data == no)
        {
            flag = true;
            break;
        }
        temp = temp->next;
    } while (temp != last->next);
    return flag;
}

/******************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : frequencyOfElement
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T no
     Description: This function return the frequency of given element from doubly circular linked list.

****************************************************************************************************/

template <class T>
int doublyCL<T>::frequencyOfElement(T no)
{
    struct nodeD<T> *temp = first;
    int Counter = 0;
    bool flag = false;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    do
    {
        if (temp->data == no)
        {
            flag = true;
            Counter++;
        }
        temp = temp->next;
    } while (temp != last->next);
    if (flag == false)
    {
        cout << "There is no such element in linked list" << endl;
    }
    return Counter;
}

/*********************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Class : Stack
      Name of the Author : Payal Shrikrushna Deshpande
      Date : 13 April 2022
      Parameters : None
      Description: This is the Class of the Stack

//******************************************************************************************************/
template <class T>
class Stack
{
public:
    struct nodeS<T> *First;
    int iCount;

    Stack();

    bool IsStackEmpty();
    void Push(T no); // Insert
    T Pop();         // Delete
    void Display();
};

/********************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : Stack
      Name of the Author : Payal Shrikrushna Deshpande
      Date : 13 April 2022
      Parameters : None
      Description: This is the constructor of the Stack Class.

//*******************************************************************************************/
template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

/*************************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : isStackEmpty
      Name of the Author : Payal Shrikrushna Deshpande
      Date : 13 April 2022
      Parameters : None
      Description: This function returns true if stack is empty and returns false if stack is not empty.

//********************************************************************************************/
template <class T>
bool Stack<T>::IsStackEmpty()
{
    if (iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/******************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : push
      Name of the Author : Payal Shrikrushna Deshpande
      Date : 13 April 2022
      Parameters : None
      Description: This function pushes(insert) element in Stack.

//*****************************************************************************************/
template <class T>
void Stack<T>::Push(T no) // insertFirst
{
    struct nodeS<T> *newn = new nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
    cout << no << "\nGets pushed in the stack successfully\n";
}

/***********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : pop
      Name of the Author : Payal Shrikrushna Deshpande

      Date : 13 April 2022
      Parameters : None
      Description: This function pops the top most element and returns it from Stack.

//**************************************************************************************/
template <class T>
T Stack<T>::Pop()
{
    if (First == NULL)
    {
        cout << "Unable to pop element as stack is empty."
             << "\n";
        return -1;
    }
    else
    {
        T value = First->data;
        struct nodeS<T> *temp = First;
        First = First->next;
        delete temp;

        iCount--;
        return value;
    }
}

/*****************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : display
      Name of the Author : Payal Shrikrushna Deshpande

      Date : 13 April 2022
      Parameters : None
      Description: This function displays elements of Stack.

//****************************************************************************************/

template <class T>
void Stack<T>::Display()
{
    if (First == NULL)
    {
        cout << "Stack is empty:";
    }
    else
    {
        cout << "Elements of stack are :"
             << "\n";
        struct nodeS<T> *temp = First;
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

/*********************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Class : Queue
      Name of the Author : Payal Shrikrushna Deshpande

      Date : 13 April 2022
      Parameters : None
      Description: This is the class of Queue.

//*********************************************************************************************/

template <class T>
class Queue
{
public:
    struct nodeS<T> *First;
    int iCount;

    Queue();

    bool IsQueueEmpty();
    void EnQueue(T no); // Insert
    T DeQueue();        // Delete
    void Display();
};

/**********************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : Queue
      Name of the Author :Payal Shrikrushna Deshpande

      Date : 13 April 2022
      Parameters : None
      Description: This is the default constructor of the class.

//***********************************************************************************************/

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

/*****************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : isQueueEmpty
      Name of the Author : Payal Shrikrushna Deshpande

      Date : 13 April 2022
      Parameters : None
      Description: This function returns true if Queue is Empty and returns false if Queue is Not Empty

//*********************************************************************************************/
template <class T>
bool Queue<T>::IsQueueEmpty()
{
    if (iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : isQueueEmpty
      Name of the Author : Payal Shrikrushna Deshpande

      Date : 13 April 2022
      Parameters : None
      Description: This function returns true if Queue is Empty and returns false if Queue is Not Empty

//*****************************************************************************/

template <class T>
void Queue<T>::EnQueue(T no) // insertLast
{
    struct nodeS<T> *newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;
    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeS<T> *temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

/*****************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : deQueue
      Name of the Author : Payal Shrikrushna Deshpande

      Parameters : None
      Description: This function deletes the element and returns it from the Queue.

//**************************************************************************************/

template <class T>
T Queue<T>::DeQueue()
{
    if (First == NULL)
    {
        cout << "Queue is empty";
        return -1;
    }
    else
    {
        struct nodeS<T> *temp = First;
        T value = First->data;

        First = First->next;
        delete temp;
        iCount--;
        return value;
    }
}

/*****************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : display
      Name of the Author :Payal Shrikrushna Deshpande

      Date : 13 April 2022
      Parameters : None
      Description: This function displays the elements in the Queue.

//*******************************************************************************/

template <class T>
void Queue<T>::Display()
{
    if (First == NULL)
    {
        cout << "Queue is empty:";
        return;
    }
    else
    {
        struct nodeS<T> *temp = First;
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

/*****************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the function : Main (Driver Code)
     Name of the Author : Payal Shrikrushna Deshpande

     Date : 13 April 2022
     Parameters : None
     Description: This is the Driver Function for this project.

********************************************************************************/
int main()
{

    return 0;
}
