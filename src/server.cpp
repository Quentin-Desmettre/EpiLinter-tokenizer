#include "server.h"
#include <QWebSocket>
#include "tokenizer.h"

Server::Server(quint16 port, QObject *parent)
    : QObject{parent},
      m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"),
                                                  QWebSocketServer::NonSecureMode, this))
{
    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
       connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
               this, &Server::onNewConnection);
       qDebug() << "Server started listening on " << m_pWebSocketServer->serverPort() << "\n";
   }
    else
        qDebug() << "error while starting server: " << m_pWebSocketServer->errorString();
}

void Server::onNewConnection()
{
    qDebug() << "New connection" << "\n";
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &Server::processTextMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &Server::socketDisconnected);
}

void Server::processTextMessage(QString message)
{
    qDebug() << "Received text message" << "\n";
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
        pClient->sendTextMessage(Tokenizer::getTokens(message));
}

void Server::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
        pClient->deleteLater();
}
