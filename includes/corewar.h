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
    #define MAX_FOUR_BYTES_VAL "2147483647"
    #define MAX_TWO_BYTES_VAL  "32767"
    #define NBR_OF_INSTRUCTION 16
    #define ERR_UNSIGNED        0
    #define VAL_IND       3
    #define REG_BYTE_SIZE 1

union type {
    uint32_t direct;
    uint16_t indirect;
    uint8_t reg;
};

struct arg {
    uint16_t size;
    union type types;
};

struct instruction {
    uint8_t instruction;
    uint8_t coding_byte;
    struct arg params[MAX_ARGS_NUMBER];
};

typedef struct label_s {
    int *pos;
    char **name;
    int *call;
    int label_nbr;
    int call_nbr;
} label_t;

struct toolbox {
    struct instruction *instructions;
    label_t labels;
};

struct pars_counter {
    char *prog_name;
    int line;
};

int error_handling(int ac, const char *av[]);

char *get_new_file_name(const char *av, struct pars_counter *pars_i);

int compile(char *av[]);

void print_invalid(struct pars_counter *pars_i);

void print_syntax(struct pars_counter *pars_i);

void print_no_name(struct pars_counter *pars_i);

uint8_t create_coding_byte(int instruction, char **param);

int is_size_param_valid(int type, char *param);

int get_parameters_size(struct instruction *instruction);

int write_champions(int compile_filed_fd, FILE *old_file_fd);

int write_header(int compile_filed_fd, FILE *old_file_fd,
    struct pars_counter *pars_i);

#endif /* !PROJECT_H_ */
