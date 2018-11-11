#ifndef RPP_BODY_HPP
#define RPP_BODY_HPP

#include "string.hpp"

namespace rpp {
    struct Body_Item {
        String key;
        String value;
    };

    class Body {
    public:
        void append(std::initializer_list<Body_Item> const&);
        void append(Body_Item const&);
        String to_string() const;

    private:
        String body;
    };
} // namespace rpp

#endif // !RPP_BODY_HPP