package service

import (
	"testing"

	"github.com/alibabacloud-go/tea/utils"
)

func Test_GetEndpointRules(t *testing.T) {
	endpoint, err := GetEndpointRules("ecs", "", "regional", "", "")
	utils.AssertEqual(t, "", endpoint)
	utils.AssertEqual(t, "RegionId is empty, please set a valid RegionId", err.Error())

	endpoint, err = GetEndpointRules("ecs", "cn-hangzhou", "regional", "", "")
	utils.AssertNil(t, err)
	utils.AssertEqual(t, "ecs.cn-hangzhou.aliyuncs.com", endpoint)

	endpoint, err = GetEndpointRules("ecs", "cn-hangzhou", "central", "intl", "test")
	utils.AssertNil(t, err)
	utils.AssertEqual(t, "ecs-test-intl.aliyuncs.com", endpoint)
}
