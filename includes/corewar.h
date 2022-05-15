/*
** EPITECH PROJECT, 2022
** main
** File description:
** corewar
*/

#ifndef PROJECT_H_
    #define PROJECT_H_
    #include <stdint.h>
    #include <stdio.h>
    #include "op.h"
    #define ERR_UNSIGNED        0
    #define NBR_OF_INSTRUCTION 16
    #define MAX_FOUR_BYTES_VAL "2147483647"
    #define MAX_TWO_BYTES_VAL  "32767"

typedef struct instruction_w_index {
    uint8_t instruction;
    int have_index;
} instruction_w_index_t;

union arg {
    uint32_t direct;
    uint16_t indirect;
    uint8_t reg;
};

typedef struct instruction_s {
    uint8_t instruction;
    uint8_t coding_byte;
    union arg params[MAX_ARGS_NUMBER];
} instruction_t;

typedef int check_instruction_t (char *line, int fd);

typedef struct instruction_tab_s {
    char *instruction;
    check_instruction_t *function;
} instruction_tab_t;

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

int error_handling(int ac, const char *av[]);

char *get_new_file_name(char *av);

int compile(char *av[]);

uint8_t create_coding_byte(int instruction, char **param);

int is_size_param_valid(int type, char *param);

int find_total_instruction_size(instruction_t *instruction);

int write_champions(int compile_filed_fd, FILE *old_file_fd);

int write_header(int compile_filed_fd, FILE *old_file_fd);

#endif /* !PROJECT_H_ */
