#include "server.hpp"

Server::Server() {
    m_ipv4 = new SocketAddress("127.0.0.1:8000");
    m_serverSocket = new ServerSocket(*m_ipv4);
        
    int count = 0;
    while(true) {
        StreamSocket clientSocket = m_serverSocket->acceptConnection();
        m_stream = new SocketStreamBuf(clientSocket);
        m_buffer = new char[SIZE];    
        std::cout << "Client accepted " << ++count << "\n";
        m_stream->readFromDevice(m_buffer, SIZE);
        std::cout << "Buffer " << m_buffer << std::endl;
    }
        
}

Server::~Server() {
    m_serverSocket->close();
}
