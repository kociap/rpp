#include "rpp/headers.hpp"

namespace rpp {
    Headers::Headers(std::map<String, String> const& headers) : headers(headers) {}
    Headers::Headers(std::map<String, String>&& headers) : headers(std::move(headers)) {}

    void Headers::append(String key, String value) {
        headers.insert_or_assign(std::move(key), std::move(value));
    }
} // namespace rpp