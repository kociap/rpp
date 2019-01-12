#ifndef RPP_URL_HPP_INCLUDE
#define RPP_URL_HPP_INCLUDE

#include "urlsearchparams.hpp"
#include <string>

namespace rpp {
    class URL {
    public:
        URL() = default;
        URL(std::string const&);
        URL(std::string&&);
        URL(char const*);
        URL& operator=(std::string const&);
        URL& operator=(std::string&&);
        URL& operator=(char const*);

        std::string get_full_url() const;
        URL_Search_Params get_search_params() const;

    private:
        std::string url;
    };
} // namespace rpp

#endif // !RPP_URL_HPP_INCLUDE