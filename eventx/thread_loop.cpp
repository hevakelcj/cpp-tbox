#include "thread_loop.h"

namespace tbox {
namespace eventx {

ThreadLoop::ThreadLoop() :
    sp_loop_(event::Loop::New()),
    thread_(std::bind(&ThreadLoop::threadProc, this))
{ }

ThreadLoop::~ThreadLoop()
{
    cleanup();
    delete sp_loop_;
}

bool ThreadLoop::isRunning() const
{
    return sp_loop_->isRunning();
}

bool ThreadLoop::isInLoopThread() const
{
    return sp_loop_->isInLoopThread();
}

void ThreadLoop::runInLoop(const Func &func)
{
    return sp_loop_->runInLoop(func);
}

void ThreadLoop::threadProc()
{
    is_running = true;
    sp_loop_->runLoop();
    is_running = false;
}

void ThreadLoop::cleanup()
{
    if (is_cleanup)
        return;

    if (is_running)
        sp_loop_->runInLoop([=] { sp_loop_->exitLoop(); });
    thread_.join();
    is_cleanup = true;
}

}
}
