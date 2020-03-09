#include "server.hpp"
#include <string>

Server::Server() {
    m_ipv4 = new SocketAddress("127.0.0.1:8000");
    m_serverSocket = new ServerSocket(*m_ipv4);
        
    int count = 0;
    while(true) {
        StreamSocket clientSocket = m_serverSocket->acceptConnection();
        char* buffer = new char[50];    
        std::cout << "Client accepted " << ++count << "\n";
        int k = clientSocket.receiveBytes(buffer, 50);
        std::cout << "Buffer " << k << " " << (std::string)buffer << std::endl;
        delete buffer;
    }
        
}

Server::~Server() {
    m_serverSocket->close();
}
