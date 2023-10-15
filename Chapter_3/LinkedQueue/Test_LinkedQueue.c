#include "LinkedQueue.h"

int main( void )
{
    Node* Popped;
    LinkedQueue* Queue;

    LQ_CreateQueue(&Queue );        /* 큐 생성 */

    /* 노드 생성하여 큐에 추가*/
    LQ_Enqueue( Queue, LQ_CreateNode("abc") );
    LQ_Enqueue( Queue, LQ_CreateNode("def") );
    LQ_Enqueue( Queue, LQ_CreateNode("efg") );
    LQ_Enqueue( Queue, LQ_CreateNode("hij") );

    printf("Queue Size : %d\n", Queue->Count);      /* Queue Size : 4 */

    while ( LQ_IsEmpty( Queue ) == 0 )              /* 큐가 비어있지 않는동안 */
    {
        Popped = LQ_Dequeue( Queue );       /* 큐에서 요소 제거 */

        printf( "Dequeue: %s \n", Popped->Data );       /* 앞에부터 노드 데이터 제거 */

        LQ_DestroyNode( Popped );       /* 노드 제거 */
    }

    LQ_DestroyQueue( Queue );       /* 큐 제거 */

    return 0;
}