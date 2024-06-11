// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.endpointutil;

import com.aliyun.tea.utils.StringUtils;

public class Client {

    public static String getEndpointRules(String product, String regionId, String endpointType, String netWork, String suffix) {
        String result;
        if (!StringUtils.isEmpty(netWork) && !"public".equals(netWork)) {
            netWork = "-" + netWork;
        } else {
            netWork = "";
        }
        if (null == suffix) {
            suffix = "";
        } else {
            suffix = "-" + suffix;
        }
        if ("regional".equals(endpointType)) {
            if (StringUtils.isEmpty(regionId)) {
                throw new RuntimeException("RegionId is empty, please set a valid RegionId");
            }
            result = String.format("%s%s%s.%s.aliyuncs.com", product, suffix, netWork, regionId);
        } else {
            result = String.format("%s%s%s.aliyuncs.com", product, suffix, netWork);
        }
        return result;
    }

    /**
     * Get regionId according to productId, endpoint, endpointType, network and suffix
     * @return regionId
     */
    public static String getRegionId(String product, String endpoint, String endpointType, String network, String suffix) throws Exception {

    }
}
