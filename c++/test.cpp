#include <iostream>
#include <string>
#include <glog/logging.h>

int main(int argc, char** argv) {
	FLAGS_log_dir = "/home/yuri/yuri/logs";
    google::InitGoogleLogging(argv[0]);

	LOG(INFO) << "yuri is yes";
	google::ShutdownGoogleLogging();//程序完结时必须有，否则会内存泄露
    return 0;
}