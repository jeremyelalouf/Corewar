/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** print_error
*/

#include "my.h"
#include "corewar.h"

void print_invalid(struct pars_counter *pars_i)
{
    my_putsterr("\033[1;37m");
    my_putsterr("asm, ");
    my_putsterr(pars_i->prog_name);
    my_putsterr(", line ");
    my_put_nberr(pars_i->line);
    my_putsterr(": ");
    my_putsterr("\033[1;31m");
    my_putsterr("Invalid instruction.\n");
    my_putsterr("\033[0m");
}

void print_syntax(struct pars_counter *pars_i)
{
    my_putsterr("\033[1;37m");
    my_putsterr("asm, ");
    my_putsterr(pars_i->prog_name);
    my_putsterr(", line ");
    my_put_nberr(pars_i->line);
    my_putsterr(": ");
    my_putsterr("\033[1;31m");
    my_putsterr("Syntax error.\n");
    my_putsterr("\033[0m");
}

void print_no_name(struct pars_counter *pars_i)
{
    my_putsterr("\033[1;37m");
    my_putsterr("asm, ");
    my_putsterr(pars_i->prog_name);
    my_putsterr(", line ");
    my_put_nberr(pars_i->line);
    my_putsterr(": ");
    my_putsterr("\033[1;31m");
    my_putsterr("No name specified.\n");
    my_putsterr("\033[0m");
}
