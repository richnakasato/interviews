class Set
{
public:
    Set(int* memory, int num) {};

    bool add(int value) {};
    bool remove(int value) {};
    bool exists(int value) {};
private:
    int* memory_;
    int size_;
    int tail_;

    bool valid() {};
};

int main()
{
    return 0;
}
