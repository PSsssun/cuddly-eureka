#include <iostream>
#include <cstddef>


class FileSystem {
public:
    std::size_t numDisks() const;

};

FileSystem& tfs()
{
    static FileSystem fs;
    return fs;
}

class Directory {
public:
    Directory();

private:
    std::size_t disks;
};

Directory::Directory()
{
    std::size_t disks = tfs().numDisks();
}

Directory& tempDir()
{
    static Directory td;
    return td;
}

int main()
{
    Directory a = tempDir();
    return 0;
}



