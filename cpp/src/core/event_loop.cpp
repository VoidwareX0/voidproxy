#include "core/event_loop.hpp"

#include <unistd.h>
#include <sys/epoll.h>
#include <iostream>
#include <cstring>

namespace vp {

EventLoop::EventLoop() : epoll_fd_(-1) {}

EventLoop::~EventLoop() {
    if (epoll_fd_ >= 0)
        close(epoll_fd_);
}

bool EventLoop::init() {
    epoll_fd_ = epoll_create1(0);
    if (epoll_fd_ < 0) {
        perror("epoll_create1");
        return false;
    }
    return true;
}

void EventLoop::add_fd(int fd) {
    epoll_event ev{};
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = fd;

    if (epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &ev) < 0) {
        perror("epoll_ctl ADD");
    }
}

void EventLoop::remove_fd(int fd) {
    epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, fd, nullptr);
    close(fd);
}

void EventLoop::run() {
    epoll_event events[MAX_EVENTS];

    while (true) {
        int n = epoll_wait(epoll_fd_, events, MAX_EVENTS, -1);

        if (n < 0) {
            perror("epoll_wait");
            continue;
        }

        for (int i = 0; i < n; ++i) {
            int fd = events[i].data.fd;

            char buffer[4096];
            ssize_t bytes = read(fd, buffer, sizeof(buffer));

            if (bytes <= 0) {
                remove_fd(fd);
                continue;
            }

            std::cout << "[Voidproxy] Received "
                      << bytes << " bytes from FD "
                      << fd << std::endl;
        }
    }
}

}