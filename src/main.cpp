#include "doom/main.hpp"

#include "doom/dehacked/strings.hpp"
#include "doom/english.hpp"
#include "doom/miscellaneous/argv.hpp"
#include "doom/stat.hpp"
#include "doom/system.hpp"
#include "doom/system/video.hpp"

#include <charconv>
#include <config.hpp>

int doom::main() {
	sys::printBanner(PROJECT_NAME_PRETTY);
	stat::noMonsters = misc::argv::exists("-nomonsters");
	stat::respawnParm = misc::argv::exists("-respawn");
	stat::fastParm = misc::argv::exists("-fast");
	stat::devParm = misc::argv::exists("-devparm");

	sys::vid::displayFpsDots(stat::devParm ? sys::vid::FpsDotsState::SHOW
	                                       : sys::vid::FpsDotsState::HIDE);

	if (stat::devParm) {
		deh::print(eng::DEVSTR);
	}

	std::size_t turboParm = misc::argv::check("-turbo");
	if (turboParm > 0) {
		int scale = 200;
		if (turboParm < misc::argv::args.size()) {
			std::string_view turboArg = misc::argv::args[turboParm];
			auto result =
				std::from_chars(turboArg.begin(), turboArg.end(), scale);
			if (result.ec != std::errc{}) {
				scale = 200;
			}

			scale = std::clamp(scale, 10, 400);
		}

		deh::print("turbo scale: {}%", scale);
		stat::forwardMove[0] = stat::forwardMove[0] * scale / 100;
		stat::forwardMove[1] = stat::forwardMove[1] * scale / 100;
		stat::sideMove[0] = stat::sideMove[0] * scale / 100;
		stat::sideMove[1] = stat::sideMove[1] * scale / 100;
	}

	deh::print("V_Init: allocate screens.\n");

	deh::print("M_LoadDefaults: Load system defaults.\n");

	return 0;
}
