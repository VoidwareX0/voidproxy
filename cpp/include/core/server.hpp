#pragma once

#include <string>
#include <memory>

namespace voidproxy::core {

class Server {
public:
    Server(const std::string& host, int port);
    ~Server();

    void start();
    void stop();

private:
    std::string host_;
    int port_;
    bool running_;

    void run_loop();
};

}