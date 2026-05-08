#include <fstream>
#include <iostream>
#include <string>

std::string replace_func(std::string line, std::string str1, std::string str2)
{
    size_t i;
    std::string tmp_str;

    while(1)
    {
        i = line.find(str1);
        if(i == std::string::npos)
            break;
        tmp = line.substr(0, i);
        tmp += str2;
        tmp += line.substr(i + str1.length());
        line = tmp;
    }
    return line;
}

int main(int argc, char **argv)
{
    std::fstream    in;
    std::fstream    out;
    std::string     line;

    if(argc == 4)
    {
        in.open(argv[1], std::fstream::in);
        out.open((std::string)argv[1] + ".replace", std::fstream::out);
        if (in.fail() || out.fail())
        {
            std::cout << "couldn't open a file" << std::endl;
            return 1;
        }
        while (std::getline(in, line))
            out << replace_func(line, argv[2], argv[3]) << std::endl;
    }
    else
        std::cout << "not enough arguments." << std::endl;
    return 0;
}