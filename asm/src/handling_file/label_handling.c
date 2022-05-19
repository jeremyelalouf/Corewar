/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** label_handling
*/

#include <stdlib.h>

#include "corewar.h"

static int get_instruction_size(struct instruction *instruction)
{
    int size = 0;
    int nbr_params = get_parameters_size(instruction);

    for (int i = 0; i != nbr_params; ++i)
        size += instruction->params[i].size;
    return size + 1 + sec_has_coding_byte(instruction->instruction);
}

static int handle_label_declaration(char ***array, struct instruction *i,
    struct label_referenced *l)
{
    if (my_char_in_str(*array[0], LABEL_CHAR) == TRUE) {
        l->def = realloc(l->def, sizeof(*l->def) *
            (l->def_size + 1));
        if (l->def == NULL)
            return ERR;
        l->def[l->def_size].label_name = my_strdup(*array[0]);
        l->def[l->def_size].label_name[my_strlen(*array[0]) - 1]
            = '\0';
        l->def[l->def_size].label_pos = i->index;
        l->def_size += 1;
        *array += 1;
    }
    return SUCC;
}

static int handle_label_call(char **array, struct instruction *i,
    struct label_referenced *l, int index)
{
    if (my_char_in_str(array[index], LABEL_CHAR) == TRUE) {
        l->call = realloc(l->call, sizeof(*l->call) * (l->call_size + 1));
        if (l->call == NULL)
            return ERR;
        l->call[l->call_size].label_name = my_strdup(array[index]);
        l->call[l->call_size].label_index = index +
            has_coding_byte(i->instruction);
        l->call[l->call_size].label_pos = i->index;
        l->call[l->call_size].size_to_write = i->params[index - 1].size;
        l->call_size += 1;
    }
    return SUCC;
}

static int handle_label(char *command, struct instruction *instruction,
    struct label_referenced *labels)
{
    char **array = my_str_to_word_array(command, " ,\t\n");

    if (array == NULL)
        return ERR;
    if (handle_label_declaration(&array, instruction, labels) == ERR)
        return ERR;
    for (int i = 0; array[i] != NULL; ++i) {
        if (handle_label_call(array, instruction, labels, i) == ERR)
            return ERR;
    }
    return SUCC;
}

void label_handling(struct toolbox *toolbox, char *line, int i, int *pos)
{
    toolbox->instructions[i].index = *pos;
    handle_label(line, &toolbox->instructions[i], &toolbox->labels);
    *pos += get_instruction_size(&toolbox->instructions[i]);
}
