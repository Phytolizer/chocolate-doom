#pragma once

#include <string_view>

namespace doom::sys {

using AtExitFunc = void (*)() noexcept;

enum class OnError {
	SKIP,
	RUN,
};

void atExit(AtExitFunc func, OnError onError);
void quit();
void printBanner(std::string_view message);
void printDivider();

} // namespace doom::sys
