class MyStack {
private:
    queue<int> q;
    int last_element = 0;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        // last pushed element should be the top
        last_element = x;
    }
    
    int pop() {
        // get size of current queue
        int size = q.size();
        if (size != 0){
            // leave last two elements
            while(size > 2){
                q.push(q.front());
                q.pop();
                size--;
            }
            // second last element is the new top now
            last_element = q.front();
            q.push(q.front());
            q.pop();
            // remove and return last element
            int result = q.front();
            q.pop();
            return result;
        }else{
            return 0;
        }
    }
    
    int top() {
        return last_element;
    }
    
    bool empty() {
        return q.empty();
    }
};
