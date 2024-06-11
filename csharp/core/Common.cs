using System;

namespace AlibabaCloud.EndpointUtil
{
    public class Common
    {
        /// <summary>
        /// Get endpoint
        /// </summary>
        /// <param name="endpointType"></param>
        /// <param name="network"></param>
        /// <param name="regionId"></param>
        /// <param name="product"></param>
        /// <returns>endpoint string</returns>
        public static string GetEndpointRules(string product, string regionId, string endpointType, string network, string suffix)
        {
            string result = string.Empty;
            product = product == null ? "" : product;
            if (endpointType == "regional")
            {
                if (string.IsNullOrEmpty(regionId))
                {
                    throw new ArgumentException("RegionId is empty, please set a valid RegionId", "RegionId");
                }
                result = "<product><suffix><network>.<region_id>.aliyuncs.com".Replace("<region_id>", regionId);
            }
            else
            {
                result = "<product><suffix><network>.aliyuncs.com";
            }

            result = result.Replace("<product>", product.ToLower());

            if (string.IsNullOrEmpty(network) || network == "public")
            {
                result = result.Replace("<network>", "");
            }
            else
            {
                result = result.Replace("<network>", "-" + network);
            }

            if(string.IsNullOrEmpty(suffix))
            {
                result = result.Replace("<suffix>", "");
            }
            else
            {
                result = result.Replace("<suffix>", "-" + suffix);
            }

            return result;
        }

        /**
         * Get regionId according to productId, endpoint, endpointType, network and suffix
         * @return regionId
         */
        public static string GetRegionId(string product, string endpoint, string endpointType, string network, string suffix)
        {
            throw new NotImplementedException();
        }
    }
}
