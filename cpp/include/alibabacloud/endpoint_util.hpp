#ifndef ALIBABACLOUD_ENDPOINTUTIL_H_
#define ALIBABACLOUD_ENDPOINTUTIL_H_

#include <iostream>
#include <memory>

using namespace std;

namespace Alibabacloud_EndpointUtil {
class Client {
public:
  static string getEndpointRules(shared_ptr<string> product,
                                 shared_ptr<string> regionId,
                                 shared_ptr<string> endpointType,
                                 shared_ptr<string> network,
                                 shared_ptr<string> suffix);

  Client() {};
  ~Client() {};
};
} // namespace Alibabacloud_EndpointUtil

#endif
