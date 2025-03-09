Compile with GCC:

`gcc -Wall -fPIC -shared -o ./sysinfo_lie.so ./sysinfo_lie.c`

Place the resulting `sysinfo_lie.so` file in `.../Steam/steamapps/common/Diablo IV/` and add the following to Steam launch options:

`LD_PRELOAD=./sysinfo_lie.so %command%`
