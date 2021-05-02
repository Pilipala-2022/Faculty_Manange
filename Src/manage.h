#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

# define FILENAME "manageFile.txt"


typedef struct Teacher
{
    char name[20];     //姓名
    char sex[20];     //性别
    char birthday[20];  //出生年月
    char workData[20]; //工作年月
    char qualification[20];    //学历
    char duty[20];     //职务
    char address[20];    //住址
    char phone[20];    //电话
    char message[20];   //科研信息
} Teacher;


typedef struct List
{
    Teacher s[1001];
    int k;
} node;


//void showMenu();                     // 显示界面
void exitSystem();                   // 退出管理系统
//void init(node* a);                  // 顺序表初始化
void saveInfo(node* a);                  //信息导出
//void findMessage(node* a);                  // 信息查询
//void modMessage(node* a);                // 修改信息
//void deleteMessage(node* a);                // 删除信息
//void showAllMessage(node* a);                 // 信息浏览
//void addMessage(node* a);                 // 录入信息
//void readData(node* a);                   //从文件读取信息
void sortMessage(node* a);

void init(node* a)    //顺序表初始化
{
    a->k = 0;
}

void showMenu()//1.主界面
{   

    // 显示菜单
    printf("%*c", 30, 0);
    printf("************************************************************\n");
    printf("%*c", 30, 0);
    printf("************************************************************\n");
    printf("%*c", 30, 0);
    printf("**********************教职工管理系统************************\n");
    printf("%*c", 30, 0);
    printf("**********************1.显示教职工信息**********************\n");
    printf("%*c", 30, 0);
    printf("**********************2.增加教职工信息**********************\n");
    printf("%*c", 30, 0);
    printf("**********************3.删除教职工信息**********************\n");
    printf("%*c", 30, 0);
    printf("**********************4.查找教职工信息**********************\n");
    printf("%*c", 30, 0);
    printf("**********************5.修改教职工信息**********************\n");
    printf("%*c", 30, 0);
    printf("**********************6.排序********************************\n");
    printf("%*c", 30, 0);
    printf("**********************7.退出系统****************************\n");
    printf("%*c", 30, 0);
    printf("************************************************************\n\n\n");
    printf("%*c", 30, 0);
    printf("**********************(输入序号选择操作)************************\n");

}

