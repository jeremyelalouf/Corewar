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

typedef struct instruction_s {
    uint8_t instruction;
    uint8_t coding_byte;
} instruction_t;

typedef int check_instruction_t (char *line, int fd);

typedef struct instruction_tab_s {
    char *instruction;
    check_instruction_t *function;
} instruction_tab_t;

check_instruction_t check_live;

int error_handling(int ac, const char *av[]);

char *get_new_file_name(char *av);

int compile(char *av[]);

int write_champions(int compile_filed_fd, FILE *old_file_fd);

int write_header(int compile_filed_fd, FILE *old_file_fd);

#endif /* !PROJECT_H_ */
