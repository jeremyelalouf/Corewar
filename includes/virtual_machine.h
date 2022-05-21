/*
** EPITECH PROJECT, 2022
** virtual_machine
** File description:
** FreeKOSOVO
*/

#ifndef VM_H
    #define VM_H
    #include <stdint.h>
    #include "corewar.h"

typedef void instruction_fun_t(struct champion * c, uint8_t *arena,
    struct champion *fork_param);

instruction_fun_t live;

instruction_fun_t ld;

instruction_fun_t my_st;

instruction_fun_t add;

instruction_fun_t sub;

instruction_fun_t my_and;

instruction_fun_t my_or;

instruction_fun_t my_xor;

instruction_fun_t zjmp;

instruction_fun_t ldi;

instruction_fun_t sti;

instruction_fun_t my_fork;

instruction_fun_t lld;

instruction_fun_t lldi;

instruction_fun_t lfork;

instruction_fun_t aff;

typedef struct instruction_fun_tab {
    instruction_fun_t *fun;
} instruction_fun_tab_t;

static const instruction_fun_tab_t TAB_FUN_INSTRUCTION[] = {
    { &live },
    { &ld },
    { &my_st },
    { &add },
    { &sub },
    { &my_and },
    { &my_or },
    { &my_xor },
    { &zjmp },
    { &ldi },
    { &sti },
    { &my_fork },
    { &lld },
    { &lldi },
    { &lfork },
    { &aff },
};

typedef struct get_value_func {
    uint8_t type;
    uint32_t (*fun) (int, struct champion *, uint8_t *);
} get_value_func_t;

uint32_t get_reg_val(int i_nb, struct champion *c, uint8_t *arena);
uint32_t get_ind_val(int i_nb, struct champion *c, uint8_t *arena);
uint32_t get_dir_val(int i_nb, struct champion *c, uint8_t *arena);

static const get_value_func_t TAB_GET_VALUE[] = {
    { T_REG, &get_reg_val },
    { T_DIR, &get_dir_val },
    { VAL_IND, &get_ind_val },
};

int corewar(int ac, const char *av[]);
int handle_flags(struct champion *result, char **av, int *index);
int error_handling(int ac, char const *av[]);

int handle_champion_action(struct champion *champions,
    uint8_t *arena);

int get_param_instruction(int *i, struct instruction *instruction,
    uint8_t *arena);
int get_size_type(uint8_t type_param);
uint32_t get_n_byte_val(int n, int address, uint8_t *arena);
uint8_t get_type_param(int param_pos, uint8_t coding_byte);

int is_game_win_or_lose(int nbr_champions, int nbr_dead_champions,
    struct champion *champions);

#endif/* !VM_H */
