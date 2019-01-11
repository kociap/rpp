#ifndef RPP_HEADERS_HPP_INCLUDE
#define RPP_HEADERS_HPP_INCLUDE

#include <map>
#include <string>

namespace rpp {
    class Request;

    class Headers {
        friend class Request;

    public:
        Headers() = default;
        Headers(std::map<std::string, std::string> const&);
        Headers(std::map<std::string, std::string>&&);

        void append(std::string key, std::string value);

    private:
        std::map<std::string, std::string> headers;
    };
} // namespace rpp

#endif // !RPP_HEADERS_HPP_INCLUDE