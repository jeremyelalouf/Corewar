/*
** EPITECH PROJECT, 2022
** virtual_machine
** File description:
** FreeKOSOVO
*/

#ifndef VM_H
    #define VM_H
    #include <stdint.h>

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
int error_handling(int ac, char const *av[]);

#endif/* !VM_H */
