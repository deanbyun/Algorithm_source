#include "LinkedList.h"

int main( void )
{
    int   i       = 0;
    int   Count   = 0;
    Node* List    = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    /*  ��� 5�� �߰� */        

    for ( i = 0; i<5; i++ )
    {
        NewNode = SLL_CreateNode(i);        /* ��� ���� */
        SLL_AppendNode(&List, NewNode);     /* ��� �߰� */
    }
    /* List -> [0] -> [1] -> [2] -> [3] -> [4] -> NULL */

    NewNode = SLL_CreateNode(-1);           
    SLL_InsertNewHead(&List, NewNode);      /* ��� ���� */

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);
    /* List -> [-2] -> [-1] -> [0] -> [1] -> [2] -> [3] -> [4] -> NULL */

    /*  ����Ʈ ��� */
    Count = SLL_GetNodeCount(List);         /* ��� �� ���� */
    for ( i = 0; i<Count; i++ )
    {
        Current = SLL_GetNodeAt(List, i);       /* ��� Ž�� */
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ����Ʈ�� ����° ��� �ڿ� �� ��� ���� */
    printf("\nInserting 3000 After [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode  = SLL_CreateNode(3000);
        /* List -> [-2] -> [-1] -> [0] -> [3000] -> [1] -> [2] -> [3] -> [4] -> NULL */

    SLL_InsertAfter(Current, NewNode);

    /*  ����Ʈ ��� */
    Count = SLL_GetNodeCount(List);
    for ( i = 0; i<Count; i++ )
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ��� ��带 �޸𸮿��� ����     */
    printf("\nDestroying List...\n");

    for ( i = 0; i<Count; i++ )
    {
        Current = SLL_GetNodeAt(List, 0);       /* ù ��° ��� */

        if ( Current != NULL ) 
        {
            SLL_RemoveNode(&List, Current);     /* ��� ���� */
            SLL_DestroyNode(Current);           /* ��� �Ҹ� (�Ҵ� �޸� ����) */
        }
    }

    return 0;
}
