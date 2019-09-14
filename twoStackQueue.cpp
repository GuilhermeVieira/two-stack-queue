#include <iostream>
#include <stack>
#include <string>

#define DIE(...) { \
        std::cerr << __VA_ARGS__ << std::endl; \
        std::exit (EXIT_FAILURE); \
}

class TwoStackQueue
{
    private: 
        std::stack<int> pushStack;
        std::stack<int> popStack;
        void insertAtBottom(std::stack<int> &st, int x);
        void reverse(std::stack<int> &st);
        void inverseSwap(std::stack<int> &st1, std::stack<int> &st2);
    public:
        void push(int);
        int pop();
        int get();
        bool isEmpty();
};

void TwoStackQueue::insertAtBottom(std::stack<int> &st, int x) {
    if (st.size() == 0) {
        st.push(x);
    }
    else {
        int y = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(y);
    }
}

void TwoStackQueue::reverse(std::stack<int> &st) {
    if (st.size() > 0) {
        int top = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st, top);
    }
}

void TwoStackQueue::inverseSwap(std::stack<int> &st1, std::stack<int> &st2)
{
    st1.swap(st2);
    reverse(st1);
    reverse(st2);
}

void TwoStackQueue::push(int n)
{
    if (!popStack.empty())
        inverseSwap(pushStack, popStack);
    pushStack.push(n);
}

int TwoStackQueue::pop()
{
    if (!pushStack.empty())
        inverseSwap(popStack, pushStack);
    if (!popStack.empty()) {
        int ret = popStack.top();
        popStack.pop();
        return ret;
    }
    DIE("Error: Tried to pop from an empty queue.")
}

int TwoStackQueue::get() {
    if (!pushStack.empty())
        inverseSwap(popStack, pushStack);
    if (!popStack.empty())
        return popStack.top();
    DIE("Error: Tried to get from an empty queue.")
}

bool TwoStackQueue::isEmpty()
{
    if (pushStack.empty() && popStack.empty())
        return true;
    return false;
}

int main()
{
    TwoStackQueue queue;
    if (!queue.isEmpty())
        DIE("ERROR: Queue should be empty")
    queue.push(1);
    std::cout << "Pushed " << 1 << std::endl;
    if (queue.isEmpty())
        DIE("ERROR: Queue should not be empty")
    std::cout << "Popping " << queue.get() << std::endl;
    queue.pop();
    if (queue.isEmpty())
        std::cout << "Pop operation was successful and queue is empty" << std::endl;
    else
        DIE("ERROR: Item should have been popped from queue but it was not")
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
        std::cout << "Pushed " << i << std::endl;
    }
    for (int i = 0; i < 2; ++i) {
        std::cout << "Popping " << queue.get() << std::endl;
        queue.pop();
    }
    queue.push(5);
    std::cout << "Pushed " << 5 << std::endl;
    while (!queue.isEmpty()) {
        std::cout << "Popping " << queue.get() << std::endl;
        queue.pop();
    }

    return 0;
}