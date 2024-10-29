#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <exception>
#include <iostream>
#include <vector>

using acceptor_type = boost::asio::ip::tcp::acceptor;
using endpoint_type = boost::asio::ip::tcp::endpoint;
using socket_type   = boost::asio::ip::tcp::socket;

class Tcp_serv
{
public:

    Tcp_serv(boost::asio::io_context &_io, endpoint_type &_serv) : m_tcp_acceptor(_io, _serv) {}

    void run(boost::asio::io_context &io);

private:

    acceptor_type            m_tcp_acceptor;
    std::vector<socket_type> socks;
};

void Tcp_serv::run(boost::asio::io_context &io)
{
    // Blocking like POSIX accept()
    while (1)
    {
        socks.push_back(socket_type{io});
        m_tcp_acceptor.accept(socks.back());

        std::cout << "Client connected addr " << socks.back().remote_endpoint().address().to_string() << std::endl;
        socks.back().send(boost::asio::buffer("Hello ASIO world \n"));
    }
}

int main()
{

    boost::asio::io_context io;
    endpoint_type           end{boost::asio::ip::address_v4(), 9001};
    std::cout << "Init server addr: " << end.address() << std::endl;

    try
    {
        Tcp_serv server(io, end);
        server.run(io);

        io.run();
    }
    catch (std::exception &ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}