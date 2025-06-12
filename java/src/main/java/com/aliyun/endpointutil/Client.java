// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.endpointutil;

public class Client {

    public static String getEndpointRules(String product, String regionId, String endpointType, String netWork, String suffix) {
        String result;
        if (!isEmpty(netWork) && !"public".equals(netWork)) {
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
            if (isEmpty(regionId)) {
                throw new RuntimeException("RegionId is empty, please set a valid RegionId");
            }
            result = String.format("%s%s%s.%s.aliyuncs.com", product, suffix, netWork, regionId);
        } else {
            result = String.format("%s%s%s.aliyuncs.com", product, suffix, netWork);
        }
        return result;
    }
    
    private static boolean isEmpty(final CharSequence cs) {
        return cs == null || cs.length() == 0;
    }
}
