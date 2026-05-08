#include "Server.hpp"

// Const
Server::Server(int _port, std::string _pass) : port(_port), password(_pass) {
    opt = true;
    shelves = std::vector<std::string>(MAX_CLIENTS, "");

    channel.push_back("genel");
    channel.push_back("sohbet");
    channel.push_back("spor");

    init_master_server();
}

// Memb
void Server::binder() {
    //bind the socket to port
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    std::cout << "Listener on port " << port << std::endl;
}

void Server::listener() {

    // start master server to listen
    start_listening();

    std::cout << "Waiting for connections..." << std::endl;
    while(true)
    {
        // init all fds to 0 to check if changed later
        init_fds();

        // check if a fd is changed
        check_new_connection();

        // check if a fd is being worked on
        check_io_operation();
    }
}

// Priv Memb
void Server::init_master_server() {
    // initialize all clients to 0 so not checked
    memset(client_socket, 0, sizeof(client_socket));

    //create a master socket 
    if((master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //set master socket to allow multiple connections ,
    if(setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 ) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
}

void Server::start_listening() {
    //try to specify maximum of 3 pending connections for the master socket
    if (listen(master_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //accept the incoming connection
    addrlen = sizeof(address);
}

void Server::init_fds() {
    int i;
    //clear the socket set
    FD_ZERO(&readfds);

    //add master socket to set
    FD_SET(master_socket, &readfds);
    max_sd = master_socket;

    //add child sockets to set
    for ( i = 0 ; i < MAX_CLIENTS ; i++)
    {
        //socket descriptor
        sd = client_socket[i];

        //if valid socket descriptor then add to read list
        if(sd > 0)
            FD_SET( sd , &readfds);

        //highest file descriptor number, need it for the select function
        if(sd > max_sd)
            max_sd = sd;
    }

    //wait for an activity on one of the sockets , timeout is NULL ,
    //so wait indefinitely
    activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);

    if ((activity < 0) && (errno!=EINTR))
        std::cerr << "select error";
}

void Server::check_new_connection() {
    //If something happened on the master socket ,
    //then its an incoming connection
    if (FD_ISSET(master_socket, &readfds))
    {
        if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        //inform user of socket number - used in send and receive commands
        std::cout << std::endl << "New connection: socket fd is " << new_socket << ", ip is : " << inet_ntoa(address.sin_addr) << ", port : " << ntohs(address.sin_port) << std::endl;

        //send new connection greeting message
        send(new_socket, "\nLutfen sifreyi giriniz\n", strlen("\nLutfen sifreyi giriniz\n"), 0);

        //add new socket to array of sockets
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            //if position is empty
            if( client_socket[i] == 0 )
            {
                client_socket[i] = new_socket;
                std::cout << "Adding to list of sockets as " << i << std::endl;

                break;
            }
        }
    }
}

void Server::check_io_operation() {
    //else its some IO operation on some other socket
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        sd = client_socket[i];
        if (FD_ISSET( sd , &readfds))
        {
            //Check if it was for closing , and also read the incoming message
            if ((valread = read( sd , buffer, 1024)) == 0)
                disconnect_user(i);

            //Handle the message that came in
            else
                handle_message(i);
        }
    }
}

void Server::disconnect_user(int i) {
    //Somebody disconnected , get 3his details and print
    getpeername(sd , (struct sockaddr*)&address , (socklen_t*)&addrlen);
    std::cout << "Host disconnected , ip " << inet_ntoa(address.sin_addr) << " , port " <<  ntohs(address.sin_port) << std::endl;

    //Close the socket and mark as 0 in list for reuse
    close( sd );
    users[i].username = "";
    users[i].nickname = "";
    users[i].connected = false;
    users[i].active_channel = -1;
    client_socket[i] = 0;
}

void Server::handle_message(int i) {
    //set the string terminating NULL byte on the end
    //of the data read
    buffer[valread] = '\0';
    if (users[i].connected == true && users[i].username != "")
    {
        // send(client_socket[i], ("\r" + std::string(1024, ' ')).c_str(), strlen(buffer) + 1, 0);
        // send(client_socket[i], "\r", 1, 0);

        bool flag = false;

        //check buffer whether consist \n
        for (int j = 0; j < valread + 1; j++)
        {
            if(buffer[j] == '\n')
                flag = true;
        }

        //if buffer haven't got /n then add collect cmd and return
        if(!flag)
        {
            collect_cmds(i, buffer);
            return ;
        }

        
        for (int j = 0; j < valread + 1; j++)
        {
            if(buffer[j] == '\n')
            {
                buffer[valread-1] = '\0';
                shelves[i] += buffer;
                for (int j = 0; j <= shelves[i].length() + valread; j++)
                {
                    buffer[j] = shelves[i][j];
                }
                
            }
        }



        if (!check_if_command(i)) {
            for (int j = 0; j < MAX_CLIENTS; j++) {
                if (users[j].active_channel == users[i].active_channel)
                {
                    send(client_socket[j], ("\033[1;31m" + users[i].nickname + "\033[0;0m: ").c_str(), users[i].nickname.length() + 15, 0);
                }
            }
            send_message_to_channel(users[i].active_channel, i);
            std::cout << users[i].username << " " << channel[users[i].active_channel] << " kanalina: \"" << buffer << "\" mesaji gonderdi." << std::endl;
        }
    }
    else if (users[i].connected == false && std::string(buffer) != password)
    {
        send(sd , "\nSifreyi yanlis girdiniz\n", strlen("\nSifreyi yanlis girdiniz\n") , 0 );
    }
    else if (users[i].connected == false && std::string(buffer) == password)
    {
        //eger kullanici adi daha önce varsa hata verecek  !!!!!
        send(sd, "\nSifre dogru, lutfen kullanici adinizi giriniz : ", strlen("\nSifre dogru, lutfen kullanici adinizi giriniz : "), 0);
        users[i].connected = true;
        users[i].nickname = "default" + std::to_string(sd);
    }
    else if (users[i].connected == true && users[i].username == "")
    {
        for (int j=0; j < MAX_CLIENTS; j++)
        {
            if(users[j].username == std::string(buffer))
            {
                send(sd , "\nBu kullaniciadi zaten kullanilmis!\n", strlen("\nBu kullaniciadi zaten kullanilmis!\n") , 0 );
                return ;
            }
        }
        
        users[i].username = std::string(buffer);
        users[i].active_channel = 0;
        send(sd , "\nBasariyla giris yaptiniz! Genel kanalina yonlendiriliyorsunuz.\n", strlen("\nBasariyla giris yaptiniz! Genel kanalina yonlendiriliyorsunuz.\n"), 0 );
        std::string join_msg = "\033[1;31m" + users[i].nickname + "\033[0m kanala giris yapti.\n";

        for (int j=0; j < MAX_CLIENTS; j++)
            if(users[j].active_channel == users[i].active_channel)
                send(client_socket[j], join_msg.c_str(), join_msg.length(), 0);

    }

    // std::cout << buffer << std::endl;
}

void Server::send_message_to_channel(int channel_id, int user_id) {
    // if (channel_id > 3)
        // error
    //send(client_socket[user_id], "\033[H", strlen("\033[H"), 0);
    for (int i = 0; i < 30; i++) {
        if (users[i].active_channel == channel_id) {               
            //send(client_socket[i], "\n", strlen("\n"), 0);
            send(client_socket[i], buffer, strlen(buffer), 0);
            send(client_socket[i], "\n", strlen("\n"), 0);
            shelves[user_id] = "";
        }
    }
}

bool Server::check_if_command(int user_id) {
    // Return false if not command
    if (buffer[0] != '/')
        return false;
    
    // Parse the command
    std::string msj = buffer;
    std::string cmd = (std::string)strtok(buffer, " ");
    char *tok = strtok(NULL, " ");

    // Store parameters of command on a vector
    std::vector<std::string> params;
    while (tok) {
        params.push_back((std::string)tok);
        tok = strtok(NULL, " ");
    }

    


    // Command found on commands map
    if (cmd == "/list")
        list(params, user_id);
    else if (cmd == "/join")
        join(params, user_id);
    else if (cmd == "/msg")
        msg(params, user_id);
    else if (cmd == "/nick")
        nick(params, user_id);
    else {
        // Command not found
        send(client_socket[user_id], "\nBilinmeyen komut\n", strlen("\nBilinmeyen komut\n"), 0);
        return true;
    }
    
    std::cout << users[user_id].username << ": " << cmd << " komutunu kullandi." << std::endl;
    return true;
}

void Server::join(std::vector<std::string> params, int user_id) {
    // if (params.size() != 1)
    //     error

    int ch_num = -1;

    if (params[0] == "genel")
        ch_num = 0;
    else if (params[0] == "sohbet")
        ch_num = 1;
    else if (params[0] == "spor")
        ch_num = 2;
    
    // if (ch_num == users[user_id].active_channel)
    //     error

    if (ch_num >= 0) {
        std::string join_msg = "\033[1;31m" + users[user_id].nickname +"\033[0m kanala giris yapti.\n";
        users[user_id].active_channel = ch_num;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (users[i].active_channel == users[user_id].active_channel)
                send(client_socket[i], join_msg.c_str(), join_msg.length(), 0);
        }
    }
    shelves[user_id] = "";
}

