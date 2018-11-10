#include "rpp/body.hpp"

namespace rpp {
    void Body::add(std::initializer_list<Body_Item> const& params) {
        for (Body_Item const& param : params) {
            add(param);
        }
    }

    void Body::add(Body_Item const& param) {
        if (!body.empty()) {
            body += "&" + param.key + "=" + param.value;
        } else {
            body += param.key + "=" + param.value;
        }
    }

    String Body::to_string() const {
        return body;
    }
} // namespace rpp