#include <iostream>
#include <memory>
#include <string.h>

class BorrowableItem {
public:
    void CheckOut();
};

void BorrowableItem::CheckOut() {
    std::cout << "Call BorrowableItem::CheckOut()\n";
}

class ElectronicGadget {
private:
    bool CheckOut() const; // perform self-test return whether tese succeeds

};

bool ElectronicGadget::CheckOut() const {
    std::cout << "Call ElectronicGadget::CheckOut()\n";
    return true;
}

class MP3Player :
    public BorrowableItem,
    public ElectronicGadget
{};


class IPerson {
public:
    virtual ~IPerson() {}
    virtual std::string name() const = 0;
    virtual std::string birth_date() const = 0;

};


class DatabaseID : public IPerson {
public:
    DatabaseID(int id) : id_(id), name_("Bob"), birth_date_("0927") {}
    virtual ~DatabaseID() {}

    virtual std::string name() const {
        return name_;
    }

    virtual std::string birth_date() const {
        return birth_date_;
    }

    void set_name(const std::string& str) {
        name_ = std::move(const_cast<std::string&>(str));
    }

    void set_birth_date(const std::string& str) {
        birth_date_ = std::move(const_cast<std::string&>(str));
    }
private:
    int id_;
    std::string name_;
    std::string birth_date_;

};

DatabaseID AskUserForDatabaseID() {
    DatabaseID data(100);
    return data;
}

std::shared_ptr<IPerson> MakePerson(DatabaseID personIdentifier) {
    auto data = new DatabaseID(100);
    if (data == nullptr) return nullptr;
    data->set_birth_date(personIdentifier.birth_date());
    data->set_name(personIdentifier.name());
    std::shared_ptr<IPerson> ptr(data);
    return ptr;

}


class PersonInfo {
public:
    explicit PersonInfo(DatabaseID pid) : pid_(pid) {}
    virtual ~PersonInfo() {}
    virtual const char* the_name() const;
    virtual const char* the_birth_date() const;
private:
    virtual const char* ValueDelimOpen() const;
    virtual const char* ValueDelimClose() const;
    DatabaseID pid_;

};

const char* PersonInfo::ValueDelimOpen() const 
{
    return "[";
}

const char* PersonInfo::ValueDelimClose() const {
    return "]";
}

const int kMaxFormattedFieldValueLength = 50;
const char* PersonInfo::the_name() const 
{
    static char value[kMaxFormattedFieldValueLength];

    strcpy(value, ValueDelimOpen());

    strcat(value, pid_.name().c_str());

    strcat(value, ValueDelimClose());
    return value;
}

const char* PersonInfo::the_birth_date() const {
    static char value[kMaxFormattedFieldValueLength];

    strcpy(value, ValueDelimOpen());
    strcat(value, pid_.birth_date().c_str());
    strcat(value, ValueDelimClose());
    return value;

}


const std::string hearts = u8"\U00002665";

class CPerson : public IPerson, private PersonInfo {
public:
    explicit CPerson(DatabaseID pid) : PersonInfo(pid) {}
    virtual std::string name() const 
    {
        return PersonInfo::the_name();
    }

    virtual std::string birth_date() const 
    {
        return PersonInfo::the_birth_date();
    }

private:
    const char* ValueDelimOpen() const {return hearts.c_str();}
    const char* ValueDelimClose() const {return hearts.c_str();}


};

int main()
{
    std::cout << "Item 40: use multiple inheritance judiciously.\n";
    {
        MP3Player mp;
        mp.BorrowableItem::CheckOut();
    }

    DatabaseID id(AskUserForDatabaseID());
    std::shared_ptr<IPerson> pp(MakePerson(id));

    std::cout << "Name: " << pp->name() << " Birthday: " << pp->birth_date() << "\n";

    CPerson cp(id);
    std::cout << "Name: " << cp.name() << "Birthday: " << cp.birth_date() << "\n";

    return 0;
}
