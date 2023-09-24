#include "ArrayStack.h"

void  AS_CreateStack(ArrayStack** Stack, int Capacity)
{
    /*  스택을 자유저장소에 생성 (스택 할당) */
    (*Stack)           = (ArrayStack*)malloc(sizeof(ArrayStack));

    /*  입력된 Capacity만큼의 노드(데이터)를 자유저장소에 생성 */
    (*Stack)->Nodes    = (Node*)malloc(sizeof(Node)*Capacity);  /* Stack이 가리키는 대상의 Nodes 멤버에  */

    /*  Capacity 및 Top 초기화 */
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack)
{
    /*  노드를 자유 저장소에서 해제 */
    free(Stack->Nodes);

    /*  스택을 자유 저장소에서 해제 */
    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)       /*새로운 데이터 추가*/
{
    int Position = Stack->Top;      /*스택의 top 의 위치를 저장*/

    Stack->Nodes[Position].Data = Data;     /*새로운 데이터를 해당 스택 위치에 할당*/   /*배열 ??*/
    Stack->Top++;                           /*스택의 top 위치 증가*/
}

ElementType AS_Pop(ArrayStack* Stack)
{
    int Position = --( Stack->Top );        /* top 위치를 가져오고 위치를 감소*/

    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)   /*top요소 반환*/
{
    int Position = Stack->Top - 1;      /*맨 위 요소의 바로 아래에 있는 요소의 위치가 저장*/

    return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack)       /* 스택 크기 확인 */
{
    return Stack->Top;                  /*맨 위 요소의 인덱스 = 스택의 크기 를 반환*/
}

int AS_IsEmpty(ArrayStack* Stack)       /* 스택 비어있는지 확인*/
{
    return (Stack->Top == 0);           /*스택 크기 = 0 이면 (비어있으면) 1 반환*/
}