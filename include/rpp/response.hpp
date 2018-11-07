#ifndef RPP_RESPONSE_HPP
#define RPP_RESPONSE_HPP

#include "types.hpp"

#include <cstdint>

namespace rpp {
    struct Response {
        std::int32_t status;
        String text;
    };
} // namespace rpp

#endif // !RPP_RESPONSE_HPP