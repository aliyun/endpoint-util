package com.aliyun.endpointutil;

import org.junit.Assert;
import org.junit.Test;

public class ClientTest {
    @Test
    public void getEndpointRulesTest() throws Exception {
        Assert.assertEquals("cs.region.aliyuncs.com", Client.getEndpointRules("cs", "region",
                "regional", null, null));
        Assert.assertEquals("cs-suffix-test.aliyuncs.com", Client.getEndpointRules("cs", "test",
                "public", "test", "suffix"));

        try {
            Client.getEndpointRules("regional", null,
                    "regional", "cs", "");
            Assert.fail();
        } catch (Exception e) {
            Assert.assertEquals("RegionId is empty, please set a valid RegionId", e.getMessage());
        }
    }
}
