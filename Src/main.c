# pragma warning(disable : 4996)
#include"manage.h"



int main()
{
    node* a = (node*)malloc(sizeof(node) * 1001);
    init(a);
    Read(a);
    int flag;

    while (true) {

        // 显示菜单
        showMenu();
        printf("选择你要进行的操作：");
        scanf("%d", &flag);

        switch (flag)
        {
        case 0:         //异常退出
            errorChoice();
        case 1:         // 1.显示教职工信息
            showAllMessage(a);
            break;
        case 2:         // 2.增加教职工信息
            addMessage(a);
            break;
        case 3:         // 3.删除教职工信息
            deleteMessage(a);
            break;
        case 4:         // 4.查找教职工信息
            findMessage(a);
            break;
        case 5:         // 5.修改教职工信息
            modMessage(a);
            break;
        case 6:         // 6.排序
            sortMessage(a);
            break;
        case 7:         // 7.退出系统
            exitSystem();
            break;
        default:
        {
            printf("输入错误，请重新输入\n");
            system("cls");
            break;
        }
        }
    }
    return 0;
}