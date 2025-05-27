#pragma once
#include "IHandler.h"
#include <gmock/gmock.h>

class MockIHandler : public IHandler {
public:
    MOCK_METHOD(bool, canhandle, (), (const, override));
    MOCK_METHOD(void, setHandler, (IHandler *), (override));
    MOCK_METHOD(void, handleRequest, (), (const, override));
};
