/*
** EPITECH PROJECT, 2022
** main
** File description:
** corewar
*/

#ifndef PROJECT_H_
    #define PROJECT_H_
    #include <stdint.h>
    #include "op.h"

typedef struct instruction_s {
    uint8_t instruction;
    uint8_t coding_byte;
} instruction_t;

int error_handling(int ac, const char *av[]);

char *get_new_file_name(char *av);

#endif /* !PROJECT_H_ */
