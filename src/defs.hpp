#ifndef DEFS_HPP
#define DEFS_HPP

struct Temps {
    char* bed;
    char* nozzle;
};

struct Positions {
    char* x;
    char* y;
    char* z;
};

struct Times {
    char* ellapse;
    char* remaining;
};

#endif