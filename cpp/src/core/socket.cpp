#include "core/socket.hpp"

#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace vp {

Socket::Socket() : fd_(-1) {}

Socket::~Socket() {
    close();
}

bool Socket::create() {
    fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd_ < 0) {
        perror("socket");
        return false;
    }

    int opt = 1;
    setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    return true;
}

bool Socket::bind(int port) {
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (::bind(fd_, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return false;
    }

    return true;
}

bool Socket::listen(int backlog) {
    if (::listen(fd_, backlog) < 0) {
        perror("listen");
        return false;
    }

    return true;
}

int Socket::accept() {
    sockaddr_in client_addr{};
    socklen_t len = sizeof(client_addr);

    int client_fd = ::accept(fd_, (sockaddr*)&client_addr, &len);
    if (client_fd < 0) {
        perror("accept");
        return -1;
    }

    return client_fd;
}

void Socket::close() {
    if (fd_ >= 0) {
        ::close(fd_);
        fd_ = -1;
    }
}

}