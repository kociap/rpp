#ifndef RPP_BODY_HPP
#define RPP_BODY_HPP

#include "string.hpp"

#include <map>

namespace rpp {
    class Body {
    public:
        Body(String const&);
        Body(String&&);

        void append(std::map<String, String> const& params);
        void append(String const& key, String const& value);
        String to_string() const;

    private:
        String body;
    };
} // namespace rpp

#endif // !RPP_BODY_HPP