#include "rpp/body.hpp"

namespace rpp {
    Body::Body(std::string const& body) : body(body) {}
    Body::Body(std::string&& body) : body(std::move(body)) {}

    void Body::append(std::map<std::string, std::string> const& params) {
        for (auto const& [key, value] : params) {
            append(key, value);
        }
    }

    void Body::append(std::string const& key, std::string const& value) {
        if (!body.empty()) {
            body += "&" + key + "=" + value;
        } else {
            body += key + "=" + value;
        }
    }

    std::string Body::to_string() const {
        return body;
    }
} // namespace rpp