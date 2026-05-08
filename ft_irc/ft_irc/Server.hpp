#pragma once

#include <string>
#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h>   //close 
#include <arpa/inet.h>    //close 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <sys/time.h>   //FD_SET, FD_ISSET, FD_ZERO macros 
#include <iostream>
#include <vector>

#define MAX_CLIENTS 30

#include "User.hpp"

class Server {
private:
    std::vector<std::string> channel;

    std::vector<std::string> shelves;
    const int port;
    std::string password;
    char buf[50];
    int opt;
    int master_socket, addrlen, new_socket, client_socket[30], max_clients, activity, valread, sd;
    int max_sd;
    User users[30];
    struct sockaddr_in address;
    char buffer[1025];  //data buffer of 1K
    fd_set readfds; //set of socket descriptors


    void send_message_to_channel(int channel_id, int user_id);
    void handle_message(int i);
    void disconnect_user(int i);
    void check_io_operation();
    void check_new_connection();
    void init_fds();
    void start_listening();
    void init_master_server();
    bool check_if_command(int i);

    void join(std::vector<std::string> params, int i);
    void list(std::vector<std::string> params, int i);
    void msg(std::vector<std::string> params, int i);
    void nick(std::vector<std::string> params, int i);

public:
    // Cons
    Server(int _port, std::string _pass);

    // Oper

    // Memb
    void binder();
    void listener();
    void collect_cmds (int user_id, std::string parts_cmds);
};