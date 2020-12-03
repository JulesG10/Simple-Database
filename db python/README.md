## Simple database in python



### Usage

run in the terminal
```bash
py db.py
```
or use it in your code
```python
import DB

db = DB('database_name','key') # TODO add usage for crypting file with the  key 

db.insert('coucou') # insert at pos 0

db.insert('test') # insert at pos 1

db.delete(1) # delete id 1

db.save() # save your data in the file

print(db.getAll()) # all elements

print(db.get(0)) # one element

```
You can also download db.zip to get the exe

### Download

```bash
git clone https://github.com/JulesG10/Simple-Database.git
```