void Server::list(std::vector<std::string> params, int user_id) {
    // if (params.size() != 0)
    //     error

    send(sd, "\n\033[1;31mkanallar\033[0m:\n  #genel\n  #sohbet\n  #spor\n\n", strlen("\n\033[1;31mkanallar\033[0m:\n  #genel\n  #sohbet\n  #spor\n\n"), 0);
    shelves[user_id] = "";
}

void Server::msg(std::vector<std::string> params, int user_id) {
    // if (params.size() < 2)
    //     error
    // if (params[0] == users[user_id].nickname)
    //     error

    std::string str = "";
    str += "\n\033[1;31m" + users[user_id].nickname + "\033[0m bir mesaj gonderdi: ";
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (users[i].nickname == params[0]) {
            
            for (int j = 1; j < params.size(); j++)
                str += params[j];
            str += "\n";

            send(client_socket[i], str.c_str(), str.length(), 0);
        }
    }
    shelves[user_id] = "";
}

void Server::collect_cmds (int user_id, std::string parts_cmds)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (i == user_id)
        {
            shelves[i] += parts_cmds;
            shelves[i] += " ";
        }
    }
}

void Server::nick(std::vector<std::string> params, int user_id) {
    // if (params.size() != 1)
    //     error
    std::string nick_msg = "\033[1;31m" + users[user_id].nickname + "\033[0m";
    users[user_id].nickname = params[0];
    nick_msg += " nickini \033[1;31m" + users[user_id].nickname + "\033[0m olarak degistirdi!\n";
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (users[i].active_channel == users[user_id].active_channel) {
            send(client_socket[i], nick_msg.c_str(), nick_msg.length(), 0);
        }
    }
    shelves[user_id] = "";
}