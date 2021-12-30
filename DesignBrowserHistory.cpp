class BrowserHistory {
    string currUrl;
    stack<string> front, backward;
public:
    void clearStack(stack<string> &tmp) {
        while(!tmp.empty()) {
            tmp.pop();
        }
    }
    BrowserHistory(string homepage) {
        // Set curr URL to hompage
        currUrl = homepage;
    }
    
    void visit(string url) {
        // Clear FRONT history
        clearStack(front);
        // Push the current URL to BACKWARD history
        if(currUrl.size() > 0) {
            backward.push(currUrl);
        }
        currUrl = url;
    }
    
    string back(int steps) {
        // If the 'steps' is less than size of BACKWARD history
        if(steps < backward.size()) {
            int cnt = 0;
            while(cnt < steps) {
                // Push current URL to FRONT history
                if(currUrl.size() > 0) {
                    front.push(currUrl);
                }
                string tmp = backward.top();
                backward.pop();
                currUrl = tmp;
                ++cnt;
            }
        }
        // If the 'steps' is greater than BACKWARD history
        else {
            while(!backward.empty()) {
                // Push current URL to FRONT history
                if(currUrl.size() > 0) {
                    front.push(currUrl);
                }
                string tmp = backward.top();
                backward.pop();
                currUrl = tmp;
            }
        }
        return currUrl;
    }
    
    string forward(int steps) {
        // If the 'steps' is less than size of FRONT history
        if(steps < front.size()) {
            int cnt = 0;
            while(cnt < steps) {
                // Push current URL to BACKWARD history
                if(currUrl.size() > 0) {
                    backward.push(currUrl);
                }
                string tmp = front.top();
                front.pop();
                currUrl = tmp;
                ++cnt;
            }
        }
        // If the 'steps' is greater than FRONT history
        else {
            while(!front.empty()) {
                // Push current URL to BACKWARD history
                if(currUrl.size() > 0) {
                    backward.push(currUrl);
                }
                string tmp = front.top();
                front.pop();
                currUrl = tmp;
            }
        }
        return currUrl;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */