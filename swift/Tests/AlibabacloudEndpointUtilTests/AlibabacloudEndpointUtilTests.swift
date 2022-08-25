import XCTest
import Tea
@testable import AlibabacloudEndpointUtil

final class ClientTests: XCTestCase {
    func testGetEndpointRules() throws {
        var endpoint: String = ""
        do {
            try Client.getEndpointRules("", "cn-hangzhou", "regional", "", "")
            assert(false)
        } catch {
            if (error is TeaError) {
                let err: TeaError = error as! TeaError
                XCTAssertEqual("ProductId is empty, please set a valid ProductId", err.getMessage())
            } else {
                assertionFailure()
            }
        }
        do {
            try Client.getEndpointRules("ecs", "", "regional", "", "")
            assert(false)
        } catch {
            if (error is TeaError) {
                let err: TeaError = error as! TeaError
                XCTAssertEqual("RegionId is empty, please set a valid RegionId", err.getMessage())
            } else {
                assertionFailure()
            }
        }
        endpoint = try Client.getEndpointRules("ecs", "cn-hangzhou", "regional", "", "")
        XCTAssertEqual("ecs.cn-hangzhou.aliyuncs.com", endpoint)
        endpoint = try Client.getEndpointRules("ecs", "", "center", "", "")
        XCTAssertEqual("ecs.aliyuncs.com", endpoint)
        endpoint = try Client.getEndpointRules("ecs", "cn-hangzhou", "regional", "intl", "test")
        XCTAssertEqual("ecs-test-intl.cn-hangzhou.aliyuncs.com", endpoint)
        endpoint = try Client.getEndpointRules("ecs", "cn-hangzhou", "center", "intl", "test")
        XCTAssertEqual("ecs-test-intl.aliyuncs.com", endpoint)
    }

    static var allTests = [
        ("testGetEndpointRules", testGetEndpointRules),
    ]
}
