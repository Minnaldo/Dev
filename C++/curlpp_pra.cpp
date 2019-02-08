#include <curlpp/Easy.cpp>
#include <curlpp/Exception.cpp>
#include <curlpp/Options.cpp>
#include <curlpp/cUrLpp.cpp>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    try
    {
        curlpp::Cleanup cleaner;
        curlpp::Easy request;

        request.setOpt(new curlpp::options::Url(url));
        request.setOpt(new curlpp::options::Verbose(true));

        list<string> header;
        header.push_back("Content-Type: application/octet-steam");

        request.setOpt(new curlpp::options::HttpHeader(header));
        request.setOpt(new curlpp::options::PoistFields("abcd"));
        request.setOpt(new curlpp::options::PostFieldSize(5));

        request.perform();
    }
    catch (curlpp::LogicError &e)
    {
        cout << e.what() << endl;
    }
    catch (curlpp::RuntimeError &e)
    {
        cout << e.what() << endl;
    }

    return EXIT_SUCCESS;
}