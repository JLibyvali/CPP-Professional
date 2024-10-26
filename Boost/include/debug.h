#pragma once

#define ANSI_BLACK         "\33[1;30m"
#define ANSI_RED           "\33[1;31m"
#define ANSI_BLUE          "\33[1;34m"
#define ANSI_NONE          "\33[0;m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE