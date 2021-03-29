#include "../ft_printf.h"

void
    ft_count_putchar(t_input *input, char c)
{
    write(1, &c, 1);
    input->length++;
}