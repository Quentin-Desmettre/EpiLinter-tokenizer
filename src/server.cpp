#include "server.h"
#include <QWebSocket>
#include "tokenizer.h"
#include <iostream>

Server::Server(quint16 port, bool isDebug, QObject *parent)
    : QObject{parent},
      m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"),
                                                  QWebSocketServer::NonSecureMode, this)),
      _isDebug(isDebug)
{
    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
       connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
               this, &Server::onNewConnection);
       std::cout << "Server started listening on " << m_pWebSocketServer->serverPort() << std::endl;
    } else
        std::cout << "error while starting server: " << m_pWebSocketServer->errorString().toStdString() << std::endl;
}

void Server::onNewConnection()
{
    if (_isDebug)
        std::cout << "New connection" << std::endl;
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &Server::processTextMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &Server::socketDisconnected);
}

void Server::processTextMessage(QString message)
{
    if (_isDebug)
        std::cout << "Received text message" << std::endl;
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
