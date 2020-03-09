#include "client.hpp"

Client::Client() {
    m_ipv4 = new SocketAddress("127.0.0.1:8000");
    m_clientSocket = new StreamSocket(*m_ipv4);
    
    m_buffer = "Give me some information";
    m_clientSocket -> sendBytes(m_buffer, 50);
    
    m_clientSocket->connect(*m_ipv4);

  
}

Client::~Client() {
    m_clientSocket->close();
}
