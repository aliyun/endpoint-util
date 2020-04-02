using System;

using AlibabaCloud.EndpointUtil;

using Xunit;

namespace tests
{
    public class CommonTest
    {
        [Fact]
        public void Test_GetEndpointRules()
        {
            Assert.Throws<ArgumentException>(() => { Common.GetEndpointRules("ecs", "", "regional", ""); });

            string endpoint = Common.GetEndpointRules("ecs", "cn-hangzhou", "regional", "");
            Assert.Equal("ecs.cn-hangzhou.aliyuncs.com", endpoint);

            endpoint = Common.GetEndpointRules("ecs", "cn-hangzhou", "regional", "intl");
            Assert.Equal("ecs-intl.cn-hangzhou.aliyuncs.com", endpoint);

            endpoint = Common.GetEndpointRules("ecs", "cn-hangzhou", "central", "");
            Assert.Equal("ecs.aliyuncs.com", endpoint);

            endpoint = Common.GetEndpointRules("ecs", "cn-hangzhou", "central", "public");
            Assert.Equal("ecs.aliyuncs.com", endpoint);

            endpoint = Common.GetEndpointRules("ecs", "cn-hangzhou", "central", "intl");
            Assert.Equal("ecs-intl.aliyuncs.com", endpoint);
        }
    }
}
