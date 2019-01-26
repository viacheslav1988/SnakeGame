#pragma once

#include <io.h>
#include <fcntl.h>

#define RUSSIAN_SUPPORT_ENCODING _setmode(_fileno(stdout), _O_U16TEXT); _setmode(_fileno(stdin), _O_U16TEXT); _setmode(_fileno(stderr), _O_U16TEXT);