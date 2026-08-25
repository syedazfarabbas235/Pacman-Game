#include "Game.h"

using namespace std;


// =====================================================
// ENQUEUE
// =====================================================

void enqueue(int r, int c)
{
    QueueNode* temp =
        new QueueNode;

    temp->row = r;
    temp->col = c;
    temp->next = nullptr;


    if (rear == nullptr)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}


// =====================================================
// DEQUEUE
// =====================================================

QueueNode* dequeue()
{
    if (front == nullptr)
        return nullptr;


    QueueNode* cur =
        front;

    front =
        front->next;


    if (front == nullptr)
    {
        rear = nullptr;
    }


    return cur;
}


// =====================================================
// CLEAR QUEUE
// =====================================================

void clearQueue()
{
    while (front != nullptr)
    {
        QueueNode* temp =
            dequeue();

        delete temp;
    }
}


// =====================================================
// PUSH
// =====================================================

void push(int r, int c)
{
    StackNode* temp =
        new StackNode;

    temp->row = r;
    temp->col = c;

    temp->next = top;

    top = temp;
}


// =====================================================
// POP
// =====================================================

StackNode* pop()
{
    if (top == nullptr)
        return nullptr;


    StackNode* temp =
        top;

    top =
        top->next;


    return temp;
}


// =====================================================
// CLEAR STACK
// =====================================================

void clearStack()
{
    while (top != nullptr)
    {
        StackNode* temp =
            pop();

        delete temp;
    }
}
