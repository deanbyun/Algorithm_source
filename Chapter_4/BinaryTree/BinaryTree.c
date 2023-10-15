#include "BinaryTree.h"

SBTNode* SBT_CreateNode( ElementType NewData )      /* 노드 생성 */
{
    SBTNode* NewNode = (SBTNode*)malloc( sizeof(SBTNode) );     /* 노드 메모리 할당 */
    NewNode->Left    = NULL;
    NewNode->Right   = NULL;
    NewNode->Data    = NewData;

    return NewNode;
}

void SBT_DestroyNode( SBTNode* Node )       /* 노드 메모리 해제 */
{
    free(Node);
}

void SBT_DestroyTree( SBTNode* Node )       /* 트리 소멸 */
{
    if ( Node == NULL )
        return;

    /*  왼쪽 하위 트리 소멸 */
    SBT_DestroyTree( Node->Left );

    /*  오른쪽 하위 트리 소멸 */
    SBT_DestroyTree( Node->Right );

    /*  루트 노드 소멸 */
    SBT_DestroyNode( Node );
}

void SBT_PreorderPrintTree( SBTNode* Node )     /* 전위 순회 */ 
/* 루트노드 -> 왼쪽 서브티리 -> 오른쪽 서브트리 */
{
    if ( Node == NULL )
        return;

    /*  루트 노드 출력 */
    printf( " %c", Node->Data );

    /*  왼쪽 하위 트리 출력 */
    SBT_PreorderPrintTree( Node->Left );

    /*  오른쪽 하위 트리 출력 */
    SBT_PreorderPrintTree( Node->Right );
}

void SBT_InorderPrintTree( SBTNode* Node )      /* 중위 순회 */
/* 왼쪽 서브티리 -> 루트 노트 -> 오른쪽 서브트리 */
{
    if ( Node == NULL )
        return;
    
    /*  왼쪽 하위 트리 출력 */
    SBT_InorderPrintTree( Node->Left );

    /*  루트 노드 출력 */
    printf( " %c", Node->Data );
    
    /*  오른쪽 하위 트리 출력 */
    SBT_InorderPrintTree( Node->Right );
}

void SBT_PostorderPrintTree( SBTNode* Node )        /* 후위 순회 */
/* 왼쪽 서브티리 -> 오른쪽 서브트리 -> 루트노드 */
{
    if ( Node == NULL )
        return;
    
    /*  왼쪽 하위 트리 출력 */
    SBT_PostorderPrintTree( Node->Left );

    /*  오른쪽 하위 트리 출력 */
    SBT_PostorderPrintTree( Node->Right );

    /*  루트 노드 출력 */
    printf( " %c", Node->Data );
}