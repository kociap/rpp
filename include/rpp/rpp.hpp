#ifndef RPP_RPP_HPP
#define RPP_RPP_HPP

#include "response.hpp"
#include "types.hpp"

namespace rpp {
    Response get(String const &url);
    Response post(String const &url, String const &headers, String const &data);
} // namespace rpp

#endif // !RPP_RPP_HPP
