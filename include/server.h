#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QWebSocketServer>

class Server : public QObject
{
    Q_OBJECT
private:
    QWebSocketServer *m_pWebSocketServer;
    bool _isDebug;

public:
    explicit Server(quint16 port, bool isDebug, QObject *parent = nullptr);

public slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();

signals:

};

#endif // SERVER_H
