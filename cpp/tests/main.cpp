#include "gtest/gtest.h"
#include <alibabacloud/endpoint_util.hpp>
#include <memory>

using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


TEST(tests, getEndpointRules) {
  try{
    Alibabacloud_EndpointUtil::Client::getEndpointRules(
        make_shared<string>("ecs"),
        make_shared<string>(""),
        make_shared<string>("regional"),
        make_shared<string>(),
        make_shared<string>());
    throw exception();
  } catch (runtime_error& err) {
    ASSERT_EQ(string("RegionId is empty, please set a valid RegionId"), err.what());
  }

  ASSERT_EQ(
      "ecs.cn-hangzhou.aliyuncs.com",
      Alibabacloud_EndpointUtil::Client::getEndpointRules(
          make_shared<string>("ecs"),
          make_shared<string>("CN-hangzhou"),
          make_shared<string>("regional"),
          make_shared<string>(""),
          make_shared<string>())
      );

  ASSERT_EQ(
      "ecs-intl.cn-hangzhou.aliyuncs.com",
      Alibabacloud_EndpointUtil::Client::getEndpointRules(
          make_shared<string>("ECS"),
          make_shared<string>("cn-hangzhou"),
          make_shared<string>("regional"),
          make_shared<string>("intl"),
          make_shared<string>())
  );

  ASSERT_EQ(
      "ecs.aliyuncs.com",
      Alibabacloud_EndpointUtil::Client::getEndpointRules(
          make_shared<string>("ecs"),
          make_shared<string>("cn-hangzhou"),
          make_shared<string>("central"),
          make_shared<string>(""),
          make_shared<string>())
  );

  ASSERT_EQ(
      "ecs.aliyuncs.com",
      Alibabacloud_EndpointUtil::Client::getEndpointRules(
          make_shared<string>("ecs"),
          make_shared<string>("cn-hangzhou"),
          make_shared<string>("central"),
          make_shared<string>("Public"),
          make_shared<string>())
  );

  ASSERT_EQ(
      "ecs-intl.aliyuncs.com",
      Alibabacloud_EndpointUtil::Client::getEndpointRules(
          make_shared<string>("ecs"),
          make_shared<string>("cn-hangzhou"),
          make_shared<string>("central"),
          make_shared<string>("intl"),
          make_shared<string>())
  );
}
