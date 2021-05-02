#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

# define FILENAME "manageFile.txt"


typedef struct Teacher
{
    char name[20];     //����
    char sex[20];     //�Ա�
    char birthday[20];  //��������
    char workData[20]; //��������
    char qualification[20];    //ѧ��
    char duty[20];     //ְ��
    char address[20];    //סַ
    char phone[20];    //�绰
    char message[20];   //������Ϣ
} Teacher;


typedef struct List
{
    Teacher s[1001];
    int k;
} node;


//void showMenu();                     // ��ʾ����
void exitSystem();                   // �˳�����ϵͳ
//void init(node* a);                  // ˳����ʼ��
void saveInfo(node* a);                  //��Ϣ����
//void findMessage(node* a);                  // ��Ϣ��ѯ
//void modMessage(node* a);                // �޸���Ϣ
//void deleteMessage(node* a);                // ɾ����Ϣ
//void showAllMessage(node* a);                 // ��Ϣ���
//void addMessage(node* a);                 // ¼����Ϣ
//void readData(node* a);                   //���ļ���ȡ��Ϣ
void sortMessage(node* a);

void init(node* a)    //˳����ʼ��
{
    a->k = 0;
}

void showMenu()//1.������
{   

    // ��ʾ�˵�
    printf("%*c", 30, 0);
    printf("************************************************************\n");
    printf("%*c", 30, 0);
    printf("************************************************************\n");
    printf("%*c", 30, 0);
    printf("**********************��ְ������ϵͳ************************\n");
    printf("%*c", 30, 0);
    printf("**********************1.��ʾ��ְ����Ϣ**********************\n");
    printf("%*c", 30, 0);
    printf("**********************2.���ӽ�ְ����Ϣ**********************\n");
    printf("%*c", 30, 0);
    printf("**********************3.ɾ����ְ����Ϣ**********************\n");
    printf("%*c", 30, 0);
    printf("**********************4.���ҽ�ְ����Ϣ**********************\n");
    printf("%*c", 30, 0);
    printf("**********************5.�޸Ľ�ְ����Ϣ**********************\n");
    printf("%*c", 30, 0);
    printf("**********************6.����********************************\n");
    printf("%*c", 30, 0);
    printf("**********************7.�˳�ϵͳ****************************\n");
    printf("%*c", 30, 0);
    printf("************************************************************\n\n\n");
    printf("%*c", 30, 0);
    printf("**********************(�������ѡ�����)************************\n");

}

void addMessage(node* a)//2.¼����Ϣ
{
    int id;
    FILE* fp = fopen(FILENAME, "a");
    if (fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�");
        exit(-1);
    }
    while (1)
    {
        system("cls");
        printf("1:¼����Ϣ;\t2:����¼����Ϣ\n");
        scanf("%d", &id);
        if (id == 2)
        {
            system("cls");
            return;
        }
        else if (id != 1)
        {
            printf("��������������,����������\n");
            continue;
        }
        if (a->k == 1001)
        {
            printf("��������¼�������������ϵͳ������Ϣ\n");
            exitSystem(a);
        }

        //������Ϣ
        printf("����������:");
        scanf("%s", a->s[++a->k].name);
        printf("�������Ա�:");
        scanf("%s", a->s[a->k].sex);
        printf("���������ʱ��:");
        scanf("%s", a->s[a->k].birthday);
        printf("�����빤��ʱ��:");
        scanf("%s", a->s[a->k].workData);
        printf("������ѧ��:");
        scanf("%s", a->s[a->k].qualification);
        printf("������ְ��:");
        scanf("%s", a->s[a->k].duty);
        printf("������סַ:");
        scanf("%s", a->s[a->k].address);
        printf("������绰:");
        scanf("%s", a->s[a->k].phone);
        printf("��������гɹ�:");
        scanf("%s", a->s[a->k].message);
      
    }
    saveInfo(a);
    fclose(fp);

}

void showAllMessage(node* a)

