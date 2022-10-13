#include <iostream>

class FileSystem {
public:
    std::size_t numDisks() const;
};


extern FileSystem tfs;

class Directory {
public:
    Directory();
};

Directory::Directory()
{
    std::size_t disks = tfs.numDisks();

}

int main()
{
    Directory tempDir;
    return 0;

}
