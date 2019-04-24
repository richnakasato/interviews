class TriggerService {
public:
    TriggerService() {};
    ~TriggerService() {};

    bool addRequest();

private:

    int max_size_;
    int curr_size_;

    void spawnProcess();
    void rejectProcess();

};


int main()
{
    return 0;
}
