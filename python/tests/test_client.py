import unittest

from alibabacloud_endpoint_util.client import Client


class TestClient(unittest.TestCase):
    def test_get_endpoint_rules(self):
        with self.assertRaises(RuntimeError):
            Client.get_endpoint_rules("ecs", "", "regional", "")

        self.assertEqual("ecs.cn-hangzhou.aliyuncs.com",
                         Client.get_endpoint_rules("ecs", "cn-hangzhou", "regional", ""))

        self.assertEqual("ecs-intl.cn-hangzhou.aliyuncs.com",
                         Client.get_endpoint_rules("ecs", "cn-hangzhou", "regional", "intl"))

        self.assertEqual("ecs.aliyuncs.com", Client.get_endpoint_rules(
            "ecs", "cn-hangzhou", "central", ""))

        self.assertEqual("ecs.aliyuncs.com", Client.get_endpoint_rules(
            "ecs", "cn-hangzhou", "central", "public"))

        self.assertEqual("ecs-intl.aliyuncs.com",
                         Client.get_endpoint_rules("ecs", "cn-hangzhou", "central", "intl"))
