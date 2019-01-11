#ifndef RPP_BODY_HPP_INCLUDE
#define RPP_BODY_HPP_INCLUDE

#include <map>
#include <string>

namespace rpp {
    class Body {
    public:
        Body() = default;
        Body(std::string const&);
        Body(std::string&&);

        void append(std::map<std::string, std::string> const& params);
        void append(std::string const& key, std::string const& value);
        std::string to_string() const;

    private:
        std::string body;
    };
} // namespace rpp

#endif // !RPP_BODY_HPP_INCLUDE