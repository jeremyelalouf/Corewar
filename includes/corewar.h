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
    #define MAX_FOUR_BYTES_VAL  "2147483647"
    #define MAX_TWO_BYTES_VAL   "32767"
    #define NBR_OF_INSTRUCTION  16
    #define ERR_UNSIGNED        0
    #define VAL_IND             3
    #define REG_BYTE_SIZE       1
    #define END_OF_TAB          -1
    #define FLAGS_NUMBER        2
    #define TMP_COREWAR_FILE    "/tmp/corewar.tmp"

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
    int index;
};

struct champion {
    int carry;
    int is_dead;
    int nbr_cycle_last_live;
    int actual_cycle;
    const char *filepath;
    struct instruction *i;
    uint32_t registers[REG_NUMBER];
    header_t h;
    int nb;
    int address;
    int address_offset;
};

struct vm_i {
    struct champion *champions;
    int dump;
    int champions_nbr;
};

struct label {
    char *label_name;
    int label_pos;
    int label_index;
    int size_to_write;
};

struct label_referenced {
    struct label *call;
    int call_size;
    struct label *def;
    int def_size;
};

struct toolbox {
    struct instruction *instructions;
    struct label_referenced labels;
};

struct pars_counter {
    char *prog_name;
    int line;
};

typedef struct write_function {
    uint8_t size;
    void (*fun_ptr) (int, union type *);
} write_function_t;

typedef void handle_flag_t(struct champion *c, int value);

struct handle_flags {
    const char *flag;
    handle_flag_t *func;
};

int error_handling(int ac, const char *av[]);

char *get_new_file_name(const char *av, struct pars_counter *pars_i);

int compile(char *av[]);

void print_invalid(struct pars_counter *pars_i);

void print_syntax(struct pars_counter *pars_i);

void print_no_name(struct pars_counter *pars_i);

int label_handling(struct toolbox *toolbox, char *line, int i, int *pos,
    char **solo_label);

int unusable_line(char *line);

int there_is_solo_label(char *line, char **solo_label);

int fill_params_array(struct instruction *instruction, char **params);

uint8_t create_coding_byte(int instruction, char **param);

int is_size_param_valid(int type, char *param);

int get_parameters_size(struct instruction *instruction);

int write_champions(int compile_filed_fd, FILE *old_file_fd,
    int params_debute);

int write_labels(int compile_filed_fd, struct toolbox *toolbox,
    int params_debute);

int has_coding_byte(uint8_t instruction);

int sec_has_coding_byte(uint8_t instruction);

int write_header(int compile_filed_fd, FILE *old_file_fd,
    struct pars_counter *pars_i, int *params_debute);

void write_indirect(int fd, union type *params);

void write_direct(int fd, union type *params);

void write_register(int fd, union type *params);

int write_instruction(int fd, struct instruction *instruction);

void fill_magic(header_t *header);

int handle_comment(char **line, size_t *size, FILE *old_file_fd);

#endif /* !PROJECT_H_ */
