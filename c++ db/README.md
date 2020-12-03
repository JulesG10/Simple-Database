## C++ file storage




### CLI

run in the terminal
```bash
cd build && start main.exe
```

### Usage


```c
#include<iostream>
#include<vector>
#include "src/db.cpp"

int main(int argc,char** argv){
    const char* name =  "database.txt";
    DB database = DB(name);
    
    // set
    database.setItem("key", "value");
    
    // get 
    cout << database.getItem("[key]") << endl;

    // list
    std::vector<std::string> items = {};
    database.getItems(&items);

    std::vector<int>::size_type size = items.size();
    for (unsigned i = 0; i < size; i++)
    {
        cout << items[i] << endl;
    }

    // remove
    database.removeItem("[key]");

    return 0;
}
```
> Compile

Compile with MinGW
```
run.cmd
```

### Download

```bash
git clone https://github.com/JulesG10/Simple-Database.git
```
