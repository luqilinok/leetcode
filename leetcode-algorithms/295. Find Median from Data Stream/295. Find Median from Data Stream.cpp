/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return small.size() > large.size() ? small.top() : 0.5 *(small.top() - large.top());
    }

private:
    priority_queue<long> small, large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
