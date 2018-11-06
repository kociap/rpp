#include "rpp.hpp"

#include "curl/curl.h"

namespace rpp {
    size_t curlWriteFunction(char *data, size_t, size_t dataSize, String *userdata) {
        userdata->append(data, dataSize);
        return CURLE_OK;
    }

    Response get(String url) {
        CURL *handle = curl_easy_init();
        Response res;
        if (handle) {
            curl_easy_setopt(handle, CURLOPT_URL, url.c_str());

            curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curlWriteFunction);
            curl_easy_setopt(handle, CURLOPT_WRITEDATA, &res.text);

            curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &res.status);

            curl_easy_perform(handle);
            curl_easy_cleanup(handle);
            handle = nullptr;

        } else {
            // Handle error
        }

        return res;
    }

    Response post(String const &url, String const &headers, String const &data) {
        CURL *handle = curl_easy_init();
        Response res;
        if (handle) {
            curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
            curl_easy_setopt(handle, CURLOPT_POST, 1);
            curl_easy_setopt(handle, CURLOPT_POSTFIELDS, data.c_str());

            curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curlWriteFunction);
            curl_easy_setopt(handle, CURLOPT_WRITEDATA, &res.text);

            curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &res.status);

            curl_easy_perform(handle);
            curl_easy_cleanup(handle);
        } else {
            // Handle error
        }

        return res;
    }
} // namespace rpp
