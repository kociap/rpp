#include "rpp/urlsearchparams.hpp"

namespace rpp {
    URL_Search_Params::URL_Search_Params(std::string const& str) : params() {
        uint64_t last_position = 0;
        while (last_position <= str.size()) {
            uint64_t equals_char_position = str.find('=', last_position + 1);
            uint64_t next_position = str.find('&', last_position + 1);
            next_position = next_position > str.size() ? str.size() : next_position;
            params.try_emplace(str.substr(last_position, equals_char_position - last_position),
                               str.substr(equals_char_position + 1, next_position - equals_char_position + 1));
            last_position = next_position + 1;
        }
    }

    URL_Search_Params::URL_Search_Params(char const* cstr) : params() {
        std::string str(cstr);
        uint64_t last_position = 0;
        while (last_position <= str.size()) {
            uint64_t equals_char_position = str.find('=', last_position + 1);
            uint64_t next_position = str.find('&', last_position + 1);
            next_position = next_position > str.size() ? str.size() : next_position;
            params.try_emplace(str.substr(last_position, equals_char_position - last_position),
                               str.substr(equals_char_position + 1, next_position - equals_char_position + 1));
            last_position = next_position + 1;
        }
    }

    URL_Search_Params::URL_Search_Params(std::map<std::string, std::string> const& map) : params(map) {}

    URL_Search_Params::URL_Search_Params(std::map<std::string, std::string>&& map) : params(std::move(map)) {}

    void URL_Search_Params::append(std::string key, std::string value) {
        params.try_emplace(std::move(key), std::move(value));
    }

    std::string URL_Search_Params::get(std::string const& key) {
        return params.find(key)->second;
    }

    bool URL_Search_Params::has(std::string const& key) {
        return params.count(key);
    }

    void URL_Search_Params::remove(std::string const& key) {
        params.erase(key);
    }

    void URL_Search_Params::set(std::string key, std::string value) {
        params.insert_or_assign(std::move(key), std::move(value));
    }

    std::string URL_Search_Params::to_string() {
        std::string query_string;
        for (auto const& [key, value] : params) {
            if (query_string.empty()) {
                query_string += key + "=" + value;
            } else {
                query_string += "&" + key + "=" + value;
            }
        }
        return query_string;
    }

} // namespace rpp