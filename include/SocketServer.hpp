/*
** EPITECH PROJECT, 2022
** EpiLinter-tokenizer
** File description:
** SocketServer.hpp
*/

#ifndef SERVER_H
#define SERVER_H

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <iostream>

typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

// pull out the type of messages sent by our config
typedef server::message_ptr message_ptr;

class SocketServer {
public:
    SocketServer(bool debug = false);
    int run(uint16_t port);

    static bool _debug;
};


#endif // SERVER_H
