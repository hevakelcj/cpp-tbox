#ifndef TBOX_EVENT_THREAD_LOOP_H_20220419
#define TBOX_EVENT_THREAD_LOOP_H_20220419

#include <thread>
#include <tbox/event/loop.h>

namespace tbox {
namespace eventx {

class ThreadLoop {
  public:
    ThreadLoop();
    ~ThreadLoop();

  public:
    event::Loop *loop() const { return sp_loop_; }

  protected:
    void threadProc();

  private:
    event::Loop *sp_loop_ = 0;
    std::thread thread_;
    bool is_running = false;
};

}
}

#endif //TBOX_EVENT_THREAD_LOOP_H_20220419
