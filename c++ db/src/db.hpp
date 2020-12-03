#pragma once

#ifndef DEF_DB
#define DEF_DB

#include <iostream>
#include <fstream>
#include <vector>

class DB
{
public:
    DB(const char *filepath);
    ~DB();
    void setItem(const char *key, const char *value);
    std::string getItem(const char *key);
    void getItems(std::vector<std::string> *items);
    void removeItem(const char *key);

private:
    std::string path;
    void patchItem();
};

#endif