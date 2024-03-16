#ifndef UTILITY_H
#define UTILITY_H

#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include <getopt.h>
#include <stdio.h>
#include <string.h>

// holds poketype enum classes
// holds category enum class

enum class Category { Physical, Special, Status };

enum class Nature {
    Hardy,
    Lonely,
    Brave,
    Adamant,
    Naughty,
    Docile,
    Bold,
    Relaxed,
    Impish,
    Lax,
    Serious,
    Timid,
    Hasty,
    Jolly,
    Naive,
    Bashful,
    Modest,
    Mild,
    Quiet,
    Rash,
    Quirky,
    Calm,
    Gentle,
    Sassy,
    Careful
};

enum class Gender { Male, Female, None };

#endif   // UTILITY_H
