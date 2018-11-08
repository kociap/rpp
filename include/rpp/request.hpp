#ifndef RPP_REQUEST_HPP
#define RPP_REQUEST_HPP

#include "types.hpp"

namespace rpp {
    class Request {
    public:
        Request(Url const &);

        Response get();
        Response post(Body const &);

    private:
        Url url;
    };
} // namespace rpp

#endif // !RPP_REQUEST_HPP