{
    int i, j;
    for (i = 1; i <= a->k - 1; i++)
        for (j = 1; j <= a->k - 1; j++)
        {
            if (strcmp(a->s[j].name, a->s[j + 1].name) > 0)
            {
                Teacher temp = a->s[j];
                a->s[j] = a->s[j + 1];
                a->s[j + 1] = temp;
            }
        }
    //------------------------���----------------------------
    for (i = 1; i <= a->k; i++)
    {
        printf("\n ����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
    }
    saveInfo(a);
    system("pause");
    system("cls");
}

void modMessage(node* a)//�޸���Ϣ
{
    printf(" ��Ϣ��ѯ\n");
    printf("1.����\n");
    printf("2.סַ\n");
    printf("3.�绰\n");

    printf("������ѡ�");
    int id;
    while (scanf("%d", &id) != EOF)
    {
        if (id == 1 || id == 2 || id == 3)
            break;
    }
    if (id == 1)
    {
        system("cls");
        int i, m, count = 1, teacher[20];
        char num[20];
        printf("��������Ҫ�޸ĵ�����:");
        scanf("%s", num);

        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].name, num);
            if (f == 0)
            {
                teacher[count] = i;
                printf("\n��%dλ��ʦ������:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", i, a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
                count++;
            }
        }

        printf("������Ҫ�޸ĵڼ�λ��ʦ��");
        scanf("%d", &m);
        i = teacher[m];
        printf("\n �����޸�Ϊ:");
        scanf("%s", a->s[i].name);
        printf("\n �Ա��޸�Ϊ:");
        scanf("%s", a->s[i].sex);
        printf("\n ����ʱ���޸�Ϊ:");
        scanf("%s", a->s[i].birthday);
        printf("\n ����ʱ���޸�Ϊ:");
        scanf("%s", a->s[i].workData);
        printf("\n ѧ���޸�Ϊ:");
        scanf("%s", a->s[i].qualification);
        printf("\n ְ���޸�Ϊ:");
        scanf("%s", a->s[i].duty);
        printf("\n סַ�޸�Ϊ:");
        scanf("%s", a->s[i].address);
        printf("\n �绰�޸�Ϊ:");
        scanf("%s", a->s[i].phone);
        printf("\n\n\n\n\n\n\n�޸ĺ����£�\n");
        printf("\n����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);

    }
    else if (id == 2)
    {
        system("cls");
        int i, m;
        char num[20];
        printf("��������Ҫ�޸ĵ�סַ:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].address, num);
            if (f == 0)
            {
                printf("\n\n\n �ý�ʦ��Ϣ����\n\n\n");

                printf("\n����:%s �Ա�:%s ����ʱ��:%d ����ʱ��:%d ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
                printf("\n �����޸�Ϊ:");
                scanf("%s", a->s[i].name);
                printf("\n �Ա��޸�Ϊ:");
                scanf("%s", a->s[i].sex);
                printf("\n ����ʱ���޸�Ϊ:\n");
                scanf("%s", a->s[i].birthday);
                printf("\n ����ʱ���޸�Ϊ:\n");
                scanf("%s", a->s[i].workData);
                printf("\n ѧ���޸�Ϊ:\n");
                scanf("%s", a->s[i].qualification);
                printf("\n ְ���޸�Ϊ:\n");
                scanf("%s", a->s[i].duty);
                printf("\n סַ�޸�Ϊ:\n");
                scanf("%s", a->s[i].address);
                printf("\n �绰�޸�Ϊ:\n");
                scanf("%s", a->s[i].phone);
                printf("\n\n\n\n\n\n\n�޸ĺ����£�\n");
                printf("\n����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
            }
        }
    }
    else if (id == 3)
    {
        system("cls");
        int i, m;
        char num[20];
        printf("��������Ҫ�޸ĵĵ绰:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].phone, num);
            if (f == 0)
            {
                printf("\n\n\n �ý�ʦ��Ϣ����\n\n\n");
                printf("\n����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
                printf("\n �����޸�Ϊ:");
                scanf("%s", a->s[i].name);
                printf("\n �Ա��޸�Ϊ:");
                scanf("%s", a->s[i].sex);
                printf("\n ����ʱ���޸�Ϊ:\n");
                scanf("%s", a->s[i].birthday);
                printf("\n ����ʱ���޸�Ϊ:\n");
                scanf("%s", a->s[i].workData);
                printf("\n ѧ���޸�Ϊ:\n");
                scanf("%s", a->s[i].qualification);
                printf("\n ְ���޸�Ϊ:\n");
                scanf("%s", a->s[i].duty);
                printf("\n סַ�޸�Ϊ:\n");
                scanf("%s", a->s[i].address);
                printf("\n �绰�޸�Ϊ:\n");
                scanf("%s", a->s[i].phone);
                printf("\n\n\n\n\n\n\n�޸ĺ����£�\n");
                printf("\n����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
            }
        }
    }
    system("pause");
    system("cls");
}

void deleteMessage(node* a)//ɾ����Ϣ
{
    printf(" ��Ϣ��ѯ\n");
    printf("1.����\n");
    printf("2.סַ\n");
    printf("3.�绰\n");

    printf("������ѡ�");
    int id;
    while (scanf("%d", &id) != EOF)
    {
        if (id == 1 || id == 2 || id == 3)
            break;
    }
    if (id == 1)
    {
        system("cls");
        int i, m, d[20], k = 0, n;
        char num[20];
        //toxy(48, 5);
        printf("��������Ҫɾ��������:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {

            if (0 == strcmp(a->s[i].name, num))
            {
                printf("\n%d ����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", ++k, a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);

                d[k] = i;

            }
        }
        printf("������Ҫɾ���Ľ�ְ�����");
        
        scanf("%d", &n);
        for (i = d[n]; i < a->k; i++)
        {
            a->s[i] = a->s[i + 1];
        }

        printf("\n\nɾ���ɹ�!\n\n");
        a->k--;
    }
    else if (id == 2)
    {
        system("cls");
        int i, m, d[20], k = 0, n;
        char num[20];
        //toxy(48, 5);
        printf("��������Ҫɾ����סַ:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {
            if (0 == strcmp(a->s[i].address, num))
            {
                printf("\n%d ����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", ++k, a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);

                d[k] = i;

            }
        }
        printf("������Ҫɾ���Ľ�ְ�����");
        scanf("%d", &n);
        for (i = d[n]; i < a->k; i++)
        {
            a->s[i] = a->s[i + 1];
        }

        printf("\n\nɾ���ɹ�!\n\n");
        a->k--;


    }
    else if (id == 3)
    {
        system("cls");
        int i, m, d[20], k = 0, n;
        char num[20];
        //toxy(48, 5);
        printf("��������Ҫɾ���ĵ绰:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {
            if (0 == strcmp(a->s[i].phone, num))
            {
                printf("\n%d ����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", ++k, a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);

                d[k] = i;
            }


        }
        printf("������Ҫɾ���Ľ�ְ�����\n");
        scanf("%d", &n);
        for (i = d[n]; i < a->k; i++)
        {
            a->s[i] = a->s[i + 1];
        }

        printf("\n\nɾ���ɹ�!\n\n");
        a->k--;
    }

    system("pause");
    system("cls");

}

void findMessage(node* a)//4. ��Ϣ��ѯ
{

    printf(" ��Ϣ��ѯ(���������ѡ���ѯ��;��)\n");
    printf("1.����\n");
    printf("2.סַ\n");
    printf("3.�绰\n");
    printf("4.���н��\n");
    printf("������ѡ�");
    int id;
    while (scanf("%d", &id) != EOF)
    {
        if (id == 1 || id == 2 || id == 3 || id == 4)
            break;
    }
    char da[50];
    if (id == 1)
    {
        system("cls");
        //toxy(48, 5);
        printf("��������Ҫ���ҵ�����:");
        scanf("%s", da);
        //���
        int i, j = 0;
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].name, da);
            if (f == 0) {
                printf("\n����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
                j++;
            }
        }
        if (j == 0)
            printf("���޴���\n");
    }
    else if (id == 2)
    {
        system("cls");
        printf("��������Ҫ���ҵ�סַ:");
        scanf("%s", da);
        //���
        int i, j = 0;
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].address, da);
            if (f == 0)
                printf("\n����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
        if (j == 0)
            printf("���޴���\n");

    }


    else if (id == 3)
    {
        system("cls");
        printf("��������Ҫ���ҵĵ绰:");
        scanf("%s", da);
        //���
        int i, j = 0;
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].phone, da);
            if (f == 0)
                printf("\n����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
        if (j == 0)
            printf("���޴���\n");

    }
    else if (id == 4)
    {
        system("cls");
        printf("��������Ҫ���ҵĿ��гɹ�:");
        scanf("%s", da);
        //���
        int i, j = 0;
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].message, da);
            if (f == 0)
                printf("\n����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
        if (j == 0)
            printf("���޴���\n");

    }
    system("pause");
    system("cls");
}

