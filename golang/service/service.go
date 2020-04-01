// This file is auto-generated, don't edit it. Thanks.
/**
 * Get endpoint
 * @return string
 */
package service

import (
	"fmt"
	"strings"
)

func GetEndpointRules(product string, regionId string, endpointType string, network string) (_result string, _err error) {
	if endpointType == "regional" {
		if regionId == "" {
			_err = fmt.Errorf("RegionId is empty, please set a valid RegionId")
			return "", _err
		}
		_result = strings.Replace("<product><network>.<region_id>.aliyuncs.com", "<region_id>", regionId, 1)
	} else {
		_result = "<product><network>.aliyuncs.com"
	}
	_result = strings.Replace(_result, "<product>", strings.ToLower(product), 1)
	if network == "" || network == "public" {
		_result = strings.Replace(_result, "<network>", "", 1)
	} else {
		_result = strings.Replace(_result, "<network>", "-"+network, 1)
	}
	return _result, nil
}
