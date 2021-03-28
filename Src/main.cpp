#include "manage.h"
#include "tool.h"

int main()
{
    Manage manage_;
    manage_.showMenu();
    printf("%*c", 30, 0);
    printf("**********************(输入序号选择操作)************************\n");
    int flag;
    while (true)
    {

        printf("选择你要进行的操作：");
        scanf_s("%s", &flag);

        //if (!Tool::isInt())
        //    break;
        //std::cout << "请输入您的选择" << std::endl;
        //std::cin >> flag;

        //std::cout << "flag = " << flag << std::endl;
        //std::cout << "type(flag) = " << typeid(flag).name() << std::endl;

        //if (!std::cin)
        //{
        //    std::cin.clear();
        //    std::cin.get();
        //}
        //if (sizeof(flag) != sizeof(int))
        //    break;

        switch (flag)
        {
        case 0:
            manage_.errorChoice(flag);
            break;
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
