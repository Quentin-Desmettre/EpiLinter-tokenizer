/*
** EPITECH PROJECT, 2022
** EpiLinter-tokenizer
** File description:
** SocketServer.cpp
*/

#include "SocketServer.hpp"
#include "Tokenizer.hpp"

bool SocketServer::_debug = false;

void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg)
{
    if (SocketServer::_debug) {
        std::cout << "on_message called with hdl: " << hdl.lock().get()
                  << " and message: "               << msg->get_payload()
        << std::endl;
    }

    try {
        std::cout << Tokenizer::getTokens(msg->get_payload()) << std::endl;
        s->send(hdl, Tokenizer::getTokens(msg->get_payload()), msg->get_opcode());
    } catch (websocketpp::exception const & e) {
        if (SocketServer::_debug) {
            std::cout << "Echo failed because: " << "(" << e.what() << ")" << std::endl;
        }
    }
}

SocketServer::SocketServer(bool debug)
{
    SocketServer::_debug = debug;
}

int SocketServer::run(uint16_t port)
{
    server echo_server;

    try {
        // Set logging settings
        echo_server.set_access_channels(websocketpp::log::alevel::all);
        echo_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize Asio
        echo_server.init_asio();

        // Register our message handler
        echo_server.set_message_handler(bind(&on_message,&echo_server,::_1,::_2));

        // Listen on port 9002
        echo_server.listen(port);

        // Start the server accept loop
        echo_server.start_accept();

        // Start the ASIO io_service run loop
        if (_debug)
            std::cout << "Server started listening on port " << port << std::endl;
        return echo_server.run();
    } catch (websocketpp::exception const & e) {
        if (_debug)
            std::cout << e.what() << std::endl;
        return 84;
    } catch (...) {
        if (_debug)
            std::cout << "other exception" << std::endl;
        return 84;
    }
}

