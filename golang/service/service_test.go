package service

import (
	"testing"

	"github.com/alibabacloud-go/tea/tea"
	"github.com/alibabacloud-go/tea/utils"
)

func Test_GetEndpointRules(t *testing.T) {
	endpoint, err := GetEndpointRules(tea.String("ecs"), tea.String(""), tea.String("regional"), tea.String(""), tea.String(""))
	utils.AssertEqual(t, "", tea.StringValue(endpoint))
	utils.AssertEqual(t, "RegionId is empty, please set a valid RegionId", err.Error())

	endpoint, err = GetEndpointRules(tea.String("ecs"), tea.String("cn-hangzhou"), tea.String("regional"), tea.String(""), tea.String(""))
	utils.AssertNil(t, err)
	utils.AssertEqual(t, "ecs.cn-hangzhou.aliyuncs.com", tea.StringValue(endpoint))

	endpoint, err = GetEndpointRules(tea.String("ecs"), tea.String("cn-hangzhou"), tea.String("central"), tea.String("intl"), tea.String("test"))
	utils.AssertNil(t, err)
	utils.AssertEqual(t, "ecs-test-intl.aliyuncs.com", tea.StringValue(endpoint))
}
