# ft_irc

<image src="imgs/image1.png" />
<image src="imgs/image2.png" />
<image src="imgs/image3.png" />
<image src="imgs/image4.png" />
<image src="imgs/image5.png" />
<image src="imgs/image6.png" />
<image src="imgs/image7.png" />

<image src="ft_irc/image.png" />

It is about internet relay chat server through socket programming.

Program run with port and password parameter.

There are 4 different irc command.

- /join #channel -> goes to channel
- /nick #new_nick -> renew nick
- /msg @nickname message -> it send a private message to a user who specify nickname in line
- /list -> shows all available channels

**Class functions**

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
