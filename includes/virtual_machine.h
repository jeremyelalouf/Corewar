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

struct arguments {
    char const **av;
    int ac;
};

void live(uint8_t *arene);
void ld(uint8_t *arene);
void st(uint8_t *arene);
void add(uint8_t *arene);
void sub(uint8_t *arene);
void and(uint8_t *arene);
void or(uint8_t *arene);
void xor(uint8_t *arene);
void zjmp(uint8_t *arene);
void ldi(uint8_t *arene);
void sti(uint8_t *arene);
void my_fork(uint8_t *arene);
void lld(uint8_t *arene);
void lldi(uint8_t *arene);
void lfork(uint8_t *arene);
void aff(uint8_t *arene);

int corewar(int ac, char *av[]);
// int handle_flags(struct champion *result, char **av, int *index);
int error_handling(int ac, char const *av[]);

void found_new_nb(struct champion *result, int nb_champions,
    int *value);
struct champion *init_champions(struct champion *);
int capture_number(int *index, int ac, char const *av[], int *dump);
int handly_error_nb_champions(int nb_champions);
int handly_flag_a(int *index, struct champion *result, char const *av[],
    int ac);
int handly_flag_n(int *index, struct champion *result, char const *av[],
    int ac);
int check_nb_of_all_champions(struct champion *result, int nb_champions,
    int *value);

int get_param_instruction(int *i, struct instruction *instruction,
    uint8_t *arena);
int get_size_type(uint8_t type_param);

#endif/* !VM_H */
