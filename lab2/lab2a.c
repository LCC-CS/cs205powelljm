#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argv[1][0] >= 'A' && argv[1][0] <= 'Z') goto is_upper;
    goto not_upper;

is_upper:
    printf("Uppercase\n");
    goto end;

not_upper:
    printf("Not Uppercase\n");

end:
    return 0;
}


