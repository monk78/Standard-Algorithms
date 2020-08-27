#include <iostream>
#include <iterator> // for ostream_iterator
#include <vector>
 
int n, x;
std::vector<int> a = std::vector<int>(), b = std::vector<int>();
 
int main() {
	std::cin >> n >> x;
    for (int i = 1; i <= n && x; ++i) {
    	switch (x % 3) {
    		case 1: b.push_back(i); break;
    		case 2: a.push_back(i); break;
    	}
    	x = (x + 1)/3;
    }
    if (x) { std::cout << -1; return 0; }
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}
