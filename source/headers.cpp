#include "rpp/headers.hpp"

namespace rpp {
    Headers::Headers(std::map<std::string, std::string> const& headers) : headers(headers) {}
    Headers::Headers(std::map<std::string, std::string>&& headers) : headers(std::move(headers)) {}

    void Headers::append(std::string key, std::string value) {
        headers.insert_or_assign(std::move(key), std::move(value));
    }
} // namespace rpp