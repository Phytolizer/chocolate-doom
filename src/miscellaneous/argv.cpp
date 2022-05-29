#include "doom/miscellaneous/argv.hpp"

#include <algorithm>

std::vector<std::string> doom::misc::argv::args;
std::filesystem::path doom::misc::argv::exedir;

bool doom::misc::argv::exists(std::string_view arg) {
	return std::find(args.begin(), args.end(), arg) != args.end();
}

void doom::misc::argv::setExeDir() {
	exedir = std::filesystem::path(args[0]).parent_path();
}
