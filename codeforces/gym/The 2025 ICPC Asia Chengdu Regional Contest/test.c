#include <stdio.h>
#include <limits.h>

int func(int x) {
    int y = x + 1;
    return y > x;
}

int main()
{
    printf("%d\n", func(INT_MAX));

    return 0;
}
