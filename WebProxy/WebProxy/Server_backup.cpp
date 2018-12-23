//#include <iostream>
//#include <istream>
//#include <ostream>
//#include <string>
//#include<thread>
//#include<sstream>
//
//int main(int argc, char* argv[])
//{
//    try
//    {
//        if (argc != 3)
//        {
//            std::cout << "Usage: proxy_server <port> <path-to-cache>\n";
//            std::cout << "Example:\n";
//            std::cout << "  proxy_server 8888 ./chache \n";
//            return 1;
//        }
//        // Form the request. We specify the "Connection: close" header so that the
//        // server will close the socket after transmitting the response. This will
//        // allow us to treat all data up until the EOF as the content.
//
//        std::stringstream requeststream;
//        request_stream << "GET " << argv[2] << " HTTP/1.0\r\n";
//        request_stream << "Host: " << argv[1] << "\r\n";
//        request_stream << "Accept: */*\r\n";
//        request_stream << "Connection: close\r\n\r\n";
//
//        // Send the request.
//
//        // Read the response status line. The response streambuf will automatically
//        // grow to accommodate the entire line. The growth may be limited by passing
//        // a maximum size to the streambuf constructor.
//
//        // Check that response is OK.
//        std::istream response_stream(&response);
//        std::string http_version;
//        response_stream >> http_version;
//        unsigned int status_code;
//        response_stream >> status_code;
//        std::string status_message;
//        std::getline(response_stream, status_message);
//        if (!response_stream || http_version.substr(0, 5) != "HTTP/")
//        {
//            std::cout << "Invalid response\n";
//            return 1;
//        }
//        if (status_code != 200)
//        {
//            std::cout << "Response returned with status code " << status_code << "\n";
//            return 1;
//        }
//
//        // Read the response headers, which are terminated by a blank line.
//
//        // Process the response headers.
//        std::string header;
//        while (std::getline(response_stream, header) && header != "\r")
//            std::cout << header << "\n";
//        std::cout << "\n";
//
//        // Write whatever content we already have to output.
//        if (response.size() > 0)
//            std::cout << &response;
//
//        // Read until EOF, writing data to output as we go.
//   }
//    catch (std::exception& e)
//    {
//        std::cout << "Exception: " << e.what() << "\n";
//    }
//
//    return 0;
//}