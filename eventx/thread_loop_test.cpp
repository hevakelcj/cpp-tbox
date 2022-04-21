#include <gtest/gtest.h>
#include "thread_loop.h"

using namespace tbox::eventx;

TEST(ThreadLoop, RunInLoop)
{
    int count = 0;
    ThreadLoop tl;
    tl.runInLoop([&]{++count;});
    tl.cleanup();
    EXPECT_EQ(count, 1);
}

TEST(ThreadLoop, RunInLoop1)
{
    int count = 0;
    {
        ThreadLoop tl;
        tl.runInLoop([&]{++count;});
    }
    EXPECT_EQ(count, 1);
}
