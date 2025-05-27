#include <gtest/gtest.h>
#include "ConcreteHandlerB.h"
#include "MockIHandler.h"
#include <gmock/gmock.h>

TEST(ConcreteHandlerBTest, HandleAlwaysHandles)
{
    ConcreteHandlerB handler;

    testing::internal::CaptureStdout();
    handler.handleRequest();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Handled by B\n");
}