void addMessage(node* a)//2.录入信息
{
    int id;
    FILE* fp = fopen(FILENAME, "a");
    if (fp == NULL)
    {
        printf("打开文件失败！");
        exit(-1);
    }
    while (1)
    {
        system("cls");
        printf("1:录入信息;\t2:结束录入信息\n");
        scanf("%d", &id);
        if (id == 2)
        {
            system("cls");
            return;
        }
        else if (id != 1)
        {
            printf("你输入的命令错误,请重新输入\n");
            continue;
        }
        if (a->k == 1001)
        {
            printf("超过单次录入次数，请重启系统输入信息\n");
            exitSystem(a);
        }

        //输入信息
        printf("请输入姓名:");
        scanf("%s", a->s[++a->k].name);
        printf("请输入性别:");
        scanf("%s", a->s[a->k].sex);
        printf("请输入出生时间:");
        scanf("%s", a->s[a->k].birthday);
        printf("请输入工作时间:");
        scanf("%s", a->s[a->k].workData);
        printf("请输入学历:");
        scanf("%s", a->s[a->k].qualification);
        printf("请输入职务:");
        scanf("%s", a->s[a->k].duty);
        printf("请输入住址:");
        scanf("%s", a->s[a->k].address);
        printf("请输入电话:");
        scanf("%s", a->s[a->k].phone);
        printf("请输入科研成果:");
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
    //------------------------输出----------------------------
    for (i = 1; i <= a->k; i++)
    {
        printf("\n 姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
    }
    saveInfo(a);
    system("pause");
    system("cls");
}

void modMessage(node* a)//修改信息
{
    printf(" 信息查询\n");
    printf("1.姓名\n");
    printf("2.住址\n");
    printf("3.电话\n");

    printf("请输入选项：");
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
        printf("请输入你要修改的姓名:");
        scanf("%s", num);

        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].name, num);
            if (f == 0)
            {
                teacher[count] = i;
                printf("\n第%d位教师：姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", i, a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
                count++;
            }
        }

        printf("请输入要修改第几位教师：");
        scanf("%d", &m);
        i = teacher[m];
        printf("\n 姓名修改为:");
        scanf("%s", a->s[i].name);
        printf("\n 性别修改为:");
        scanf("%s", a->s[i].sex);
        printf("\n 出生时间修改为:");
        scanf("%s", a->s[i].birthday);
        printf("\n 工作时间修改为:");
        scanf("%s", a->s[i].workData);
        printf("\n 学历修改为:");
        scanf("%s", a->s[i].qualification);
        printf("\n 职务修改为:");
        scanf("%s", a->s[i].duty);
        printf("\n 住址修改为:");
        scanf("%s", a->s[i].address);
        printf("\n 电话修改为:");
        scanf("%s", a->s[i].phone);
        printf("\n\n\n\n\n\n\n修改后如下：\n");
        printf("\n姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);

    }
    else if (id == 2)
    {
        system("cls");
        int i, m;
        char num[20];
        printf("请输入你要修改的住址:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].address, num);
            if (f == 0)
            {
                printf("\n\n\n 该教师信息如下\n\n\n");

                printf("\n姓名:%s 性别:%s 出生时间:%d 工作时间:%d 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
                printf("\n 姓名修改为:");
                scanf("%s", a->s[i].name);
                printf("\n 性别修改为:");
                scanf("%s", a->s[i].sex);
                printf("\n 出生时间修改为:\n");
                scanf("%s", a->s[i].birthday);
                printf("\n 工作时间修改为:\n");
                scanf("%s", a->s[i].workData);
                printf("\n 学历修改为:\n");
                scanf("%s", a->s[i].qualification);
                printf("\n 职务修改为:\n");
                scanf("%s", a->s[i].duty);
                printf("\n 住址修改为:\n");
                scanf("%s", a->s[i].address);
                printf("\n 电话修改为:\n");
                scanf("%s", a->s[i].phone);
                printf("\n\n\n\n\n\n\n修改后如下：\n");
                printf("\n姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
            }
        }
    }
    else if (id == 3)
    {
        system("cls");
        int i, m;
        char num[20];
        printf("请输入你要修改的电话:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].phone, num);
            if (f == 0)
            {
                printf("\n\n\n 该教师信息如下\n\n\n");
                printf("\n姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
                printf("\n 姓名修改为:");
                scanf("%s", a->s[i].name);
                printf("\n 性别修改为:");
                scanf("%s", a->s[i].sex);
                printf("\n 出生时间修改为:\n");
                scanf("%s", a->s[i].birthday);
                printf("\n 工作时间修改为:\n");
                scanf("%s", a->s[i].workData);
                printf("\n 学历修改为:\n");
                scanf("%s", a->s[i].qualification);
                printf("\n 职务修改为:\n");
                scanf("%s", a->s[i].duty);
                printf("\n 住址修改为:\n");
                scanf("%s", a->s[i].address);
                printf("\n 电话修改为:\n");
                scanf("%s", a->s[i].phone);
                printf("\n\n\n\n\n\n\n修改后如下：\n");
                printf("\n姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
            }
        }
    }
    system("pause");
    system("cls");
}

void deleteMessage(node* a)//删除信息
{
    printf(" 信息查询\n");
    printf("1.姓名\n");
    printf("2.住址\n");
    printf("3.电话\n");

    printf("请输入选项：");
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
        printf("请输入你要删除的姓名:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {

            if (0 == strcmp(a->s[i].name, num))
            {
                printf("\n%d 姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", ++k, a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);

                d[k] = i;

            }
        }
        printf("请输入要删除的教职工序号");
        
        scanf("%d", &n);
        for (i = d[n]; i < a->k; i++)
        {
            a->s[i] = a->s[i + 1];
        }

        printf("\n\n删除成功!\n\n");
        a->k--;
    }
    else if (id == 2)
    {
        system("cls");
        int i, m, d[20], k = 0, n;
        char num[20];
        //toxy(48, 5);
        printf("请输入你要删除的住址:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {
            if (0 == strcmp(a->s[i].address, num))
            {
                printf("\n%d 姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", ++k, a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);

                d[k] = i;

            }
        }
        printf("请输入要删除的教职工序号");
        scanf("%d", &n);
        for (i = d[n]; i < a->k; i++)
        {
            a->s[i] = a->s[i + 1];
        }

        printf("\n\n删除成功!\n\n");
        a->k--;


    }
    else if (id == 3)
    {
        system("cls");
        int i, m, d[20], k = 0, n;
        char num[20];
        //toxy(48, 5);
        printf("请输入你要删除的电话:");
        scanf("%s", num);
        for (i = 1; i <= a->k; i++)
        {
            if (0 == strcmp(a->s[i].phone, num))
            {
                printf("\n%d 姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", ++k, a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);

                d[k] = i;
            }


        }
        printf("请输入要删除的教职工序号\n");
        scanf("%d", &n);
        for (i = d[n]; i < a->k; i++)
        {
            a->s[i] = a->s[i + 1];
        }

        printf("\n\n删除成功!\n\n");
        a->k--;
    }

    system("pause");
    system("cls");

}

void findMessage(node* a)//4. 信息查询
{

    printf(" 信息查询(按下列序号选择查询的途径)\n");
    printf("1.姓名\n");
    printf("2.住址\n");
    printf("3.电话\n");
    printf("4.科研结果\n");
    printf("请输入选项：");
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
        printf("请输入你要查找的姓名:");
        scanf("%s", da);
        //输出
        int i, j = 0;
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].name, da);
            if (f == 0) {
                printf("\n姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
                j++;
            }
        }
        if (j == 0)
            printf("查无此人\n");
    }
    else if (id == 2)
    {
        system("cls");
        printf("请输入你要查找的住址:");
        scanf("%s", da);
        //输出
        int i, j = 0;
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].address, da);
            if (f == 0)
                printf("\n姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
        if (j == 0)
            printf("查无此人\n");

    }


    else if (id == 3)
    {
        system("cls");
        printf("请输入你要查找的电话:");
        scanf("%s", da);
        //输出
        int i, j = 0;
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].phone, da);
            if (f == 0)
                printf("\n姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
        if (j == 0)
            printf("查无此人\n");

    }
    else if (id == 4)
    {
        system("cls");
        printf("请输入你要查找的科研成果:");
        scanf("%s", da);
        //输出
        int i, j = 0;
        for (i = 1; i <= a->k; i++)
        {
            int f = strcmp(a->s[i].message, da);
            if (f == 0)
                printf("\n姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
        if (j == 0)
            printf("查无此人\n");

    }
    system("pause");
    system("cls");
}

void saveInfo(node* a)//5. 信息导出
{
    

    FILE* fp = fopen(FILENAME, "w");
    //char ch[] = "\n\r";
    if (fp == NULL)
    {
        printf("打开文件失败！");
        exit(-1);
    }
    int i;
    //--------------------------------输出到文件-----------------------------------
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
        printf("打开文件失败！");
        system("cls");
        return;
    }
    while (fread(&(a->s[++(a->k)]), sizeof(Teacher), 1, fp));
    a->k--;
    fclose(fp);

}

void exitSystem()       //退出软件
{
    system("pause");
    exit(0); // 退出程序
}

void errorChoice()
{
    printf("错误输入\n");
    exitSystem();
}

void sortMessage(node* a) {
    int choise, i, j;
    printf("请选择需要按哪种信息排序\n");
    printf("1.出生年月\n");
    printf("2.工作年月\n");
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
            printf("\n 姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
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
            printf("\n 姓名:%s 性别:%s 出生时间:%s 工作时间:%s 学历:%s 职务:%s 住址:%s 电话:%s  科研成果:%s\n", a->s[i].name, a->s[i].sex, a->s[i].birthday, a->s[i].workData, a->s[i].qualification, a->s[i].duty, a->s[i].address, a->s[i].phone, a->s[i].message);
        }
    }

    else
        printf("错误输入\n");

    system("pause");
    system("cls");
}
