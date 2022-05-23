/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write_label
*/

#include <unistd.h>

#include <corewar.h>

static int label_is_good(struct label_referenced *labels, struct label *label)
{
    for (int i = 0; i != labels->def_size; ++i) {
        if (my_strstr(label->label_name, labels->def[i].label_name) != NULL) {
            return labels->def[i].label_pos;
        }
    }
    return 0;
}

int write_labels(int compile_filed_fd, struct toolbox *toolbox,
    int params_debute)
{
    uint64_t tmp = 0;
    int return_value = 0;

    for (int i = 0; i != toolbox->labels.call_size; ++i) {
        return_value = label_is_good(&toolbox->labels,
            &toolbox->labels.call[i]);
        if (return_value != 0) {
            tmp = return_value - toolbox->labels.call[i].label_pos;
            my_bswap(&tmp, toolbox->labels.call[i].size_to_write);
            lseek(compile_filed_fd, params_debute +
                toolbox->labels.call[i].label_index +
                toolbox->labels.call[i].label_pos, SEEK_SET);
            write(compile_filed_fd, &tmp,
                toolbox->labels.call[i].size_to_write);
        } else
            return ERR;
    }
    return SUCC;
}
