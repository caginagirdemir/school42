#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = -1;
    if(argc == 1)
        return(printf("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"));
    while(++i < argc)
    {
        j = -1;
        while(++j <= (int)std::strlen(argv[i]))
             std::printf("%c", (char)std::toupper(argv[i][j]));
        printf(" ");
    }
    printf("\n");
    return(0);
}