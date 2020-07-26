#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *fp = fopen("../include/Screen.hpp","w");
    if(fp==NULL)
    {
        printf("fail open!\n");
        return 1;
    }
    else
    {
        printf("success!\n");
    }
    return 0;
}
