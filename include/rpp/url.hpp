#ifndef RPP_URL_HPP
#define RPP_URL_HPP

#include "string.hpp"
#include "urlsearchparams.hpp"

namespace rpp {
    class URL {
    public:
        URL(String const&);
        URL(String&&);
        URL(char const*);

        String get_full_url() const;
        URL_Search_Params get_search_params() const;

    private:
        String url;
    };
} // namespace rpp

#endif // !RPP_URL_HPP