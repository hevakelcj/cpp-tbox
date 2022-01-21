#include <thread>
#include <gtest/gtest.h>
#include "pid_file.h"

using namespace tbox::util;

TEST(PidFile, base)
{
    const char *pid_file = "/tmp/test.pid";
    ::unlink(pid_file);
    {
        PidFile pid;
        ASSERT_TRUE(pid.lock(pid_file));

        EXPECT_EQ(::access(pid_file, R_OK), 0); //! 文件应该存在
    }

    EXPECT_EQ(::access(pid_file, R_OK), -1);    //! 文件应该打不开，因为已经删除了
    EXPECT_EQ(errno, ENOENT);
}

TEST(PidFile, duplicate)
{
    const char *pid_file = "/tmp/test.pid";
    ::unlink(pid_file);
    {
        PidFile pid1;
        ASSERT_TRUE(pid1.lock(pid_file));

        if (fork() == 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            PidFile pid2;
            ASSERT_FALSE(pid2.lock(pid_file));
            return;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
        EXPECT_EQ(::access(pid_file, R_OK), 0); //! 文件应该存在
    }

    EXPECT_EQ(::access(pid_file, R_OK), -1);    //! 文件应该打不开，因为已经删除了
    EXPECT_EQ(errno, ENOENT);
}