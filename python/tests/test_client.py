import unittest

from Tea.exceptions import RequiredArgumentException
from alibabacloudendpointutil import client


class TestClient(unittest.TestCase):
    def test_get_endpoint_rules(self):
        with self.assertRaises(RequiredArgumentException):
            client.get_endpoint_rules("ecs", "", "regional", "")

        self.assertEqual("ecs.cn-hangzhou.aliyuncs.com",
                         client.get_endpoint_rules("ecs", "cn-hangzhou", "regional", ""))

        self.assertEqual("ecs-intl.cn-hangzhou.aliyuncs.com",
                         client.get_endpoint_rules("ecs", "cn-hangzhou", "regional", "intl"))

        self.assertEqual("ecs.aliyuncs.com", client.get_endpoint_rules(
            "ecs", "cn-hangzhou", "central", ""))

        self.assertEqual("ecs.aliyuncs.com", client.get_endpoint_rules(
            "ecs", "cn-hangzhou", "central", "public"))

        self.assertEqual("ecs-intl.aliyuncs.com",
                         client.get_endpoint_rules("ecs", "cn-hangzhou", "central", "intl"))
