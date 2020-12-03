import re as rgx
import time as t

class DB:
    name = ""
    file = None
    arr  = []
    bad  = []
    key  = None

    def __init__(self, name,key):
        self.name = name
        self.key = key
        self.file = self.makeFile()
        self.readFile()

    def insert(self, data):
        self.arr.insert(0,data)
        return 0

    def delete(self, idE):
        try:
            del self.arr[idE]
        except:
            print('')
        return 0

    def get(self,idE):
        return self.arr[idE]
    def getAll(self):
        return self.arr
    def save(self):
        nb=0
        f = open(self.file.name, "a")
        f.truncate(0)
        for item in self.arr:
            nb+=1
            data =  '['+str(nb)+':"'+str(item)+'"]\n'
            f.write(data)
        f.close()
        return self.arr
    
    def makeFile(self):
        f = open(self.name+".txt", "a")
        return f

    def readFile(self):
        for el in open(self.file.name,'r').read().split('\n'):
            if rgx.match(r"\[([0-9]+)\s*\:\s*(\"[a-zA-Z0-9]*\")\]",el):
                el=rgx.sub(r"\[([0-9]+)\s*\:\s*\"",'',el)
                el=rgx.sub(r"\"\]",'',el)
                self.arr.insert(0,el)
            else:
                self.bad.insert(0,el)  
        return [self.arr,self.bad]

def init():
    name=str(input('Enter your database name >>> '))
    db = DB(name,"")
    return db


def Execcommand(name,db):
    if name == "insert":
        value=str(input('value >>>'))
        db.insert(value)
        print('Success to insert your value')
    elif name == "delete":
        value=str(input('value >>>'))
        db.delete(int(value))
        print('Success to delete your value')
    elif name == "get":
        value=str(input('value >>>'))
        print(db.get(int(value)))
    elif name ==  "getAll":
        print(db.getAll())
    elif name == "save":
        db.save()
        print('Success to save your database')
    elif name == "insertAll":
        value=str(input('text >>>'))
        nb= int(input('number >>>'))
        start = 0
        if isinstance(nb, int):
            while start < nb:
                start += 1
                db.insert(value)
            print("Success to insert yours values, don't forget to save !")
        else:
            print('Fail to insert your number is not available')
    return 0

def action(db):
    ps=0
    while ps<100:
        ps += 10
        t.sleep(0.1)
        printProgressBar(ps,100)
    print('')
    print('(insert, insertAll, delete, get, getAll, save, exit)')
    while True:
        command = str(input('command >>> '))
        if command == "insert":
            Execcommand("insert",db)
        elif command == "delete":
            Execcommand("delete",db)
        elif command == "get":
            Execcommand("get",db)
        elif command == "getAll":
            Execcommand("getAll",db)
        elif command == "save":
            Execcommand('save',db)
        elif command == "exit":
            exit(0)
        elif command == "insertAll":
            Execcommand("insertAll",db)
        else:
            print('Invalid command line')


def printProgressBar (iteration, total, prefix = '', suffix = '', decimals = 1, length = 100, fill = '█', printEnd = "\r"):
    percent = ("{0:." + str(decimals) + "f}").format(100 * (iteration / float(total)))
    filledLength = int(length * iteration // total)
    bar = fill * filledLength + '-' * (length - filledLength)
    print(f'\r{prefix} |{bar}| {percent}% {suffix}', end = printEnd)
    if iteration == total: 
        print()      
           

if __name__ == "__main__":
    db=init()
    action(db)
