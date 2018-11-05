#ifndef RPP_RPP_HPP
#define RPP_RPP_HPP

#include "response.hpp"
#include "types.hpp"

namespace rpp {
    Response get(String url);
    Response post(String url);
    Response put(String url);
} // namespace rpp

#endif // !RPP_RPP_HPP
