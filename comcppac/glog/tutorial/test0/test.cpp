#include <glog/logging.h>

int main(int argc, char* argv[]) {
    // Initialize Google's logging library.
   // google::InitGoogleLogging(argv[0]);
    int num_cookies = 6;
    LOG(INFO) << "Found" << num_cookies << " cookies";
    VLOG_IF(1, (num_cookies > 3))
        << "I'm printed when size is more than 3";
    return 0;
}