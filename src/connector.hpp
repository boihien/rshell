#ifndef _CONNECTOR_HPP_
#define _CONNECTOR_HPP_
#include <string>
#include "base.hpp"


class AND: public Base{
    public:
        AND();
        virtual void evaluate();
        virtual char * parse(string input);
        bool succeeded;
        bool keepexecuting;
};

class OR: public Base{
    public:
        OR();
        virtual void evaluate();
        virtual char * parse(string input);
        bool succeeded;
        bool keepexecuting;
};

class SEMICOLON: public Base{
    public:
        SEMICOLON() : Base(){ }
        virtual void evaluate();
        virtual char * parse(string input);
        bool succeeded;
        bool keepexecuting;
};

#endif
