#include "LinkedList.h"

int main( void )
{
    int   i       = 0;
    int   Count   = 0;
    Node* List    = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    /*  노드 5개 추가 */        

    for ( i = 0; i<5; i++ )
    {
        NewNode = SLL_CreateNode(i);        /* 노드 생성 */
        SLL_AppendNode(&List, NewNode);     /* 노드 추가 */
    }
    /* List -> [0] -> [1] -> [2] -> [3] -> [4] -> NULL */

    NewNode = SLL_CreateNode(-1);           
    SLL_InsertNewHead(&List, NewNode);      /* 노드 삽입 */

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);
    /* List -> [-2] -> [-1] -> [0] -> [1] -> [2] -> [3] -> [4] -> NULL */

    /*  리스트 출력 */
    Count = SLL_GetNodeCount(List);         /* 노드 수 세기 */
    for ( i = 0; i<Count; i++ )
    {
        Current = SLL_GetNodeAt(List, i);       /* 노드 탐색 */
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  리스트의 세번째 노드 뒤에 새 노드 삽입 */
    printf("\nInserting 3000 After [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode  = SLL_CreateNode(3000);
        /* List -> [-2] -> [-1] -> [0] -> [3000] -> [1] -> [2] -> [3] -> [4] -> NULL */

    SLL_InsertAfter(Current, NewNode);

    /*  리스트 출력 */
    Count = SLL_GetNodeCount(List);
    for ( i = 0; i<Count; i++ )
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  모든 노드를 메모리에서 제거     */
    printf("\nDestroying List...\n");

    for ( i = 0; i<Count; i++ )
    {
        Current = SLL_GetNodeAt(List, 0);       /* 첫 번째 노드 */

        if ( Current != NULL ) 
        {
            SLL_RemoveNode(&List, Current);     /* 노드 제거 */
            SLL_DestroyNode(Current);           /* 노드 소멸 (할당 메모리 해제) */
        }
    }

    return 0;
}
