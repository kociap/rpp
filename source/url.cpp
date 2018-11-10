#include "rpp/url.hpp"

#include <utility>

namespace rpp {
    using uint64 = unsigned long long;

    URL::URL(String const& str) : url(str) {}
    URL::URL(String&& str) : url(std::move(str)) {}
    URL::URL(char const* str) : url(str) {}

    String URL::get_full_url() const {
        return url;
    }

    URL_Search_Params URL::get_search_params() const {
        uint64 query_position = url.find('?');
        if (url.find('?') >= url.size()) {
            return URL_Search_Params();
        } else {
            return URL_Search_Params(url.substr(query_position + 1));
        }
    }
} // namespace rpp