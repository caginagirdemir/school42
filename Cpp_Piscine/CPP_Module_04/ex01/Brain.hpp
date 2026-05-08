#pragma once

#include <string>
#include <iostream>

class Brain
{
    public:
    // Constructors
        Brain();
        Brain(const Brain &copy);

    // Deconstructors
        virtual ~Brain();
    
    // Overloaded Operators
        Brain &operator=(const Brain &src);
    
    // Get Funcs
        const std::string getIdea(size_t i)const;
        const std::string *getIdeaAddress(size_t i)const;
    // Set Funcs
        void setIdea(size_t i, std::string idea);
    
    private:
        std::string _ideas[100];

};