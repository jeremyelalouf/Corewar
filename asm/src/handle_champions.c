/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** handle_champions
*/

#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "corewar.h"

// static const instruction_tab_t INSTRUCTION_TAB[] = {
//     { "live", &check_live },
//     { "ld", &check_ld },
//     { "st", &check_st },
//     { "add", &check_add },
//     { "sub", &check_sub },
//     { "and", &check_and },
//     { "or", &check_or },
//     { "xor", &check_xor },
//     { "zjmp", &check_zjmp },
//     { "ldi", &check_ldi },
//     { "sti", &check_sti },
//     { "fork", &check_fork },
//     { "lld", &check_lld },
//     { "lldi", &check_lldi },
//     { "lfork", &check_lfork },
//     { "aff", &check_aff },
// };

int add_label_pos(char *label, label_t *label_struct, int line_read)
{
    label_struct->pos = realloc(label_struct->pos, label_struct->label_nbr);
    label_struct->pos[label_struct->label_nbr] = line_read;
    return SUCC;
}

static int call_check_function(
    int compile_filed_fd,
    char *command,
    toolbox_t *toolbox)
{
    char **array = my_str_to_word_array(command, " ,\t\n");

    if (array == NULL)
        return ERR;
    if (my_char_in_str(array[0], LABEL_CHAR) == TRUE)
        array += 1;
    for (int i = 0; i != sizeof(INSTRUCTION_TAB) / sizeof(*INSTRUCTION_TAB);
        ++i) {
        if (my_strcmp(array[0], INSTRUCTION_TAB[i].instruction) == 0)
            INSTRUCTION_TAB[i].function(array, compile_filed_fd);
    }
    return SUCC;
}

int write_champions(int compile_filed_fd, FILE *old_file_fd)
{
    char *line = NULL;
    char **array = NULL;
    size_t size = 0;
    toolbox_t toolbox = {
        .line_read = 0,
        .labels.label_nbr = 0,
        .labels.call_nbr = 0,
    };
    int i = 0;

    while (getline(&line, &size, old_file_fd) != -1) {
        if (my_strlen(line) < 2)
            continue;
        toolbox.instructions = realloc(toolbox.instructions, toolbox.line_read + 1);
        if (toolbox.instructions == NULL)
            return ERR;
        call_check_function(compile_filed_fd, line, &toolbox);
        ++toolbox.line_read;
    }
    return SUCC;
}
