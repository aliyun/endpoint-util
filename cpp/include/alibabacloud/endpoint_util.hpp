#ifndef CPP_INCLUDE_ALIBABACLOUD_ENDPOINTUTIL_H
#define CPP_INCLUDE_ALIBABACLOUD_ENDPOINTUTIL_H

#include <boost/any.hpp>
#include <darabonba/core.hpp>
#include <map>


namespace Alibabacloud_endpoint_util {
class Client
{
public:
  Client();
  ~Client();
  static string getEndpointRules(string *product, string *regionId, string *endpointType, string *network,string *suffix);
};
}
#endif //CPP_INCLUDE_ALIBABACLOUD_ENDPOINTUTIL_H
