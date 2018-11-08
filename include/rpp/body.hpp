#ifndef RPP_PARAMETERS_HPP
#define RPP_PARAMETERS_HPP

#include "string.hpp"

namespace rpp {
    struct BodyItem {
        String key;
        String value;
    };

    class Body {
    public:
        void add(std::initializer_list<BodyItem> const &);
        void add(BodyItem const &);
        String toString() const;

    private:
        String body;
    };
} // namespace rpp

#endif // !RPP_PARAMETERS_HPP