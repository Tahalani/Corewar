/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-mehdi.djendar
** File description:
** error_four
*/

#include "my.h"
#include "corewar.h"
#include "error_asm.h"

int error_aff(char **params)
{
    if (params[2] != NULL)
        return (84);
    return (0);
}

int error_options(char **params)
{
    int return_value = 0;

    for (int count = 0; count != 16; count++) {
        if (my_strcmp(params[0], ERROR_ARRAY[count]) == 0) {
            return_value = (*ERROR_FUNC[count]) (params);
            return (return_value);
        }
    }
    return (return_value);
}

int error_before_getline(char *path)
{
    char *buff = my_file_in_str(path);
    char **line = str_to_word(buff, '\n');
    int count_name = 0;
    int count_comment = 0;

    for (int i = 0; line[i]; i++) {
        if (my_strstr(line[i], ".name") != NULL)
            count_name++;
    }
    for (int j = 0; line[j]; j++)
        if (my_strstr(line[j], ".comment") != NULL)
            count_comment++;
    if (count_name != 1 || count_comment != 1)
        return (84);
    return (0);
}

int error_handling(char *buffer)
{
    char **params = my_str_to_word_array(buffer, ' ');

    for (int i = 0; params[i]; i++)
        if (error_options(params) == 84)
            return (84);
    return (0);
}
