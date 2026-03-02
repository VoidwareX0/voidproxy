#pragma once

#include <unordered_map>
#include <functional>

namespace vp {

class EventLoop {
public:
    EventLoop();
    ~EventLoop();

    bool init();
    void add_fd(int fd);
    void remove_fd(int fd);
    void run();

private:
    int epoll_fd_;
    static const int MAX_EVENTS = 1024;
};

}