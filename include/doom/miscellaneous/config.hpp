#pragma once

#include <filesystem>

namespace doom::misc::conf {

extern std::filesystem::path configDir;

void setConfigDir();

} // namespace doom::misc::conf
