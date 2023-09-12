#include "LinkedList.h"

/*  ��� ���� */
Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));    
    /* ���ο� ����� �����Ϳ� ���� ��带 ����Ű�� �����͸� �����ϱ� ���� ���� �Ҵ� */

    NewNode->Data = NewData;  /*  �����͸� �����Ѵ�. */
    NewNode->NextNode = NULL; /*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

/*  ��� �Ҹ� */
void SLL_DestroyNode(Node* Node)
{
    free(Node);     /* �Ҵ� �޸� ���� */
}

/*  ��� �߰� */
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  ��� ��尡 NULL�̶�� ���ο� ��尡 Head */
    if ( (*Head) == NULL ) 
    {        
        *Head = NewNode;
    } 
    else
    {
        /*  ������ ã�� NewNode�� �����Ѵ�. */
        Node* Tail = (*Head);
        while ( Tail->NextNode != NULL )    /* ������ ��带 ã�� ������ */
        {
            Tail = Tail->NextNode;      /* Node�� �������� Tail �����͸� ���� ��带 ����Ű���� */
        }

        Tail->NextNode = NewNode;       /* ���ο� ��忡 ���� */
    }
}

/*  ��� ���� */
void SLL_InsertAfter(Node* Current, Node* NewNode)  
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void  SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ( Head == NULL )     /* ����尡 �������� ���� ��� */
    {
        (*Head) = NewHead;    /* ���ο� ��带 ��� ���� ���� */
    }
    else
    {
        NewHead->NextNode = (*Head);    /* ��� ��带 ���ο� ����� ���� ���� ���� */
        (*Head) = NewHead;              /* ���ο� ��带 ���ο� ��� ���� ���� */
    }
}

/*  ��� ���� */
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if ( *Head == Remove )
    {
        *Head = Remove->NextNode;   /* ��� ���Ÿ� ���� ������带 ���� ���� */
    }
    else
    {
        Node* Current = *Head;      /* �ӽ� ������ �����Ͽ� ���� �ʱ�ȭ */
        while ( Current != NULL && Current->NextNode != Remove )    /* Remove ���� ��� ã�� �� ���� */
        {
            Current = Current->NextNode;    /* ���� ���� �̵� */
        }

        if ( Current != NULL )      /* Remove ��� ã���� ��� */
            Current->NextNode = Remove->NextNode; /* Remove ��带 ���� ����Ʈ�� �и� */
    }
}

/*  ��� Ž�� */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;       /* ������ ���� �� ��� �ʱ�ȭ */

    while ( Current != NULL && (--Location) >= 0)   /* Location 1�� ���� */
    {
        Current = Current->NextNode;    /* ���� ���� �̵� */
    }

    return Current;     /* ��� ��ġ ��ȯ */
}

/*  ��� �� ���� */
int SLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;   /* ������ ���� �� ��� �ʱ�ȭ */

    while ( Current != NULL )
    {
        Current = Current->NextNode;    /* ���� ���� �̵� */
        Count++;                        /* ��� �� ���� */
    }

    return Count;
}
