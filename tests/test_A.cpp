#include <gtest/gtest.h>
#include "ConcreteHandlerA.h"
#include "MockIHandler.h"
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::Exactly;

TEST(ConcreteHandlerATest, HandleWhenCanHandle)
{
    ConcreteHandlerA handler;

    EXPECT_CALL(handler, canhandle())
        .Times(Exactly(1))
        .WillOnce(Return(true));	//переопределяем canhandle()

    testing::internal::CaptureStdout();
    handler.handleRequest();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Handled by A\n");
}

TEST(ConcreteHandlerATest, HandleWhenCannotHandleCallsNext)
{
    auto mockSuccessor = new MockIHandler;
    EXPECT_CALL(*mockSuccessor, handleRequest()).Times(1);

    ConcreteHandlerA handler;
    handler.setHandler(mockSuccessor);

    EXPECT_CALL(handler, canhandle())
        .Times(Exactly(1))
        .WillOnce(Return(false));

    testing::internal::CaptureStdout();
    handler.handleRequest();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Cannot be Handled by A") != std::string::npos);
}
