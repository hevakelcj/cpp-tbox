#include "request.h"
#include <tbox/base/defines.h>
#include <sstream>

namespace tbox {
namespace http {

bool Request::isValid() const
{
    return method != Method::kUnset && http_ver != HttpVer::kUnset && !url.empty();
}

std::string Request::toString() const
{
    std::ostringstream oss;
    oss << method << " " << url << " " << http_ver << CRLF;
    for (auto &head : headers)
        oss << head.first << ": " << head.second << CRLF;
    oss << "Content-Length: " << body.length() << CRLF;
    oss << CRLF;
    oss << body;

    return oss.str();
}

}
}