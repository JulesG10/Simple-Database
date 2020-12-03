#include <iostream>
#include "src/db.cpp"
#include "src/utils.cpp"
using namespace std;

void list(DB database)
{
    std::vector<std::string> items = {};
    database.getItems(&items);
    std::vector<int>::size_type size = items.size();
    for (unsigned i = 0; i < size; i++)
    {
        cout << items[i] << endl;
    }
}

void remove(DB database)
{
    std::string key;
    cout << "[KEY]>";
    std::getline(std::cin, key);
    database.removeItem(key.data());
}

void get(DB database)
{
    std::string key;
    cout << "[KEY]>";
    std::getline(std::cin, key);
    cout << database.getItem(key.data()) << endl;
}

void set(DB database)
{
    std::string key;
    cout << "[KEY]>";
    std::getline(std::cin, key);

    std::string value;
    cout << "[VALUE]>";
    std::getline(std::cin, value);
    database.setItem(key.data(), value.data());
}

void Database(const char *name)
{
    DB database = DB(name);
    while (true)
    {
        std::string line;
        cout << ">";
        std::getline(std::cin, line);
        switch (str2int(line.data()))
        {
        case str2int("set"):
            set(database);
            break;
        case str2int("remove"):
            remove(database);
            break;
        case str2int("list"):
            list(database);
            break;
        case str2int("get"):
            get(database);
            break;
        case str2int("exit"):
            exit(0);
            break;
        case str2int("help"):
            cout << "set, remove, get, list, exit, help" << endl;
            break;
        default:
            cout << "Command no found" << endl;
            break;
        }
    }
}

int main(int argc, const char *argv[])
{
    std::string name;
    std::string delimiter = ".";
    std::cout << "Enter your database name: ";
    std::getline(std::cin, name);
    if (name.find(delimiter) != std::string::npos)
    {
        Database(name.data());
    }
    else
    {
        name += ".txt";
        Database(name.data());
    }
    return 0;
}