
from Tea.exceptions import RequiredArgumentException


class Client:
    @staticmethod
    def get_endpoint_rules(product, regionId, endpointType, network):
        result = ""
        product = product or ""
        network = network or ""
        if endpointType == "regional":
            if regionId is None or regionId == "":
                raise RequiredArgumentException(
                    "RegionId is empty, please set a valid RegionId")
            result = "<product><network>.<region_id>.aliyuncs.com".replace(
                "<region_id>", regionId)
        else:
            result = "<product><network>.aliyuncs.com"

        result = result.replace("<product>", product.lower())
        if network == "" or network == "public":
            result = result.replace("<network>", "")
        else:
            result = result.replace("<network>", "-"+network)

        return result
