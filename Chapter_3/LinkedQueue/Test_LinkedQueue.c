#include "LinkedQueue.h"

int main( void )
{
    Node* Popped;
    LinkedQueue* Queue;

    LQ_CreateQueue(&Queue );        /* ť ���� */

    /* ��� �����Ͽ� ť�� �߰�*/
    LQ_Enqueue( Queue, LQ_CreateNode("abc") );
    LQ_Enqueue( Queue, LQ_CreateNode("def") );
    LQ_Enqueue( Queue, LQ_CreateNode("efg") );
    LQ_Enqueue( Queue, LQ_CreateNode("hij") );

    printf("Queue Size : %d\n", Queue->Count);      /* Queue Size : 4 */

    while ( LQ_IsEmpty( Queue ) == 0 )              /* ť�� ������� �ʴµ��� */
    {
        Popped = LQ_Dequeue( Queue );       /* ť���� ��� ���� */

        printf( "Dequeue: %s \n", Popped->Data );       /* �տ����� ��� ������ ���� */

        LQ_DestroyNode( Popped );       /* ��� ���� */
    }

    LQ_DestroyQueue( Queue );       /* ť ���� */

    return 0;
}