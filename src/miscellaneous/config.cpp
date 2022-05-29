#include "doom/miscellaneous/config.hpp"

#include "doom/miscellaneous/argv.hpp"

#include <SDL_filesystem.h>
#include <config.hpp>

std::filesystem::path doom::misc::conf::configDir;

static std::filesystem::path defaultConfigDir() {
	char* configDir = SDL_GetPrefPath(PROJECT_NAME_SIMPLE, PROJECT_NAME_SIMPLE);
	if (configDir != nullptr) {
		std::filesystem::path result(configDir);
		SDL_free(configDir);
		return result;
	}
	return doom::misc::argv::exedir;
}

void doom::misc::conf::setConfigDir() {
	configDir = defaultConfigDir();
}
