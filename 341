
方法1：
c++
(from StefanPochmann)
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while(!begins.empty()){
            if(begins.top() == ends.top()){
                begins.pop();
                ends.pop();
            }
            else{
                auto x = begins.top();
                if(x->isInteger()){
                    return true;
                }
                ++begins.top();
                auto &nList = x->getList();
                begins.push(nList.begin());
                ends.push(nList.end());
            }
        }
        return false;
    }
    
private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};

方法2：
c++
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i >= 0; --i){
            st.push(&nestedList[i]);
        }
    }

    int next() {
        hasNext();
        int res = st.top()->getInteger();
        st.pop();
        return res;
    }

    bool hasNext() {
        while(!st.empty()){
            auto x = st.top();
            if(x->isInteger()){
                return true;
            }
            st.pop();
            auto &nList = x->getList();
            for(int i = nList.size()-1; i >= 0; --i){
                st.push(&nList[i]);
            }
        }
        return false;
    }
    
private:
    stack<NestedInteger*> st;
};