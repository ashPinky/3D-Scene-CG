#ifndef STRING_HPP
#define STRING_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "../common/Alias.hpp"

namespace re
{
    std::string ReadLine(FILE* filestream);
    std::string FirstToken(std::string in);
    std::vector<std::string> SplitString(std::string in, std::string token);
}

#endif