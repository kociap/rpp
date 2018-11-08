#include "rpp/url.hpp"

#include <utility>

namespace rpp {
    Url::Url(String const &str) : url(str) {}
    Url::Url(String &&str) : url(std::move(str)) {}
    Url::Url(char const *str) : url(str) {}

    String Url::getFullUrl() const {
        return url;
    }
} // namespace rpp