

DBConn::~DBConn()
{
    try {db.close();}
    catch () {
        //record fail of invoking close
    }

}
