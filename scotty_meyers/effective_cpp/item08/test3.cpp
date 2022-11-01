#include <iostream>


DBConn::~DBConn()
{
    try {db.close();}
    catch (...) {
        std::abort();
    }

}
