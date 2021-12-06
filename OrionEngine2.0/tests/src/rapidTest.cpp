#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>

RC_GTEST_PROP(MyTestCase,
    copyOfStringIsIdenticalToOriginal,
    (const std::string& str)) {
    const auto strCopy = str;
    RC_ASSERT(strCopy != str);
}