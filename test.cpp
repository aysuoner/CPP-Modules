#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span(unsigned int N) : N(N) {}

    void addNumber(int num) {
        if (numbers.size() == N) {
            throw std::runtime_error("Span is full");
        }
        numbers.push_back(num);
    }

    template<typename InputIterator>
    void fill_all(InputIterator begin, InputIterator end) {
        unsigned int num_to_add = std::min((unsigned int)std::distance(begin, end), N - numbers.size());
        if (num_to_add == 0) {
            throw std::runtime_error("Span is full");
        }
        numbers.insert(numbers.end(), begin, begin + num_to_add);
    }

    int shortestSpan() {
        if (numbers.size() < 2) {
            throw std::runtime_error("Not enough numbers in Span");
        }
        std::sort(numbers.begin(), numbers.end());
        int min_span = numbers[1] - numbers[0];
        for (unsigned int i = 2; i < numbers.size(); i++) {
            int span = numbers[i] - numbers[i-1];
            if (span < min_span) {
                min_span = span;
            }
        }
        return min_span;
    }

    int longestSpan() {
        if (numbers.size() < 2) {
            throw std::runtime_error("Not enough numbers in Span");
        }
        std::sort(numbers.begin(), numbers.end());
        return numbers[numbers.size()-1] - numbers[0];
    }
};

int main(void) {
    // Color codes
    std::string white_code = "\001\033[1m\033[37m\002";
    std::string reset_code = "\001\033[0;0m\002";
	
    std::cout << white_code << "\n----addNumber() TEST-----\n" << reset_code << std::endl;
    Span sp1(15);
    sp1.addNumber(10);
    sp1.addNumber(20);
    sp1.addNumber(30);
    sp1.addNumber(40);

    std::cout << white_code << "\n----fill_all() TEST-----\n" << reset_code << std::endl;
    std::vector<int> v1 = {50, 60, 70, 80, 90, 100};
    sp1.fill_all(v1.begin(), v1.end());

    std::cout << white_code << "\n----range TEST-----\n" << reset_code << std::endl;
    std::cout << "shortest: " << sp1.shortestSpan() << std::endl;
    std::cout << "longest: " << sp1.longestSpan() << std::endl;

    Span sp2(23);
    try {
        std::cout << "longest2: " << sp2.longestSpan() << std::endl;
        std::cout << "shortest2: " << sp2.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
