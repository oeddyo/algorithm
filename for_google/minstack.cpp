#include <iostream>
#include <stack>



using namespace std;


struct minstack{
        stack<int> element;
        stack<int> _min_stack;
        void pop(){
            cout<<"pop "  ;  
            if(element.empty()){
                        printf("Error\n");
                        return ;
                }else{
                    cout<<element.top()<<endl;    
                    if(element.top()==_min_stack.top()){
                            _min_stack.pop();
                        }
                        element.pop();
                }
        }
        void push(int k){
            cout<<"push "<<k<<endl;    
            if(_min_stack.empty() || k<=_min_stack.top()){
                        _min_stack.push(k);
                }
                element.push(k);        
        }
        int get_min(){
                if(!_min_stack.empty())
                    return _min_stack.top();        
        }
};




int main(){
    struct minstack my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(4);
    cout<<my_stack.get_min()<<endl;    
    my_stack.push(4);
    my_stack.push(0);
    cout<<my_stack.get_min()<<endl;
    my_stack.push(3);
    my_stack.pop();
    cout<<my_stack.get_min()<<endl;
    my_stack.pop();
    cout<<my_stack.get_min()<<endl;
    return 0;
}
