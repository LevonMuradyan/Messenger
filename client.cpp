#include "client.hpp"

Client::Client() {
    m_ipv4 = new SocketAddress("127.0.0.1:8000");
    m_clientSocket = new StreamSocket(*m_ipv4);
    m_clientSocket->connect(*m_ipv4);
    
    m_stream = new SocketStreamBuf(*m_clientSocket);
    m_stream->writeToDevice("Give me some information", 50);    
}

Client::~Client() {
    m_clientSocket->close();
}
