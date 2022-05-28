#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace doom::misc::argv {

extern std::vector<std::string> args;

bool exists(std::string_view arg);

} // namespace doom::argv
