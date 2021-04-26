#include "utils.h"

void        report_error(int err_num)
{
    if (err_num == 1)
        printf("vector input ERROR\n");
    else if (err_num == 2)
        printf("R,G,B input ERROR\n");
    else if (err_num == 3)
        printf("angle input ERROR\n");
    else if (err_num == 4)
        printf("light input ERROR\n");
    else if (err_num == 5)
        printf("Unallowed Negative Value ERROR\n");
    else if (err_num == 6)
        printf("argv input ERROR\n");
    exit(err_num);
}