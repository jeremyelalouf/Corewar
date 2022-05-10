/*
** EPITECH PROJECT, 2022
** bscorewar
** File description:
** op
*/

#ifndef _OP_H_
   #define _OP_H_
   #define MEM_SIZE (6 * 1024)
   #define MAX_ARGS_NUMBER 4
   #define IDX_MOD 512
   #define SEPARATOR_CHAR ','
   #define COMMENT_CHAR '#'
   #define DIRECT_CHAR '%'
   #define LABEL_CHAR ':'
   #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
   #define NAME_CMD_STRING ".name"
   #define COMMENT_CMD_STRING ".comment"
   #define REG_NUMBER 16
   #define T_REG 1       /* register */
   #define T_DIR 2       /* direct  (ld  #1,r1  put 1 into r1) */
   #define T_IND 4       /* indirect always relative
                                      ( ld 1,r1 put what's in the address (1+pc)
                                      into r1 (4 bytes )) */
   #define T_LAB 8       /* LABEL */
   /*
   ** size (in bytes)
   */
   #define IND_SIZE        2
   #define DIR_SIZE        4
   #define REG_SIZE        DIR_SIZE

typedef char args_type_t;

typedef struct op_s {
   char *mnemonique;
   char nbr_args;
   args_type_t type[MAX_ARGS_NUMBER];
   char code;
   int nbr_cycles;
   char *comment;
} op_t;

/*
** op_tab
*/
extern  op_t    op_tab[];

/*
** header
*/
   #define PROG_NAME_LENGTH        128
   #define COMMENT_LENGTH          2048

typedef struct header_s {
   int  magic;
#define COREWAR_EXEC_MAGIC      0xea83f3
   char prog_name[PROG_NAME_LENGTH + 1];
   int  prog_size;
   char comment[COMMENT_LENGTH + 1];
} header_t;

/*
** live
*/
   #define CYCLE_TO_DIE    1536
   #define CYCLE_DELTA     5
   #define NBR_LIVE        40

op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};

#endif /* _OP_H_ */
