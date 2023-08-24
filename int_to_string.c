#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
                       char *buff, int buff_size);

/**
 * get_int - Gets a character pointer to a new string containing an int.
 * @num: Number to convert to a string.
 *
 * Return: Character pointer to the newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *ret;

    temp = _abs(num);
    length = get_numbase_len(temp, 10);

    if (num < 0 || num_l < 0)
        length++; /* negative sign */
    ret = malloc(length + 1); /* create a new string */
    if (!ret)
        return (NULL);

    fill_numbase_buff(temp, 10, ret, length);
    if (num < 0 || num_l < 0)
        ret[0] = '-';

    return (ret);
}

/**
 * _abs - Gets the absolute value of an integer.
 * @i: Integer to get the absolute value of.
 *
 * Return: Unsigned integer absolute representation of i.
 */
unsigned int _abs(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}

/**
 * get_numbase_len - Gets the length of the buffer needed for an unsigned int.
 * @num: Number to get the length needed for.
 * @base: Base of the number representation used by the buffer.
 *
 * Return: Integer containing the length of the buffer needed (excluding null byte).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
    int len = 1; /* all numbers contain at least one digit */

    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return (len);
}

/**
 * fill_numbase_buff - Fills the buffer with correct numbers up to base 36.
 * @num: Number to convert to a string in the given base.
 * @base: Base of the number used in conversion (works up to base 36).
 * @buff: Buffer to fill with the result of conversion.
 * @buff_size: Size of the buffer in bytes.
 *
 * Return: Always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
                       char *buff, int buff_size)
{
    int rem, i = buff_size - 1;

    buff[buff_size] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9) /* return lowercase ASCII value representation */
            buff[i] = rem + 87; /* 10 will be 'a', 11 = 'b', ... */
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
