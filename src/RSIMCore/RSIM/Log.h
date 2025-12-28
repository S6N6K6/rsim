#pragma once

#include "Core.h"
#include "spdlog/fmt/bundled/base.h"
#include <Events/Event.h>
#include <memory.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <sstream>

namespace RSIM {
  class RSIM_API Log {
    public:
      static void Init();
      inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
        return s_coreLogger;
      }
      inline static std::shared_ptr<spdlog::logger> &GetClientLogger() {
        return s_clientLogger;
      }

    private:
      static std::shared_ptr<spdlog::logger> s_coreLogger;
      static std::shared_ptr<spdlog::logger> s_clientLogger;
  };
} // namespace RSIM
//

/*
 * Custom formatter for the Event class that allows logging the events
 * */
namespace fmt {
  template <>
  struct formatter<RSIM::Event> {
      constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }
      template <typename FormatContext>
      auto format(const RSIM::Event &e, FormatContext &ctx) const {
        std::ostringstream oss;
        oss << e;
        return format_to(ctx.out(), "{}", oss.str());
      }
  };
} // namespace fmt

// Core Log Macros
#define RSIM_CORE_TRACE(...) ::RSIM::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RSIM_CORE_INFO(...) ::RSIM::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RSIM_CORE_WARN(...) ::RSIM::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RSIM_CORE_ERROR(...) ::RSIM::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RSIM_CORE_FATAL(...) ::RSIM::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//
// Client Log Macros
#define RSIM_TRACE(...) ::RSIM::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RSIM_INFO(...) ::RSIM::Log::GetClientLogger()->info(__VA_ARGS__)
#define RSIM_WARN(...) ::RSIM::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RSIM_ERROR(...) ::RSIM::Log::GetClientLogger()->error(__VA_ARGS__)
#define RSIM_FATAL(...) ::RSIM::Log::GetClientLogger()->fatal(__VA_ARGS__)
