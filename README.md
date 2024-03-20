## c-with-sqlite/ Ubuntu OS
### Install GCC Compiler in Linux:
> $ sudo apt install build-essential
### Check GCC installation:
> $ gcc --version
### Install SQLite3 on Linux:
> $ sudo apt update
> $ sudo apt install sqlite3
### Check SQLite3 installation:
> $ sqlite3 --version
### Create Database:
> $ sqlite3 phonebook.db
### Create Table:
> $ sqlite3
> $ sqlite3> CREATE TABLE phones (id integer NOT NULL, name text NOT NULL, mobile text NOT NULL, PRIMARY KEY (id AUTOINCREMENT));
### Insert into table:
> $ sqlite3> INSERT INTO phones VALUES (1, "Mohammad", "09126168235");
### Check list of data:
> $ sqlite> .open phonebook.db
> $ sqlite> select * from phones;
> 1|Mohammad|09126168235
### Compile code with C Compiler:
> $ gcc phonebook.c -lsqlite3 -o phonebook
## Run executable program:
> $ ./phonebook


