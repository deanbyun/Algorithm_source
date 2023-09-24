#include "ArrayStack.h"

int main( void )
{
    int i= 0;
    ArrayStack* Stack = NULL;       /*스택 배열 초기화*/

    AS_CreateStack(&Stack, 10);     /*스택 데이터 10개 할당 (생성)*/
    
    /*스택에 데이터 추가*/
    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    AS_Push(Stack, 12);

    printf( "Capacity: %d, Size: %d, Top: %d\n\n",      /*데이터 총량, 스택 크기, 스택 가장 위 데이터*/
        Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack) );

    for ( i=0; i<4; i++ )
    {
        if ( AS_IsEmpty(Stack) )        /*스택 비어있으면 break*/
            break;
        
        printf( "Popped: %d, ", AS_Pop(Stack) );        /*스택 데이터 제거 및 반환*/
        
        if ( ! AS_IsEmpty(Stack) )
            printf( "Current Top: %d\n", AS_Top(Stack) );       /*현재 스택의 top 요소 출력*/
        else
            printf( "Stack Is Empty.\n" );
    }

    AS_DestroyStack(Stack);     /*스택 메모리 해제*/

    return 0;
}