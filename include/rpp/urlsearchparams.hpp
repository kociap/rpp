#ifndef RPP_URL_SEARCH_PARAMS_HPP_INCLUDE
#define RPP_URL_SEARCH_PARAMS_HPP_INCLUDE

#include <map>
#include <string>

namespace rpp {
    class URL_Search_Params {
    public:
        URL_Search_Params() = default;
        URL_Search_Params(std::string const& queryString);
        URL_Search_Params(char const* queryString);
        URL_Search_Params(std::map<std::string, std::string> const&);
        URL_Search_Params(std::map<std::string, std::string>&&);

        void append(std::string key, std::string value);
        std::string get(std::string const& key);
        bool has(std::string const& key);
        void remove(std::string const& key);
        void set(std::string key, std::string value);

        std::string to_string();

    private:
        std::map<std::string, std::string> params;
    };
} // namespace rpp

#endif // !RPP_URL_SEARCH_PARAMS_HPP_INCLUDE