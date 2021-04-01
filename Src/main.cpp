#include "manage.h"
#include "tool.h"

int main()
{
    Manage manage_;
    
    while (true)
    {
        // 显示菜单
        manage_.showMenu();

        int flag = 0;
        printf("选择你要进行的操作：");
        scanf_s("%d", &flag);

        switch (flag)
        {
        case 0:
            manage_.errorChoice();
        case 1:
            manage_.showAllMessage();
            break;
        case 2:
            manage_.addMessage();
            break;
        case 3:
            manage_.deleteMessage();
            break;
        case 4:
            manage_.findMessage();
            break;
        case 5:
            manage_.modMessage();
            break;
        case 6:
            manage_.clearMessage();
            break;
        case 7:
            manage_.exitSystem();
            break;
        default:
            printf("输入错误，请重新输入\n");
            system("cls");
            break;
        }
    }
}
