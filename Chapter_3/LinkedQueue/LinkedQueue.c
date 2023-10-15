#include "LinkedQueue.h"

void  LQ_CreateQueue( LinkedQueue** Queue )
{
    /*  큐를 자유저장소에 생성 */
    (*Queue )        = ( LinkedQueue*)malloc(sizeof( LinkedQueue ) );   /* 큐 메모리 할당 */
    (*Queue )->Front = NULL;
    (*Queue )->Rear  = NULL;
    (*Queue )->Count = 0;
}

void LQ_DestroyQueue( LinkedQueue* Queue )
{
    while ( !LQ_IsEmpty( Queue ) )              /* 큐가 비워질때까지 Popped됨 */
    {
        Node* Popped = LQ_Dequeue( Queue );
        LQ_DestroyNode(Popped);    
    }

    /*  큐를 자유 저장소에서 해제 */
    free( Queue );
}

Node* LQ_CreateNode( char* NewData )            /* 노드 생성 */
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );
    NewNode->Data = (char*)malloc( strlen( NewData) + 1);

    strcpy(NewNode->Data, NewData);  /*  데이터를 저장한다. */

    NewNode->NextNode = NULL; /*  다음 노드에 대한 포인터는 NULL로 초기화 한다. */

    return NewNode;/*  노드의 주소를 반환한다. */
}

void  LQ_DestroyNode(Node* _Node )              /* 노드 삭제 (노드와 노드 내의 데이터를 해제) */
{
    free(_Node->Data);
    free(_Node );
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )        /* 큐에 새로운 노드 추가 */
{
    if ( Queue->Front == NULL )         /* 큐 비워져있다면 새로운 노드 추가하기 위해 새 큐로 초기화 */
    {        
        Queue->Front = NewNode;
        Queue->Rear  = NewNode;
        Queue->Count++;
    } 
    else                /* 큐 비어있지 않다면 새로운 노드를 큐의 뒤에 추가 */
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
}

Node* LQ_Dequeue( LinkedQueue* Queue )              /* 큐에 노드 제거 */
{
    /*  LQ_Dequeue() 함수가 반환할 최상위 노드 */
    Node* Front = Queue->Front;     /* 큐의 맨앞에 노드를 Front로 저장 */

    if ( Queue->Front->NextNode == NULL )       /* 큐의 맨앞 노드의 다음 노드가 없는 경우 */
    {
        Queue->Front = NULL;        /* 큐 비움 */
        Queue->Rear  = NULL;        /* 큐 비움 */
    }
    else        /* 큐의 맨앞 노드의 다음 노드가 있는 경우 */ 
    {
        Queue->Front = Queue->Front->NextNode;      /* 주어진 큐의 맨앞에 노드를 다음 노드로 이동 (큐에서 가장 앞의 요소가 제거) */
    }

    Queue->Count--;

    return Front;       /* 제거된 노드 반환 */
}

int LQ_IsEmpty( LinkedQueue* Queue )        /* 큐 비어있는지 상태 확인 */
{
    return ( Queue->Front == NULL);         /* 큐가 비어있는 경우 1 반환 */
}