void saveInfo(node* a)//5. ��Ϣ����
{
    

    FILE* fp = fopen(FILENAME, "w");
    //char ch[] = "\n\r";
    if (fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�");
        exit(-1);
    }
    int i;
    //--------------------------------������ļ�-----------------------------------
    for (i = 1; i <= a->k; i++)
    {
        fwrite(&(a->s[i]), sizeof(Teacher), 1, fp);
        //fwrite(ch, 2, 1, fp);
    }
    fclose(fp);

}

void Read(node* a)
{
    FILE* fp = fopen(FILENAME, "r");
    if (fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�");
        system("cls");
        return;
    }
    while (fread(&(a->s[++(a->k)]), sizeof(Teacher), 1, fp));
    a->k--;
    fclose(fp);

}

void exitSystem()       //�˳����
{
    system("pause");
    exit(0); // �˳�����
}

void errorChoice()
{
    printf("��������\n");
    exitSystem();
}

void sortMessage(node* a) {
    int choise, i, j;
    printf("��ѡ����Ҫ��������Ϣ����\n");
    printf("1.��������\n");
    printf("2.��������\n");
    scanf("%d", &choise);
    if (choise == 1) {
        for (i = 1; i <= a->k - 1; i++)
            for (j = 1; j <= a->k - 1; j++)
            {
                if (strcmp(a->s[j].birthday, a->s[j + 1].birthday) > 0)
                {
                    Teacher temp = a->s[j];
                    a->s[j] = a->s[j + 1];
                    a->s[j + 1] = temp;
                }
            }
        //saveInfo(a);
        for (i = 1; i <= a->k; i++)
        {
            printf("\n ����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
    }
    else if (choise == 2) {
        for (i = 1; i <= a->k - 1; i++)
            for (j = 1; j <= a->k - 1; j++)
            {
                if (strcmp(a->s[j].workData, a->s[j + 1].workData) > 0)
                {
                    Teacher temp = a->s[j];
                    a->s[j] = a->s[j + 1];
                    a->s[j + 1] = temp;
                }
            }
        //saveInfo(a);
        for (i = 1; i <= a->k; i++)
        {
            printf("\n ����:%s �Ա�:%s ����ʱ��:%s ����ʱ��:%s ѧ��:%s ְ��:%s סַ:%s �绰:%s  ���гɹ�:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
    }

    else
        printf("��������\n");

    system("pause");
    system("cls");
}
