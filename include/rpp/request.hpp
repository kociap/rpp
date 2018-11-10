#ifndef RPP_REQUEST_HPP
#define RPP_REQUEST_HPP

#include "curl/curl.h"
#include "types.hpp"

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

        Response get(URL const&);
        Response post(URL const&, Body const&);

    private:
        CURL* handle;
    };
} // namespace rpp

#endif // !RPP_REQUEST_HPP