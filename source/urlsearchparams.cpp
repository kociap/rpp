#include "rpp/urlsearchparams.hpp"

namespace rpp {
    using uint64 = unsigned long long;

    URL_Search_Params::URL_Search_Params(String const& str) : params() {
        uint64 last_position = 0;
        while (last_position <= str.size()) {
            uint64 equals_char_position = str.find('=', last_position + 1);
            uint64 next_position = str.find('&', last_position + 1);
            next_position = next_position > str.size() ? str.size() : next_position;
            params.try_emplace(str.substr(last_position, equals_char_position - last_position),
                               str.substr(equals_char_position + 1, next_position - equals_char_position + 1));
            last_position = next_position + 1;
        }
    }

    URL_Search_Params::URL_Search_Params(char const* cstr) : params() {
        String str(cstr);
        uint64 last_position = 0;
        while (last_position <= str.size()) {
            uint64 equals_char_position = str.find('=', last_position + 1);
            uint64 next_position = str.find('&', last_position + 1);
            next_position = next_position > str.size() ? str.size() : next_position;
            params.try_emplace(str.substr(last_position, equals_char_position - last_position),
                               str.substr(equals_char_position + 1, next_position - equals_char_position + 1));
            last_position = next_position + 1;
        }
    }

    URL_Search_Params::URL_Search_Params(std::map<String, String> const& map) : params(map) {}

    URL_Search_Params::URL_Search_Params(std::map<String, String>&& map) : params(std::move(map)) {}

    void URL_Search_Params::append(String key, String value) {
        params.try_emplace(std::move(key), std::move(value));
    }

    String URL_Search_Params::get(String const& key) {
        return params.find(key)->second;
    }

    bool URL_Search_Params::has(String const& key) {
        return params.count(key);
    }

    void URL_Search_Params::remove(String const& key) {
        params.erase(key);
    }

    void URL_Search_Params::set(String key, String value) {
        params.insert_or_assign(std::move(key), std::move(value));
    }

    String URL_Search_Params::to_string() {
        String query_string;
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