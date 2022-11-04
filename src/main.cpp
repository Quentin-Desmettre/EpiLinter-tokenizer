#include "server.h"
#include <QApplication>

int main(int ac, char **av)
{
    QApplication app(ac, av);
    Server serv(8081);
    return app.exec();
}
