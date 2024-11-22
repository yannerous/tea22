#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <fmt/chrono.h>
#include <fmt/format.h>

template <typename T>
struct ListNode{
    ListNode<T>* nextPtr;
    T* dataPtr;
};
template <typename T>
struct LinkedList{
    int size;
    ListNode<T>* headPtr;
    ListNode<T>* tailPtr;
};

template <typename T>
ListNode<T>* newListNode(T* dataPtr)
{
    ListNode<T>* nodePtr = (ListNode<T>*)malloc(sizeof(ListNode<T>));
    nodePtr->dataPtr = dataPtr;
    nodePtr->nextPtr = NULL;

    return nodePtr;
}

template <typename T>
void FreeNode(ListNode<T>* nodePtr)
{
    free(nodePtr);
}

template <typename T>
void addToList(LinkedList<T>* ListPtr,T* dataPtr)
{
    ListNode<T>* nodePtr = newListNode(dataPtr);

    //catch first Element
    if(ListPtr->headPtr == NULL)
    {
        ListPtr->headPtr = nodePtr;
        ListPtr->tailPtr = nodePtr;
    }

    //add new Node behind current tail
    ListPtr->tailPtr->nextPtr = nodePtr;

    //switch tail to new Node
    ListPtr->tailPtr = nodePtr;

    //update size
    ListPtr->size +=1;
}
template <typename T>
T RemoveFromList(LinkedList<T>* ListPtr, T* dataPtr)
{
    //catch empty List
    if(ListPtr->headPtr == NULL)
    {
        fmt::print("List is empty");
        return 0;
    }
    //node is first
    if(ListPtr->headPtr->dataPtr == dataPtr)
    {
        //save the pointer to free it
        ListNode<T>* nodePtr = ListPtr->headPtr;
        //remove it from the List
        ListPtr->headPtr = ListPtr->headPtr->nextPtr;

        //update size
        ListPtr->size -=1;

        //if list is now empty
        if( ListPtr->headPtr == NULL)
        {
            ListPtr->tailPtr = NULL;
            ListPtr->size = 0;
        }


        //save value and free space
        T data = *(nodePtr->dataPtr);
        FreeNode(nodePtr);
        return data;
    }

    ListNode<T>* curNodePtr = ListPtr->headPtr;

    while(curNodePtr->nextPtr->dataPtr !=dataPtr \
       && curNodePtr->nextPtr != NULL)
    {
        curNodePtr=curNodePtr->nextPtr;
    }

    //Element not in List
    if(curNodePtr->nextPtr == NULL)
    {
        fmt::print("Element is not in List");
        return 0;
    }
    //save the pointer to free it later 
    ListNode<T>* nodePtr = curNodePtr->nextPtr;
    //remove from list
    curNodePtr->nextPtr = curNodePtr->nextPtr->nextPtr;

    //Node is Last
    if(curNodePtr->nextPtr == NULL)
        ListPtr->tailPtr = curNodePtr;

    //update size
    ListPtr->size -=1;

    //save value and free space
    T data = *(nodePtr->dataPtr);
    FreeNode(nodePtr);

    return data;
}

template <typename T>
void printList(LinkedList<T>* listPtr)
{
    ListNode<T>* curNode = listPtr->headPtr;
    
    while (curNode != NULL)
    {
        fmt::print("{}\n", *(curNode->dataPtr));
        curNode = curNode->nextPtr;
    }
    
}
#endif