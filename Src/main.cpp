#include"manage.h"


extern void showMenu();
extern void errorChoice();
extern void showAllMessage();
extern void addMessage();
extern void deleteMessage();
extern void findMessage();
extern void modMessage();
extern void clearMessage();
extern void exitSystem();
extern void saveInfo();
extern int inSearch();
extern void readData();

int main()
{
    //读取文件中的信息
    readData();
    while (true)
    {
        // 显示菜单
        showMenu();

        int flag = 0;
        printf("选择你要进行的操作：");
        scanf_s("%d", &flag);

        switch (flag)
        {
        case 0:     //异常退出
            errorChoice();
        case 1:     //显示所有信息
            showAllMessage();
            break;
        case 2:     //添加信息
            addMessage();
            break;
        case 3:     //删除
            deleteMessage();
            break;
        case 4:     //查找
            findMessage();
            break;
        case 5:     //修改
            modMessage();
            break;
        case 6:     //清空
            clearMessage();
            break;
        case 7:
            exitSystem();
            break;
        default:
            printf("输入错误，请重新输入\n");
            system("cls");
            break;
        }
    }
}
