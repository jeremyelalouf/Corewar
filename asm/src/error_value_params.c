/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** function to check if the value of the param exceed the size of type
*/

#include "corewar.h"
#include "my.h"

static int is_param_four_bytes(char *param)
{
    int i = 0;

    if (my_strlen(param) > 11)
        return (FALSE);
    if (param[i] == '-' || param[i] == '+')
        ++i;
    if (my_strlen(&param[i]) < my_strlen(MAX_FOUR_BYTES_VAL))
        return (TRUE);
    while (i < my_strlen(param)) {
        if (param[i] < MAX_FOUR_BYTES_VAL[i] || (i == 10 && param[0] == '-' &&
            param[i] == '8'))
            return (TRUE);
        if (param[i] > MAX_FOUR_BYTES_VAL[i])
            return (FALSE);
        ++i;
    }
    return (TRUE);
}

static int is_param_two_bytes(char *param)
{
    int i = 0;

    if (my_strlen(param) > 6)
        return (FALSE);
    if (param[i] == '-' || param[i] == '+')
        ++i;
    if (my_strlen(&param[i]) < my_strlen(MAX_TWO_BYTES_VAL))
        return (TRUE);
    while (i < my_strlen(param)) {
        if (param[i] < MAX_TWO_BYTES_VAL[i] || (i == 5 && param[0] == '-' &&
            param[i] == '8'))
            return (TRUE);
        if (param[i] > MAX_TWO_BYTES_VAL[i])
            return (FALSE);
        ++i;
    }
    return (TRUE);
}

int is_size_param_valid(int type, char *param)
{
    if (type == T_DIR)
        return (is_param_four_bytes(&param[1]));
    return (is_param_two_bytes(param));
}
