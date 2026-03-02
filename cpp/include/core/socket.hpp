#pragma once

#include <string>

namespace vp {

class Socket {
public:
    Socket();
    ~Socket();

    bool create();
    bool bind(int port);
    bool listen(int backlog = 128);
    int  accept();

    void close();

private:
    int fd_;
};

}