#include <iostream>
#include <stack>
#include <string>

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::stack<int> num;
    std::string inst;
    int n;
    int size = 0;
    for(int i = 0 ; i < N; i++){
        std::cin >> inst;

        if(inst == "push"){
            std::cin >> n;
            num.push(n);
            size++;
        }
        else if(inst == "pop"){
            if(size==0){
                std::cout << "-1\n";
            }
            else{
                std::cout << num.top() << "\n";
                num.pop();
                size--;
            }
        }
        else if(inst == "size"){
            std::cout << size << "\n";
        }
        else if(inst == "empty"){
            if(size == 0){
                std::cout << "1\n";
            }
            else{
                std::cout <<"0\n";
            }
        }
        else if(inst == "top"){
            if(size == 0){
                std::cout << "-1\n";
            }
            else{
                std::cout << num.top() << "\n";
            }
        }
    }
}