#include "rpp/body.hpp"

namespace rpp {
    void Body::append(std::map<String, String> const& params) {
        for (auto const& [key, value] : params) {
            append(key, value);
        }
    }

    void Body::append(String const& key, String const& value) {
        if (!body.empty()) {
            body += "&" + key + "=" + value;
        } else {
            body += key + "=" + value;
        }
    }

    String Body::to_string() const {
        return body;
    }
} // namespace rpp