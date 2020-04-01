<?php

namespace AlibabaCloud\Endpoint;

/**
 * Get endpoint
 *
 * @return string
 */
class Endpoint
{

    const ENDPOINT_TYPE_REGIONAL = "regional";
    const ENDPOINT_TYPE_CENTRAL  = "central";

    /**
     * @param string $product      required
     * @param string $regionId     optional It will be required when endpoint type is 'regional'
     * @param string $endpointType optional regional|central
     * @param string $network      optional
     *
     * @return string
     * @throws \InvalidArgumentException
     */
    public static function getEndpointRules($product, $regionId, $endpointType = "", $network = "")
    {
        if (empty($product)) {
            throw new \InvalidArgumentException("Product name cannot be empty.");
        }
        $endpoint = "<product><network>.<region_id>.aliyuncs.com";
        if ($endpointType === self::ENDPOINT_TYPE_REGIONAL) {
            if (empty($regionId)) {
                throw new \InvalidArgumentException('RegionId is empty, please set a valid RegionId');
            }
            $endpoint = str_replace("<region_id>", strtolower($regionId), $endpoint);
        } else if ($endpointType === self::ENDPOINT_TYPE_CENTRAL) {
            $endpoint = "<product><network>.aliyuncs.com";
        } else {
            throw new \InvalidArgumentException("Invalid EndpointType");
        }
        if (!empty($network) && $network !== 'public') {
            $endpoint = str_replace("<network>", "-" . $network, $endpoint);
        } else {
            $endpoint = str_replace("<network>", "", $endpoint);
        }
        return str_replace("<product>", strtolower($product), $endpoint);
    }
}
