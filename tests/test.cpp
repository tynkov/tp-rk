#include <gtest/gtest.h>
#include "ConcreteHandlerA.h"
#include "ConcreteHandlerB.h"

TEST(HandlerTest, ADelegatesToB) {
	ConcreteHandlerA handlerA;
	ConcreteHandlerB handlerB;
	handlerA.setHandler(&handlerB);

	::testing::internal::CaptureStdout();
	handlerA.handleRequest();
	std::string output = ::testing::internal::GetCapturedStdout();

	EXPECT_NE(output.find("Handled by B"), std::string::npos);
}

TEST(HandlerTest, BHandlesItself) {
	ConcreteHandlerB handlerB;

	::testing::internal::CaptureStdout();
	handlerB.handleRequest();
	std::string output = ::testing::internal::GetCapturedStdout();

	EXPECT_NE(output.find("Handled by B"), std::string::npos);
}
