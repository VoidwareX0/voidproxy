#include "core/server.hpp"
#include "core/event_loop.hpp"

namespace {
    vp::Server* server = nullptr;
    vp::EventLoop* loop = nullptr;
}

extern "C" void vp_start(int port) {
    server = new vp::Server(port);

    if (!server->start())
        return;

    loop = new vp::EventLoop();
    loop->init();
    loop->run(*server);
}