#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

void cards(std::string input_filename, std::string output_filename){
    std::fstream input_file(input_filename, std::ios::in);
    if(!input_file){
        throw std::runtime_error("Error opening input file");
    }
    int n;
    input_file >> n;
    std::vector<int> cards(n);
    for(int i = 0; i < n; i++){
        input_file >> cards[i];
    }
    input_file.close();
    std::sort(cards.begin(), cards.end(), std::greater<>());
    int max_sum = std::accumulate(cards.begin(), cards.begin() + n / 2, 0);
    int min_sum = std::accumulate(cards.begin() + n / 2, cards.end(), 0);
    std::fstream output_file(output_filename, std::ios::out);
    if(!output_file){
        throw std::runtime_error("Error opening output file");
    }
    output_file << max_sum - min_sum;
    output_file.close();
}

int main() {
    cards("input.txt", "output.txt");
    return 0;
}
