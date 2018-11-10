#ifndef RPP_URL_SEARCH_PARAMS_HPP
#define RPP_URL_SEARCH_PARAMS_HPP

#include "string.hpp"

#include <map>

namespace rpp {
    class URL_Search_Params {
    public:
        URL_Search_Params() = default;
        URL_Search_Params(String const& queryString);
        URL_Search_Params(char const* queryString);
        URL_Search_Params(std::map<String, String> const&);
        URL_Search_Params(std::map<String, String>&&);

        void append(String key, String value);
        String get(String const& key);
        bool has(String const& key);
        void remove(String const& key);
        void set(String key, String value);

        String to_string();

    private:
        std::map<String, String> params;
    };
} // namespace rpp

#endif // !RPP_URL_SEARCH_PARAMS_HPP