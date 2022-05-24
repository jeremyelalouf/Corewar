/*
** EPITECH PROJECT, 2022
** partie_asm_main
** File description:
** handle_option
*/

#include "my.h"
#include "virtual_machine.h"
#include "check_options.h"

int handle_dump_opt(struct vm_i *vm_inf, char *av[], int i,
    UNUSED struct opt_value *tmp)
{
    if (vm_inf->dump != -1)
        return ERR;
    vm_inf->dump = my_getnbr(av[i + 1]);
    return SUCC;
}

int handle_a_opt(struct vm_i *vm_inf, char *av[], int i,
    struct opt_value *tmp)
{
    if (my_str_isnum(av[i + 1]) == FALSE)
        return ERR;
    tmp->next_champion_address = my_getnbr(av[i + 1]);
    return SUCC;
}

int handle_n_opt(struct vm_i *vm_inf, char *av[], int i,
    struct opt_value *tmp)
{
    if (my_str_isnum(av[i + 1]) == FALSE)
        return ERR;
    tmp->next_champion_nbr = my_getnbr(av[i + 1]);
    return SUCC;
}

int handle_option(struct vm_i *vm_inf, char *av[], int *i,
    struct opt_value *tmp)
{
    int return_value = -1;

    for (int count = 0; count != SIZEOF(OPT_TAB); ++count) {
        if (my_strcmp(av[*i], OPT_TAB[count].instruction) == 0) {
            return_value = OPT_TAB[count].function(vm_inf, av, *i, tmp);
            if (return_value == SUCC)
                *i += 2;
        }
    }
    return return_value;
}
