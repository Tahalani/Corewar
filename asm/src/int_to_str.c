/*
** EPITECH PROJECT, 2021
** int_to_string
** File description:
** int_to_string
*/

#include <stdlib.h>

char *int_to_str(int number)
{
  int size = 0;
  char *string;
  int pmt = number;

  while (pmt > 0) {
    pmt /= 10;
    size++;
  }
  string = malloc(sizeof(*string) * (size + 1));
  string[size] = '\0';
  while (size--) {
    string[size] = number % 10  + '0';
    number /= 10;
  }
    return (string);
}
