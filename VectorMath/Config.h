#pragma once

#ifndef CONFIG_H
#define CONFIG_H

#include <type_traits>
#include <iterator>

#define ENABLE      1
#define DISABLE     0

#ifndef USE_UPPERCASE_COMPONENTS
#define USE_UPPERCASE_COMPONENTS        DISABLE
#endif

#endif // CONFIG_H