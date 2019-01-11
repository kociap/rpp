#include "rpp/url.hpp"

#include <utility>

namespace rpp {
    URL::URL(std::string const& str) : url(str) {}
    URL::URL(std::string&& str) : url(std::move(str)) {}
    URL::URL(char const* str) : url(str) {}

    std::string URL::get_full_url() const {
        return url;
    }

    URL_Search_Params URL::get_search_params() const {
        uint64_t query_position = url.find('?');
        if (url.find('?') >= url.size()) {
            return URL_Search_Params();
        } else {
            return URL_Search_Params(url.substr(query_position + 1));
        }
    }
} // namespace rpp