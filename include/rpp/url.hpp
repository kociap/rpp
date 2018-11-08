#ifndef RPP_URL_HPP
#define RPP_URL_HPP

#include "string.hpp"

namespace rpp {
    class Url {
    public:
        Url(String const &);
        Url(String &&);
        Url(char const *);

        String getFullUrl() const;

    private:
        String url;
    };
} // namespace rpp

#endif // !RPP_URL_HPP