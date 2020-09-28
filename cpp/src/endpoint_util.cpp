#include <alibabacloud/endpoint_util.hpp>
#include <boost/any.hpp>

using namespace Alibabacloud_endpoint_util;
using namespace std;


string lowercase(string str) {
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return str;
}

string Alibabacloud_endpoint_util::Client::getEndpointRules(
    string *product,
    string *regionId,
    string *endpointType,
    string *network,
    string *suffix)
{
  string productVal = nullptr == product ? "" : *product;
  string regionIdVal = nullptr == regionId ? "" : *regionId;
  string endpointTypeVal = nullptr == endpointType ? "" : *endpointType;
  string networkVal = nullptr == network ? "" : *network;
  string result = "";

  if (!networkVal.empty() && networkVal != "public") {
    productVal.append("-");
  } else {
    networkVal = "";
  }

  if (endpointTypeVal == "regional") {
    if (regionIdVal.empty()) {
      throw runtime_error("RegionId is empty, please set a valid RegionId");
    }
    result.append(lowercase(productVal))
          .append(networkVal + ".")
          .append(regionIdVal)
          .append(".aliyuncs.com");
  } else {
    result.append(lowercase(productVal))
          .append(networkVal)
          .append(".aliyuncs.com");
  }
  return result;
}
