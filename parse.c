#include "source.h"

void parse_args(t_opt *opt, char *arg)
{
    if(is_Command(arg))
    {
        set_flags(opt, arg);
    }
    // if it is path
    else
    {
        set_path(opt, arg);
    }
}
