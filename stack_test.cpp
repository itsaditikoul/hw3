#include "stack.h"
#include <iostream>
#include <string>

int main() {
    Stack<std::string> s;
    std::cout << std::boolalpha << "empty? " << s.empty() << "\n";
    s.push("a");
    s.push("b");
    std::cout << "size: " << s.size() << ", top: " << s.top() << "\n";
    s.pop();
    std::cout << "size: " << s.size() << ", top: " << s.top() << "\n";

    // Uncomment to see exception:
    // s.pop(); s.pop(); std::cout << s.top() << "\n";

    return 0;
}
