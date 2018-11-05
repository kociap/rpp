#include "rpp.hpp"

#include "curl/curl.h"

namespace rpp {
    Response get() {
        curl_easy_init();
    }
} // namespace rpp
