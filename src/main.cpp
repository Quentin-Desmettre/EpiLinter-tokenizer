#include "server.h"
#include <QCoreApplication>

int main(int ac, char **av)
{
    QCoreApplication app(ac, av);
    Server serv(8081);
    return app.exec();
}
