#include <stdio.h>

int main() {
    int i, sum = 0;
    
    i = 1;
loop_start:
    if (i >= 10) goto loop_end;
    sum += i;
    i++;
    goto loop_start;
loop_end:
    
    printf("Sum = %d\n", sum);
    return 0;
}
