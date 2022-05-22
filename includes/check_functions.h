/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** check_functions
*/

#ifndef CHECK_FUNCTIONS_H_
    #define CHECK_FUNCTIONS_H_

typedef int check_instruction_t(struct instruction *instruction,
    char **params, int fd);

typedef struct check_tab_s {
    char *instruction;
    check_instruction_t *function;
} check_tab_t;

check_instruction_t check_live;

check_instruction_t check_ld;

check_instruction_t check_st;

check_instruction_t check_add;

check_instruction_t check_sub;

check_instruction_t check_and;

check_instruction_t check_or;

check_instruction_t check_xor;

check_instruction_t check_zjmp;

check_instruction_t check_ldi;

check_instruction_t check_sti;

check_instruction_t check_fork;

check_instruction_t check_lld;

check_instruction_t check_lldi;

check_instruction_t check_lfork;

check_instruction_t check_aff;

static const check_tab_t INSTRUCTION_TAB[] = {
    { "live", &check_live },
    { "ld", &check_ld },
    { "st", &check_st },
    { "add", &check_add },
    { "sub", &check_sub },
    { "and", &check_and },
    { "or", &check_or },
    { "xor", &check_xor },
    { "zjmp", &check_zjmp },
    { "ldi", &check_ldi },
    { "sti", &check_sti },
    { "fork", &check_fork },
    { "lld", &check_lld },
    { "lldi", &check_lldi },
    { "lfork", &check_lfork },
    { "aff", &check_aff },
};

#endif /* !CHECK_FUNCTIONS_H_ */
