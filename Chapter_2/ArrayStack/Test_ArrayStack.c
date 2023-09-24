#include "ArrayStack.h"

int main( void )
{
    int i= 0;
    ArrayStack* Stack = NULL;       /*���� �迭 �ʱ�ȭ*/

    AS_CreateStack(&Stack, 10);     /*���� ������ 10�� �Ҵ� (����)*/
    
    /*���ÿ� ������ �߰�*/
    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    AS_Push(Stack, 12);

    printf( "Capacity: %d, Size: %d, Top: %d\n\n",      /*������ �ѷ�, ���� ũ��, ���� ���� �� ������*/
        Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack) );

    for ( i=0; i<4; i++ )
    {
        if ( AS_IsEmpty(Stack) )        /*���� ��������� break*/
            break;
        
        printf( "Popped: %d, ", AS_Pop(Stack) );        /*���� ������ ���� �� ��ȯ*/
        
        if ( ! AS_IsEmpty(Stack) )
            printf( "Current Top: %d\n", AS_Top(Stack) );       /*���� ������ top ��� ���*/
        else
            printf( "Stack Is Empty.\n" );
    }

    AS_DestroyStack(Stack);     /*���� �޸� ����*/

    return 0;
}