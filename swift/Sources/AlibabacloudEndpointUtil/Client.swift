import Foundation
import Tea

open class Client {
    public static func getEndpointRules(_ product: String?, _ regionId: String?, _ endpointType: String?, _ network: String?, _ suffix: String?) throws -> String {
        var endpoint: String = ""
        if product == nil || product!.isEmpty {
            throw TeaError("ProductId is empty, please set a valid ProductId")
        }
        if endpointType == "regional" {
            if regionId == nil || regionId!.isEmpty {
                throw TeaError("RegionId is empty, please set a valid RegionId")
            }
            endpoint = "<product><suffix><network>.<region_id>.aliyuncs.com"
            endpoint = endpoint.replacingOccurrences(of: "<region_id>", with: regionId!)
        } else {
            endpoint = "<product><suffix><network>.aliyuncs.com"
        }
        endpoint = endpoint.replacingOccurrences(of: "<product>", with: product!)
        if network == nil || network!.isEmpty || network == "public" {
            endpoint = endpoint.replacingOccurrences(of: "<network>", with: "")
        } else {
            endpoint = endpoint.replacingOccurrences(of: "<network>", with: "-\(network!)")
        }
        if suffix == nil || suffix!.isEmpty {
            endpoint = endpoint.replacingOccurrences(of: "<suffix>", with: "")
        } else {
            endpoint = endpoint.replacingOccurrences(of: "<suffix>", with: "-\(suffix!)")
        }
        return endpoint
    }

    public static func getRegionId(_ product: String?, _ endpoint: String?, _ endpointType: String?, _ network: String?, _ suffix: String?) throws -> String {
        throw Tea.TeaError("Un-implemented")
    }
}
