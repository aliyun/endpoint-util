#include "gtest/gtest.h"
#include <alibabacloud/endpoint_util.hpp>
#include <iostream>

using namespace std;
using namespace Alibabacloud_endpoint_util;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


TEST(tests, getEndpointRules) {
  try{
    Client::getEndpointRules(
        new string("ecs"),
        new string(""),
        new string("regional"),
        new string(""),
        nullptr);
    throw exception();
  } catch (runtime_error& err) {
    ASSERT_EQ(string("RegionId is empty, please set a valid RegionId"), err.what());
  }

  ASSERT_EQ(
      "ecs.cn-hangzhou.aliyuncs.com",
      Client::getEndpointRules(
          new string("ecs"),
          new string("cn-hangzhou"),
          new string("regional"),
          new string(""),
          nullptr)
      );

  ASSERT_EQ(
      "ecs-intl.cn-hangzhou.aliyuncs.com",
      Client::getEndpointRules(
          new string("ecs"),
          new string("cn-hangzhou"),
          new string("regional"),
          new string("intl"),
          nullptr)
  );

  ASSERT_EQ(
      "ecs.aliyuncs.com",
      Client::getEndpointRules(
          new string("ecs"),
          new string("cn-hangzhou"),
          new string("central"),
          new string(""),
          nullptr)
  );

  ASSERT_EQ(
      "ecs.aliyuncs.com",
      Client::getEndpointRules(
          new string("ecs"),
          new string("cn-hangzhou"),
          new string("central"),
          new string("public"),
          nullptr)
  );

  ASSERT_EQ(
      "ecs-intl.aliyuncs.com",
      Client::getEndpointRules(
          new string("ecs"),
          new string("cn-hangzhou"),
          new string("central"),
          new string("intl"),
          nullptr)
  );
}
