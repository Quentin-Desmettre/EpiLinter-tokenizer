/*
** EPITECH PROJECT, 2022
** EpiLinter-tokenizer
** File description:
** main.cpp
*/

#include "SocketServer.hpp"

int main(int ac, char **av)
{
    SocketServer server(ac == 2 && (std::string)(av[1]) == "--debug");

    try {
        return server.run(8081);
    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
        return 84;
    } catch (...) {
        std::cout << "other exception" << std::endl;
        return 84;
    }
}
