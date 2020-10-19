#include <alibabacloud/endpoint_util.hpp>
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;


string lowercase(string str) {
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return str;
}


string Alibabacloud_EndpointUtil::Client::getEndpointRules(shared_ptr<string> product,
                                                           shared_ptr<string> regionId,
                                                           shared_ptr<string> endpointType,
                                                           shared_ptr<string> network,
                                                           shared_ptr<string> suffix) {
  string productVal = !product ? "" : *product;
  string regionIdVal = !regionId ? "" : *regionId;
  string endpointTypeVal = !endpointType ? "" : *endpointType;
  string networkVal = !network ? "" : *network;
  string result;

  if (!networkVal.empty() && lowercase(networkVal) != "public") {
    productVal.append("-");
  } else {
    networkVal = "";
  }

  if (endpointTypeVal == "regional") {
    if (regionIdVal.empty()) {
      throw runtime_error("RegionId is empty, please set a valid RegionId");
    }
    result.append(productVal)
        .append(networkVal + ".")
        .append(regionIdVal)
        .append(".aliyuncs.com");
  } else {
    result.append(productVal)
        .append(networkVal)
        .append(".aliyuncs.com");
  }
  return lowercase(result);
}

