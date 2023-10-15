#include "LinkedQueue.h"

void  LQ_CreateQueue( LinkedQueue** Queue )
{
    /*  ť�� ��������ҿ� ���� */
    (*Queue )        = ( LinkedQueue*)malloc(sizeof( LinkedQueue ) );   /* ť �޸� �Ҵ� */
    (*Queue )->Front = NULL;
    (*Queue )->Rear  = NULL;
    (*Queue )->Count = 0;
}

void LQ_DestroyQueue( LinkedQueue* Queue )
{
    while ( !LQ_IsEmpty( Queue ) )              /* ť�� ����������� Popped�� */
    {
        Node* Popped = LQ_Dequeue( Queue );
        LQ_DestroyNode(Popped);    
    }

    /*  ť�� ���� ����ҿ��� ���� */
    free( Queue );
}

Node* LQ_CreateNode( char* NewData )            /* ��� ���� */
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );
    NewNode->Data = (char*)malloc( strlen( NewData) + 1);

    strcpy(NewNode->Data, NewData);  /*  �����͸� �����Ѵ�. */

    NewNode->NextNode = NULL; /*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

void  LQ_DestroyNode(Node* _Node )              /* ��� ���� (���� ��� ���� �����͸� ����) */
{
    free(_Node->Data);
    free(_Node );
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )        /* ť�� ���ο� ��� �߰� */
{
    if ( Queue->Front == NULL )         /* ť ������ִٸ� ���ο� ��� �߰��ϱ� ���� �� ť�� �ʱ�ȭ */
    {        
        Queue->Front = NewNode;
        Queue->Rear  = NewNode;
        Queue->Count++;
    } 
    else                /* ť ������� �ʴٸ� ���ο� ��带 ť�� �ڿ� �߰� */
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
}

Node* LQ_Dequeue( LinkedQueue* Queue )              /* ť�� ��� ���� */
{
    /*  LQ_Dequeue() �Լ��� ��ȯ�� �ֻ��� ��� */
    Node* Front = Queue->Front;     /* ť�� �Ǿտ� ��带 Front�� ���� */

    if ( Queue->Front->NextNode == NULL )       /* ť�� �Ǿ� ����� ���� ��尡 ���� ��� */
    {
        Queue->Front = NULL;        /* ť ��� */
        Queue->Rear  = NULL;        /* ť ��� */
    }
    else        /* ť�� �Ǿ� ����� ���� ��尡 �ִ� ��� */ 
    {
        Queue->Front = Queue->Front->NextNode;      /* �־��� ť�� �Ǿտ� ��带 ���� ���� �̵� (ť���� ���� ���� ��Ұ� ����) */
    }

    Queue->Count--;

    return Front;       /* ���ŵ� ��� ��ȯ */
}

int LQ_IsEmpty( LinkedQueue* Queue )        /* ť ����ִ��� ���� Ȯ�� */
{
    return ( Queue->Front == NULL);         /* ť�� ����ִ� ��� 1 ��ȯ */
}