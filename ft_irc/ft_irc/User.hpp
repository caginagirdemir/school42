#pragma once

#include <string>

class User {
private:
    
public:
    std::string username, nickname;
    int active_channel;
    bool connected;
    User();
};