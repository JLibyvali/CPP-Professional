#include <boost/asio.hpp>
#include <iostream>
#include <string>

using acceptor_type = boost::asio::ip::tcp::acceptor;
using endpoint_type = boost::asio::ip::tcp::endpoint;
using socket_type   = boost::asio::ip::tcp::socket;

class Tcp_clnt
{
public:

    explicit Tcp_clnt(boost::asio::io_context &io, endpoint_type _end) : m_ep(_end), m_sock(io) {}

    void run();

private:

    endpoint_type m_ep;
    socket_type   m_sock;
};

void Tcp_clnt::run()
{

    // Like POSIX connect()
    m_sock.connect(m_ep);
    std::cout << "Connect to " << m_sock.remote_endpoint().address() << ": " << m_sock.remote_endpoint().port()
              << std::endl;

    // Create a string for buffer
    std::string str;
    str.resize(256);
    
    m_sock.receive(boost::asio::buffer(str));
    std::cout << "message from server: " << str << std::endl;
}

int main()
{

    boost::asio::io_context io;
    endpoint_type           end{boost::asio::ip::address::from_string("127.0.0.1"), 9001};

    std::cout << "Init client" << std::endl;
    try
    {
        Tcp_clnt client(io, end);
        client.run();

        io.run();
    }
    catch (std::exception &ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}