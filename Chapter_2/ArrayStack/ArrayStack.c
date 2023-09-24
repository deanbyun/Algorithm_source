#include "ArrayStack.h"

void  AS_CreateStack(ArrayStack** Stack, int Capacity)
{
    /*  ������ ��������ҿ� ���� (���� �Ҵ�) */
    (*Stack)           = (ArrayStack*)malloc(sizeof(ArrayStack));

    /*  �Էµ� Capacity��ŭ�� ���(������)�� ��������ҿ� ���� */
    (*Stack)->Nodes    = (Node*)malloc(sizeof(Node)*Capacity);  /* Stack�� ����Ű�� ����� Nodes �����  */

    /*  Capacity �� Top �ʱ�ȭ */
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack)
{
    /*  ��带 ���� ����ҿ��� ���� */
    free(Stack->Nodes);

    /*  ������ ���� ����ҿ��� ���� */
    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)       /*���ο� ������ �߰�*/
{
    int Position = Stack->Top;      /*������ top �� ��ġ�� ����*/

    Stack->Nodes[Position].Data = Data;     /*���ο� �����͸� �ش� ���� ��ġ�� �Ҵ�*/   /*�迭 ??*/
    Stack->Top++;                           /*������ top ��ġ ����*/
}

ElementType AS_Pop(ArrayStack* Stack)
{
    int Position = --( Stack->Top );        /* top ��ġ�� �������� ��ġ�� ����*/

    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)   /*top��� ��ȯ*/
{
    int Position = Stack->Top - 1;      /*�� �� ����� �ٷ� �Ʒ��� �ִ� ����� ��ġ�� ����*/

    return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack)       /* ���� ũ�� Ȯ�� */
{
    return Stack->Top;                  /*�� �� ����� �ε��� = ������ ũ�� �� ��ȯ*/
}

int AS_IsEmpty(ArrayStack* Stack)       /* ���� ����ִ��� Ȯ��*/
{
    return (Stack->Top == 0);           /*���� ũ�� = 0 �̸� (���������) 1 ��ȯ*/
}