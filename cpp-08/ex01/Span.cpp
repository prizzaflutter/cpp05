#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : maxSize(0) {}
Span::Span(unsigned int n) : maxSize(n) {}
Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers){}
Span& Span::operator=(const Span& other) {
    if (this != &other){
        this->maxSize = other.maxSize;
        this->numbers = other.numbers;
    }
    return *this;
}
Span::~Span(){}

void Span::addNumber(int n){
    if (numbers.size() > maxSize){
        throw SpanFullException();
    }
    numbers.push_back(n);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2){
        throw NotEnoughNumbersException();
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = std::numeric_limits<int>::max();

    for (size_t i = 0; i < sortedNumbers.size(); ++i){
        int currentSpan = sortedNumbers[i] - sortedNumbers[i - 1];
        if (currentSpan < minSpan){
            minSpan = currentSpan;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (numbers.size() < 2) throw NotEnoughNumbersException();
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    return max - min;
}

const char* Span::SpanFullException::what() const throw() {
        return "Error: Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
        return "Error: Not enough numbers";
}