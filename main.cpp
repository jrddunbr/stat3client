/*
 * File:   main.cpp
 * Author: jared
 *
 * Created on March 19, 2016, 2:32 AM
 *
 * Edited May 24, 2016 at 12:58 PM EST
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

class udp_module {
private:
    string address;
    int port;
    struct sockaddr_in server;
    int sock;
public:
    udp_module(string, int);
    void send_udp(string);
    void close_udp() {
        close(sock);
    };
};

udp_module::udp_module(string ip, int port) {
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        cerr << "socket\n";
        exit(0);
    }
    memset((char *) &server, 0, sizeof (server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_aton(ip.c_str(), &server.sin_addr) == 0) {
        cout << "inet_aton() failed\n";
        exit(0);
    }
}

void udp_module::send_udp(string data) {
    if (sendto(sock, data.data(), data.size(), 0, (struct sockaddr *) &server, sizeof (server)) == -1) {
        cerr << "packet\n";
        exit(0);
    }
}

void sendKey(udp_module connection, string key, string data) {
    string send = key + "|" + data;
    connection.send_udp(send);
}

/*
 *
 */
int main(int argc, char** argv) {
    if(argc !=  5) {
        cerr << "Error, not enough arguments!\n";
        cout << "\n  Usage:\n\n./[executable] host port key value\n";
        for(int i = 0; i < argc; i++) {
            cout << argv[i] << " ";
        }
        cout << "\n";
        exit(1);
    }

    string key = argv[3];
    string data = argv[4];

    string host = argv[1];
    int port = atoi(argv[2]);
    udp_module udp(host, port);
    sendKey(udp, key, data);
    udp.close_udp();
    return 0;
}
