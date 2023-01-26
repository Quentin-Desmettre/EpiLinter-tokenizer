#include "server.h"
#include <QCoreApplication>

int main(int ac, char **av)
{
    QCoreApplication app(ac, av);
    Server serv(8081, ac > 1 && av[1] == (std::string)("--debug"));
    return app.exec();
}
