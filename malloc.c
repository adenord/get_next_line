#include <stdlib.h>
#include "get_next_line.h"

static int malloc_count = 0;

void* malloc(size_t size)
{
    void* (*real_malloc)(size_t) = dlsym(RTLD_NEXT, "malloc");
    malloc_count++;

    if (malloc_count == 24)
        return NULL;

    return real_malloc(size);
}

