#include <stdio.h>
#include <sys/sysinfo.h>
#include <dlfcn.h>
#include <stdint.h>

#define LIE_IN_GIGS 32

__attribute__ ((constructor)) static void init(void)
{

    fprintf(stderr, "hooking up sysinfo.\n");

    return;
}

int sysinfo(struct sysinfo* info)
{


    int (*sysinfo_true)(struct sysinfo*) = (int(*)(struct sysinfo*)) dlsym(RTLD_NEXT, "sysinfo");

    int res = sysinfo_true(info);

    uint64_t total_reported  = (uint64_t) LIE_IN_GIGS * 1024 * 1024 * 1024;
    total_reported /= info->mem_unit;

    info->totalram = total_reported;

    return res;
}
