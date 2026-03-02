#include "core/server.hpp"
#include <iostream>
#include <thread>
#include <chrono>

namespace voidproxy::core {

Server::Server(const std::string& host, int port)
    : host_(host), port_(port), running_(false) {}

Server::~Server() {
    stop();
}

void Server::start() {
    running_ = true;
    std::cout << "[VoidProxy] Starting server on "
              << host_ << ":" << port_ << std::endl;

    run_loop();
}

void Server::stop() {
    running_ = false;
    std::cout << "[VoidProxy] Server stopped." << std::endl;
}

void Server::run_loop() {
    while (running_) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "[VoidProxy] Listening..." << std::endl;
    }
}

}