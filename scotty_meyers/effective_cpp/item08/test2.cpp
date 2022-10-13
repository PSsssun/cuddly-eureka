#include <iostream>
#include <vector>


class DBConnection {
public:
    static DBConnection create();
    DBConnection()
    {
        a=1.0;
    }
    void close();
private:

    int a;
};
DBConnection DBConnection::create()
{
    std::cout << "DBConnection created invoked" << std::endl;
    DBConnection dbc;
    return dbc;
}


class DBConn {
public:
    DBConn(DBConnection a)
    {
        std::cout << "hey" << std::endl;
        db = a;
    }
    ~DBConn()
    {
        db.close();
    }
private:
    DBConnection db;

};


int main()
{
    {
        DBConn dbc(DBConnection::create());
    
    }

    return 0;

}
