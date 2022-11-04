#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QWebSocketServer>

class Server : public QObject
{
    Q_OBJECT
private:
    QWebSocketServer *m_pWebSocketServer;

public:
    explicit Server(quint16 port, QObject *parent = nullptr);

public slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();

signals:

};

#endif // SERVER_H
