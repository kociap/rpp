#ifndef RPP_RESPONSE_HPP_INCLUDE
#define RPP_RESPONSE_HPP_INCLUDE

#include <cstdint>
#include <string>

namespace rpp {
    struct Response {
        std::int32_t status;
        std::string text;
    };
} // namespace rpp

#endif // !RPP_RESPONSE_HPP_INCLUDE