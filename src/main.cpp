/*
** EPITECH PROJECT, 2022
** EpiLinter-tokenizer
** File description:
** main.cpp
*/

#include "SocketServer.hpp"

void redirect_output()
{
    int dev_null = open("/dev/null", O_RDONLY | O_WRONLY);
    dup2(dev_null, 1);
    dup2(dev_null, 2);
}

int main(int ac, char **av)
{
    bool debug = (ac == 2 && (std::string)(av[1]) == "--debug");
    SocketServer server(debug);

    if (!debug)
        redirect_output();
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
