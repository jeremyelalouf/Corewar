/*
** EPITECH PROJECT, 2022
** partie_asm_main
** File description:
** check_options
*/

#ifndef CHECK_OPTIONS_H_
    #define CHECK_OPTIONS_H_

struct opt_value {
    int next_champion_nbr;
    int next_champion_address;
};

typedef int check_opt_t(struct vm_i *vm_inf, char *av[], int i,
    struct opt_value *tmp);

struct check_opt_tab {
    char *instruction;
    check_opt_t *function;
};

check_opt_t handle_dump_opt;

check_opt_t handle_a_opt;

check_opt_t handle_n_opt;

static const struct check_opt_tab OPT_TAB[] = {
    {.instruction = "-dump", handle_dump_opt},
    {.instruction = "-a", handle_a_opt},
    {.instruction = "-n", handle_n_opt},
};

int handle_option(struct vm_i *vm_inf, char *av[], int *i,
    struct opt_value *tmp);

#endif /* !CHECK_OPTIONS_H_ */
