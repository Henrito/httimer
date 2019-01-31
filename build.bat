if not exist build mkdir build
cl /c /W4 /LD /Iinclude src/win32/timer.c /Fobuild/timer.obj
if not exist lib mkdir lib
if exist build/timer.obj lib build/timer.obj /out:lib/httimer.lib
