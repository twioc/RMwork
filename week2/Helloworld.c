#include <stdio.h>

int main(){
    int userinput = 0;
    while (1)
    {
        scanf("%d",&userinput);
        //对用户的输入进行检测
        switch (userinput)
        {
        case 1:
            printf("HELLOWORLD\n");//输出大写
            break;
        case 0:
            printf("helloworld\n");//输出小写
            break;
        case -1:
            return 0;//退出程序
        default:
            break;
        }
        
    }
    
}