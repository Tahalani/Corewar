/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Compare two strings
*/

int my_strcmp(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
    return (0);
}