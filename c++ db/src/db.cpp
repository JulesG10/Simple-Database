#include "db.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

DB::DB(const char *filepath)
{
    this->path = filepath;
    this->patchItem();
}

std::string DB::getItem(const char *key)
{
    std::ifstream read;
    std::string line;
    std::string result;

    read.open(this->path);

    if (read.is_open())
    {
        while (getline(read, line))
        {
            if (result.size() == 0)
            {
                std::regex reg("\\[[^\\[\\]\\=]+\\]\\=");
                std::regex_replace(std::back_inserter(result), line.begin(), line.end(), reg, "");
            }
        }
        read.close();
    }
    return result;
}

void DB::removeItem(const char *key)
{
    std::ofstream write;
    std::ifstream read;
    std::string line;
    std::regex reg("\\=(.?)*");
    std::string result;
    std::vector<std::string> lines = {};

    read.open(this->path);
    if (read.is_open())
    {
        while (getline(read, line))
        {
            result = "";
            std::regex_replace(std::back_inserter(result), line.begin(), line.end(), reg, "");
            if (result != key)
            {
                lines.insert(lines.end(), line);
            }
        }
        read.close();
        write.open(this->path);
        if (write.is_open())
        {
            int i = 0;
            std::vector<int>::size_type linesSize = lines.size();
            for (unsigned i = 0; i < linesSize; i++)
            {
                write << lines[i] << "\n";
            }
            write.close();
        }
    }
}

void DB::getItems(std::vector<std::string> *items)
{
    std::ifstream read;
    std::string line;
    std::vector<std::string> key = {};
    std::string result;
    std::regex reg("\\=(.?)*");

    read.open(this->path);

    if (read.is_open())
    {
        while (getline(read, line))
        {
            result = "";
            std::regex_replace(std::back_inserter(result), line.begin(), line.end(), reg, "");
            key.insert(key.end(), line);
        }
        read.close();
    }
    *items = key;
}

void DB::setItem(const char *key, const char *value)
{
    std::ofstream write;
    write.open(this->path, std::ofstream::out | std::ofstream::app);
    if (write.is_open())
    {
        write << "[" << key << "]=" << value << "\n";
        write.close();
    }
}

void DB::patchItem()
{
    std::ifstream read;
    std::string line;
    std::regex reg("\\[[^\\[\\]\\=]+\\]\\=(.?)*");
    std::vector<std::string> lines = {};
    std::ofstream write;

    read.open(this->path);

    if (read.is_open())
    {
        while (getline(read, line))
        {
            if (!std::regex_match(line.begin(), line.end(), reg))
            {

                std::smatch match;
                const std::string s = line;
                std::regex_search(s.begin(), s.end(), match, reg);
                lines.insert(lines.end(), match[0]);
            }
            else
            {
                int i = 0;
                int same = 0;
                std::vector<int>::size_type size = lines.size();
                for (unsigned i = 0; i < size; i++)
                {
                    if (lines[i] == line)
                    {
                        same++;
                    }
                }
                if (same == 0)
                {
                    lines.insert(lines.end(), line);
                }
            }
        }
        write.open(this->path);
        if (write.is_open())
        {
            int i = 0;
            std::vector<int>::size_type linesSize = lines.size();
            for (unsigned i = 0; i < linesSize; i++)
            {
                if (lines[i] != "")
                {
                    write << lines[i] << "\n";
                }
            }
            write.close();
        }
    }
}

DB::~DB()
{
    this->patchItem();
}