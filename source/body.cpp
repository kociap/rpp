#include "rpp/body.hpp"

namespace rpp {
    void Body::add(std::initializer_list<BodyItem> const &params) {
        for (BodyItem const &param : params) {
            add(param);
        }
    }

    void Body::add(BodyItem const &param) {
        if (!body.empty()) {
            body += "&" + param.key + "=" + param.value;
        } else {
            body += param.key + "=" + param.value;
        }
    }

    String Body::toString() const {
        return body;
    }
} // namespace rpp