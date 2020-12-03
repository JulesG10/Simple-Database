#include "utils.hpp"
#include <iostream>
#include <cstring>
#include <string>

int StrToInterger(const char *str)
{
     std::string Resfinal;
     int i = 0;
     while (str[i])
     {
          if ((int)str[i] > 0)
          {
               Resfinal = Resfinal + std::to_string((int)str[i]);
               i++;
          }
          else
          {
               break;
          }
     }
     return atoi(Resfinal.data());
}

// https://stackoverflow.com/questions/16388510/evaluate-a-string-with-a-switch-in-c
constexpr unsigned int str2int(const char *str, int h = 0)
{
     return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}