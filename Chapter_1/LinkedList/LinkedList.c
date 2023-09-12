#include "LinkedList.h"

/*  노드 생성 */
Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));    
    /* 새로운 노드의 데이터와 다음 노드를 가리키는 포인터를 저장하기 위한 공간 할당 */

    NewNode->Data = NewData;  /*  데이터를 저장한다. */
    NewNode->NextNode = NULL; /*  다음 노드에 대한 포인터는 NULL로 초기화 한다. */

    return NewNode;/*  노드의 주소를 반환한다. */
}

/*  노드 소멸 */
void SLL_DestroyNode(Node* Node)
{
    free(Node);     /* 할당 메모리 해제 */
}

/*  노드 추가 */
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  헤드 노드가 NULL이라면 새로운 노드가 Head */
    if ( (*Head) == NULL ) 
    {        
        *Head = NewNode;
    } 
    else
    {
        /*  테일을 찾아 NewNode를 연결한다. */
        Node* Tail = (*Head);
        while ( Tail->NextNode != NULL )    /* 마지막 노드를 찾을 때까지 */
        {
            Tail = Tail->NextNode;      /* Node의 포인터인 Tail 포인터를 다음 노드를 가르키도록 */
        }

        Tail->NextNode = NewNode;       /* 새로운 노드에 연결 */
    }
}

/*  노드 삽입 */
void SLL_InsertAfter(Node* Current, Node* NewNode)  
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void  SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ( Head == NULL )     /* 헤드노드가 생성되지 않은 경우 */
    {
        (*Head) = NewHead;    /* 새로운 노드를 헤드 노드로 설정 */
    }
    else
    {
        NewHead->NextNode = (*Head);    /* 헤드 노드를 새로운 노드의 다음 노드로 연결 */
        (*Head) = NewHead;              /* 새로운 노드를 새로운 헤드 노드로 설정 */
    }
}

/*  노드 제거 */
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if ( *Head == Remove )
    {
        *Head = Remove->NextNode;   /* 노드 제거를 위해 다음노드를 헤드로 설정 */
    }
    else
    {
        Node* Current = *Head;      /* 임시 포인터 생성하여 헤드로 초기화 */
        while ( Current != NULL && Current->NextNode != Remove )    /* Remove 이전 노드 찾을 때 까지 */
        {
            Current = Current->NextNode;    /* 다음 노드로 이동 */
        }

        if ( Current != NULL )      /* Remove 노드 찾아진 경우 */
            Current->NextNode = Remove->NextNode; /* Remove 노드를 연결 리스트에 분리 */
    }
}

/*  노드 탐색 */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;       /* 포인터 생성 및 헤드 초기화 */

    while ( Current != NULL && (--Location) >= 0)   /* Location 1씩 감소 */
    {
        Current = Current->NextNode;    /* 다음 노드로 이동 */
    }

    return Current;     /* 노드 위치 반환 */
}

/*  노드 수 세기 */
int SLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;   /* 포인터 생성 및 헤드 초기화 */

    while ( Current != NULL )
    {
        Current = Current->NextNode;    /* 다음 노드로 이동 */
        Count++;                        /* 노드 수 증가 */
    }

    return Count;
}
