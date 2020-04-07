import Client from '../src/client';
import assert from 'assert';
import 'mocha';

describe('Endpoint Util', function () {
    it('getEndpoint should ok', function () {
        assert.strictEqual(Client.getEndpointRules("ecs", "cn-hangzhou", "regional", "", ""), "ecs.cn-hangzhou.aliyuncs.com");
        assert.strictEqual(Client.getEndpointRules("ecs", "cn-hangzhou", "central", "intl", "test"), "ecs-test-intl.aliyuncs.com");
        assert.strictEqual(Client.getEndpointRules("ecs", "cn-hangzhou", "central", "public", "test"), "ecs-test.aliyuncs.com");
        assert.throws(() => {
            Client.getEndpointRules("ecs", "", "regional", "", "");
        }, /RegionId is empty, please set a valid RegionId/)
    });

});
