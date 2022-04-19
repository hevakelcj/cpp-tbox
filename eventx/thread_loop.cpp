#include "thread_loop.h"

namespace tbox {
namespace eventx {

ThreadLoop::ThreadLoop() :
    sp_loop_(event::Loop::New()),
    thread_(std::bind(&ThreadLoop::threadProc, this))
{ }

ThreadLoop::~ThreadLoop()
{
    if (is_running)
        sp_loop_->runInLoop([=] { sp_loop_->exitLoop(); });
    thread_.join();
    delete sp_loop_;
}

void ThreadLoop::threadProc()
{
    is_running = true;
    sp_loop_->runLoop();
    is_running = false;
}

}
}
