// 看了hint..在每个节点中加入当前的最小值
// 别人都是用的vector或者干脆就是用的两个stack，我为什么要用链表。。
class MinStack {

private:
    struct StackNode{
        int elem;
        int minelem;
        StackNode *prev;
        StackNode(int val) : elem(val), minelem(val), prev(NULL){}
    };
    StackNode *head;
    int size;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        head = NULL;
        size = 0;
    }
    
    void push(int x) {
        if(size == 0){
            head = new StackNode(x);
        }
        else{
            auto ptmp = head;
            head = new StackNode(x);
            head->minelem = head->minelem < ptmp->minelem ? head->minelem : ptmp->minelem;
            head->prev = ptmp;
        }
        ++size;
    }
    
    void pop() {
        if(size == 0) return;
        auto ptmp = head;
        head = head->prev;
        delete ptmp;
        --size;
    }
    
    int top() {
        return head->elem;
    }
    
    int getMin() {
        return head->minelem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */class MinStack {

private:
    struct StackNode{
        int elem;
        int minelem;
        StackNode *prev;
        StackNode(int val) : elem(val), minelem(val), prev(NULL){}
    };
    StackNode *head;
    int size;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        head = NULL;
        size = 0;
    }
    
    void push(int x) {
        if(size == 0){
            head = new StackNode(x);
        }
        else{
            auto ptmp = head;
            head = new StackNode(x);
            head->minelem = head->minelem < ptmp->minelem ? head->minelem : ptmp->minelem;
            head->prev = ptmp;
        }
        ++size;
    }
    
    void pop() {
        if(size == 0) return;
        auto ptmp = head;
        head = head->prev;
        delete ptmp;
        --size;
    }
    
    int top() {
        return head->elem;
    }
    
    int getMin() {
        return head->minelem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
