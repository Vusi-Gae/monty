#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
                       char *buff, int buff_size);

/**
 * get_int - Converts an integer to a string
 * @num: The number to convert
 *
 * Returns: A pointer to the newly created string, or NULL if malloc fails.
 */
char *get_int(int num) {
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *ret;

    temp = _abs(num);
    length = get_numbase_len(temp, 10);

    if (num < 0 || num_l < 0)
        length++; /* Consider negative sign */
    ret = malloc(length + 1); /* Allocate memory for new string */
    if (!ret)
        return NULL;

    fill_numbase_buff(temp, 10, ret, length);
    if (num < 0 || num_l < 0)
        ret[0] = '-';

    return ret;
}

/**
 * _abs - Calculates the absolute value of an integer
 * @i: The integer to calculate absolute value for
 *
 * Returns: The absolute value of the integer as an unsigned integer
 */
unsigned int _abs(int i) {
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}

/**
 * get_numbase_len - Calculates the length of buffer needed for an unsigned int
 * @num: The number to calculate buffer length for
 * @base: The base used for number representation in the buffer
 *
 * Returns: The length of buffer needed (excluding null byte)
 */
int get_numbase_len(unsigned int num, unsigned int base) {
    int len = 1; /* All numbers have at least one digit */

    while (num > base - 1) {
        len++;
        num /= base;
    }
    return len;
}

/**
 * fill_numbase_buff - Fills the buffer with correct numbers up to base 36
 * @num: The number to convert to string in the given base
 * @base: The base used for conversion (works up to base 36)
 * @buff: The buffer to fill with the conversion result
 * @buff_size: The size of the buffer in bytes
 *
 * Returns: Void
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
                       char *buff, int buff_size) {
    int rem, i = buff_size - 1;

    buff[buff_size] = '\0';
    while (i >= 0) {
        rem = num % base;
        if (rem > 9)
            buff[i] = rem + 87; /* Using lowercase ASCII values: 10=a, 11=b, ... */
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
