#ifndef RPP_HEADERS_HPP
#define RPP_HEADERS_HPP

#include "string.hpp"

#include <map>

namespace rpp {
    class Request;

    class Headers {
        friend class Request;

    public:
        Headers() = default;
        Headers(std::map<String, String> const&);
        Headers(std::map<String, String>&&);

        void append(String key, String value);

    private:
        std::map<String, String> headers;
    };
} // namespace rpp

#endif // !RPP_HEADERS_HPP