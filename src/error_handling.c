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
        printf("not RT file (File must be formatted by '.rt')\n");
    else if (err_num == 7)
        printf("no necessary input in .rt file\n");
    else if (err_num == 8)
        printf(".rt file Line ERROR\n");
    else if (err_num == 9)
        printf("File dose not exist in ./scene");
    exit(err_num);
}
