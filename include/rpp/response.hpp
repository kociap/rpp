#ifndef RPP_RESPONSE_HPP
#define RPP_RESPONSE_HPP

#include "types.hpp"

#include <cstdint>

struct Response {
    std::int32_t status;
    String text;
};

#endif // !RPP_RESPONSE_HPP