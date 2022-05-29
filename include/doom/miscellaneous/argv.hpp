#pragma once

#include <filesystem>
#include <string>
#include <string_view>
#include <vector>

namespace doom::misc::argv {

extern std::vector<std::string> args;
extern std::filesystem::path exedir;

bool exists(std::string_view arg);
void setExeDir();

} // namespace doom::misc::argv
