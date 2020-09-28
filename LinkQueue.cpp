#include <iostream>
#include <stdlib.h>

typedef struct
{
    int data;
    QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;