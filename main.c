#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE  10
#define OVERFLOW    0
#define ERROR       0
#define OK          1
#define INCREMENT   5
typedef int Status;

typedef struct LNode
{
    int data;
    struct LNode* next;
}Node, * Linklist;

//����һ��������
Status Create_Node(void)
{
    Linklist node;
    node = (Linklist)malloc(sizeof(Node));
    if (!node)
        return ERROR;
    return OK;
}

//ȡ����i��Ԫ�أ����ظ�e
Status GetElem(Linklist L, int i, int* e)
{
    Linklist p = L->next;
    int j = 1;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

//��ӡ��������ֵ
Status Print_Linklist(Linklist L)
{
    Linklist p = L;
    while (p->next)
    {
        printf("%d  ", p->next->data);
        p = p->next;
    }
    return OK;
}

//������ĵ�i��λ��֮ǰ����Ԫ��
Status Insert_linklist(Linklist L, int position, int datum)
{
    Linklist p = L;
    int cnt = 0;
    while (p && cnt < position - 1)
    {
        p = p->next;
        cnt++;
    }
    if (!p || cnt > position)
        return ERROR;
    Linklist newl = (Linklist)malloc(sizeof(Node));
    newl->data = datum;
    newl->next = p->next;
    p->next = newl;
}

//ɾ���ڵ�i��λ�õ�Ԫ��
Status Delete_linklist(Linklist L, int position)
{
    Linklist p = L;
    int cnt = 0;
    while (p && cnt < position - 1)
    {
        p = p->next;
        cnt++;
    }
    if (!p || cnt > position)
        return ERROR;
    Linklist q = p->next;
    p->next = p->next->next;
    free(q);
    return OK;
}

//��������
Status Reverse_Linklist(Linklist L)
{
    Linklist head = L->next;
    Linklist next = head->next;
    Linklist prev = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    L->next = prev;
    return OK;
}

//��������
Status Create_Linklist(Linklist* pHead)
{
    Linklist p = (Linklist)malloc(sizeof(Node));
    scanf("%d", &p->data);
    p->next = NULL;
    (*pHead)->next = p;
    (*pHead) = p;
    return OK;
}

//��չ�⣺���쵥������Ԫ������Ϊ����������0������0���ŵ�������
Status Input_Linklist(Linklist L, Linklist* pHead)
{
    int num;
    do
    {
        scanf("%d", &num);
        if (num == 0)
            break;
        Linklist p = (Linklist)malloc(sizeof(Node));
        p->data = num;
        p->next = NULL;
        (*pHead)->next = p;
        (*pHead) = p;

    } while (num != 0);
    return OK;
}
//��չ�⣺�Ӽ�����������һ���������ڵ������в�ѯ������
//������������Ѿ�������������͵���ɾ��������
//ɾ����Ԫ�����ڽ�㣬������������ɾ��ǰ�������Ԫ�������������Ļ��
//����������в�������������͵��ò��뺯����
//����������뵽������β�������������ڲ���ǰ�������Ԫ�������������Ļ��
Status Search_Linklist(Linklist L, int number)
{
    Linklist p = L;
    int found = 0;
    while (p->next)
    {
        if (p->next)
        {
            if (p->next->data == number)
            {
                Linklist q = p->next;
                p->next = q->next;
                free(q);
                found = 1;
            }
        }
        if (p->next == NULL)
        {
            break;
        }
        if (p->next->data != number)
        {
            p = p->next;
        }
    }
    if (p->next == NULL)
    {
        if (p->data == number)
        {
            found = 1;
            free(p);
        }
    }
    if (found == 1)//�ҵ���
    {
        Print_Linklist(L);
        printf("\n");
    }
    if (found == 0)//û�ҵ�
    {
        Linklist last = (Linklist)malloc(sizeof(Node));
        last->next = NULL;
        last->data = number;
        p->next = last;
        Print_Linklist(L);
        printf("\n");
    }
    return OK;
}

//��չ�⣺��һ������Ԫ�ز�������˳����У������ά��ԭ��˳��
Status Ordered_Insertion(Linklist L, int datum)
{
    int Order;
    Linklist p = L->next;
    Linklist last = L;
    while (last->next)
        last = last->next;

    if (p->data > p->next->data)//����
        Order = 0;
    if (p->data < p->next->data)//����
        Order = 1;
    if ((Order == 0 && datum > p->data) || (Order == 1 && datum < p->data))//Ӧ���ڶ���
    {
        Linklist q = (Linklist)malloc(sizeof(Node));
        q->next = p;
        q->data = datum;
        L->next = q;
    }
    else if ((Order == 0 && datum < last->data) || (Order == 1 && datum > last->data))//Ӧ���ڶ�β
    {
        Linklist q = (Linklist)malloc(sizeof(Node));
        q->next = NULL;
        q->data = datum;
        last->next = q;
    }
    else if (Order == 0)//����
    {
        while (!(p->data >= datum && p->next->data < datum))
        {
            p = p->next;
        }
        Linklist q = (Linklist)malloc(sizeof(Node));
        q->next = p->next;
        q->data = datum;
        p->next = q;
    }
    else if (Order == 1)//����
    {
        while (!(p->data <= datum && p->next->data > datum))
        {
            p = p->next;
        }
        Linklist q = (Linklist)malloc(sizeof(Node));
        q->next = p->next;
        q->data = datum;
        p->next = q;
    }
    return OK;
}
//��չ�⣺ɾ����������ȫ���ĸ���
Status Delete_NegativeNumbers(Linklist L)
{
    Linklist p = L;
    while (p->next)
    {

        if (p->next->data < 0)
        {
            Linklist q = p->next;
            p->next = q->next;
            free(q);
        }
        if (p->next == NULL)
        {
            break;
        }
        if (p->next->data >= 0)
        {
            p = p->next;
        }
    }
    if (p->next == NULL && p->data < 0)
    {
        free(p);
    }
    return OK;
}
//��չ�⣺����һ��˫����������ð�������˼·�����˫�������������
//��ӡ��������ע�⣬���㷨�ڽ���Ԫ��ʱ�ǽ������������������ǽ������е�Ԫ��ֵ����
Status Bubble()


int main()
{
    Linklist head = (Linklist)malloc(sizeof(Node));
    head->next = NULL;
    Linklist p;
    p = head;
    //ͷ���ĳ�ʼ��
    int n;


    printf("Please input the length of the linklist:\n");
    Input_Linklist(head, &p);
    printf("Here is the data of your linklist:\n");
    Print_Linklist(head);
    printf("\n");
    /*    printf("Here is the data after deletion:\n");
        Delete_NegativeNumbers(head);
        Print_Linklist(head);
        printf("\n");
    */
    /*
        printf("Please input the length of the linklist:\n");
        scanf("%d",&n);
        printf("Now please input all the data:\n");
        for(int j=0;j<n;j++)
        {
            Create_Linklist(&p);
        }
        printf("Here is the data of your linklist:\n");
        Print_Linklist(head);
        printf("\n");
    */

    /*
        printf("Please input the number:\n");
        int number;
        scanf("%d",&number);
        Search_Linklist(head,number);
    */

    /*    printf("Please input your number in the ordered linklist:");
        int num;
        scanf("%d",&num);
        Ordered_Insertion(head,num);
        Print_Linklist(head);
        printf("\n");
    */
    /*    printf("Please input the data and the position you want to insert:(position first)\n");
        int position,datum;
        scanf("%d %d",&position,&datum);
        Insert_linklist(head,position,datum);
        printf("Here is your linklist after insertion:\n");
        Print_Linklist(head);
        printf("\n");
        printf("Please input the position you want to delete:\n");
        scanf("%d",&position);
        Delete_linklist(head,position);
        printf("Here is your linklist after deletion:\n");
        Print_Linklist(head);
        printf("\n");
    */
    return 0;
}

/*    int length;
    scanf("%d",&length);
    for(int i=0;i<length;i++)
    {
        Linklist q=(Linklist)malloc(sizeof(Node));
        scanf("%d",&q->data);
        p->next=q;
        q->next=NULL;
        p=q;
    }
*/


/*
    do
    {
        scanf("%d",&num);
        if(num==-1)
            break;
        Create_Linklist(&head);
    }while(num!=-1);

*/
