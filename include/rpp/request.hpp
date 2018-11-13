#ifndef RPP_REQUEST_HPP
#define RPP_REQUEST_HPP

#include "body.hpp"
#include "headers.hpp"
#include "response.hpp"
#include "url.hpp"

#include "curl/curl.h"

namespace rpp {
    class Request {
    public:
        Request();
        Request(Request const&) = delete;
        Request(Request&&);
        Request& operator=(Request const&) = delete;
        Request& operator=(Request&&);
        ~Request();

        void set_verbose(bool);
        void set_verify_ssl(bool);
        void set_headers(Headers const&);

        Response get(URL const&);
        Response post(URL const&, Body const&);

    private:
        CURL* handle;
        curl_slist* headers;
    };
} // namespace rpp

#endif // !RPP_REQUEST_HPP