#pragma once

#include <fmt/core.h>
#include <string_view>

namespace doom::deh {

std::string getString(std::string_view key);

template <typename... Args>
void print(std::string_view format, Args&&... args) {
	std::string transFormat = getString(format);
	fmt::vprint(transFormat,
	            fmt::make_format_args(std::forward<Args>(args)...));
}

} // namespace doom::deh
