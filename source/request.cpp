#include "rpp/request.hpp"
#include "curl/curl.h"

namespace rpp {
    Request::Request() : handle(curl_easy_init()), headers(nullptr) {}

    Request::Request(Request&& req) : handle(req.handle), headers(req.headers) {
        req.handle = nullptr;
        req.headers = nullptr;
    }

    Request& Request::operator=(Request&& req) {
        handle = req.handle;
        headers = req.headers;
        req.handle = nullptr;
        req.headers = nullptr;
        return *this;
    }

    Request::~Request() {
        if (handle != nullptr) {
            curl_easy_cleanup(handle);
        }

        if (headers != nullptr) {
            curl_slist_free_all(headers);
        }
    }

    void Request::set_verbose(bool verbose) {
        curl_easy_setopt(handle, CURLOPT_VERBOSE, verbose);
    }

    void Request::set_verify_ssl(bool verify) {
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, verify);
    }

    void Request::set_headers(Headers const& hs) {
        if (hs.headers.empty()) {
            curl_easy_setopt(handle, CURLOPT_HTTPHEADER, NULL);
            return;
        }

        if (headers != nullptr) {
            curl_slist_free_all(headers);
            headers = NULL;
        }

        for (auto const& [key, value] : hs.headers) {
            if (value.empty()) {
                headers = curl_slist_append(headers, (key + ";").data());
            } else {
                headers = curl_slist_append(headers, (key + ": " + value).data());
            }
        }

        curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);
    }

    size_t curl_write_function(char* data, size_t, size_t data_size, String* user_data) {
        user_data->append(data, data_size);
        return data_size;
    }

    Response Request::get(URL const& url) {
        Response res;
        String full_url = url.get_full_url();
        curl_easy_setopt(handle, CURLOPT_URL, full_url.c_str());
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curl_write_function);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &res.text);

        curl_easy_perform(handle);

        curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &res.status);

        return res;
    }

    Response Request::post(URL const& url, Body const& body) {
        Response res;
        String data = body.to_string();
        String full_url = url.get_full_url();
        curl_easy_setopt(handle, CURLOPT_URL, full_url.c_str());
        curl_easy_setopt(handle, CURLOPT_POST, 1);
        curl_easy_setopt(handle, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curl_write_function);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &res.text);

        curl_easy_perform(handle);

        curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &res.status);

        return res;
    }
} // namespace rpp