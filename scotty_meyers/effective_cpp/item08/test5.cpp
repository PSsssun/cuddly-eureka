class DBConn {
public:
    void close()
    {
        db.close();
        closed = true;
    }

    ~DBConn()
    {
        if (!closed) {
            try {
                db.close();
            }
            catch () {
                //record
            }
        }
    }

private:
    DBConnection db;
    bool closed;
};
