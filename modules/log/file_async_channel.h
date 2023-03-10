#ifndef TBOX_LOG_FILE_ASYNC_CHANNEL_H_20220412
#define TBOX_LOG_FILE_ASYNC_CHANNEL_H_20220412

#include "async_channel.h"

#include <vector>

namespace tbox {
namespace log {

class FileAsyncChannel : public AsyncChannel {
  public:
    virtual ~FileAsyncChannel() override;

  public:
    bool initialize(const std::string &log_path, const std::string &log_prefix);
    void cleanup();

    void setFileMaxSize(size_t max_size) { file_max_size_ = max_size; }
    std::string currentFilename() const { return log_filename_; }

  protected:
    virtual void onLogBackEnd(const void *data_ptr, size_t data_size) override;
    bool checkAndCreateLogFile();

  private:
    std::string log_prefix_;
    std::string log_path_;
    size_t file_max_size_ = (1 << 20);  //!< 默认文件大小为2MB
    pid_t pid_ = 0;

    std::string filename_prefix_;
    std::string sym_filename_;
    std::string log_filename_;

    int fd_ = -1;
    size_t total_write_size_ = 0;

    std::vector<char> buffer_;
};

}
}

#endif //TBOX_LOG_FILE_ASYNC_CHANNEL_H_20220412
