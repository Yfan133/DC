#include"common.h"
class MaxQueue
{
public:
    MaxQueue()
    {

    }

    int max_value()
    {
        if (que_.size() == 0)
            return -1;
        return dq_.front();
    }

    void push_back(int value)
    {
        while (!dq_.empty() && value > dq_.back())
            dq_.pop_back();
        dq_.push_back(value);
        que_.push(value);
    }

    int pop_front()
    {
        if (que_.size() == 0)
            return -1;
        int tmp = que_.front();
        que_.pop();
        if (tmp == dq_.front())
            dq_.pop_front();
        return tmp;
    }
private:
    queue<int> que_;
    deque<int> dq_;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */