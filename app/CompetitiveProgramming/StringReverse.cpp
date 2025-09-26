
#include <string>
#include <iostream>
#include <vector>

// Head recursion: work done AFTER recursion
std::string reverse_head_recursion(const std::string& name) {

    if(name.size() == 0) return name;

    std::string partialWord = reverse_head_recursion(name.substr(1));

    std::string result = partialWord + name.at(0); // compute afetr resursion

    return result;
}

// Tail recursion: work done DURING recursion
std::string reverse_tail_recursion(const std::string& name, const std::string& accumulator = "") {

    if(name.size() == 0) return accumulator;

    std::string partialWord = name.substr(1);

    return reverse_tail_recursion(partialWord,  name.at(0) + accumulator); // compute During recursion
}


// Backtracking: generate all permutations
void permute(std::string& s, int start, std::vector<std::string>& results) {

    if (start == s.size() - 1) {
        results.push_back(s);
        return;
    }

    for (int i = start; i < s.size(); ++i) {
        // choice: swap current index with start
        std::swap(s[start], s[i]);

        // recurse on the remaining substring
        permute(s, start + 1, results);

        // undo choice (backtrack)
        std::swap(s[start], s[i]);
    }
}



int main() {
    /*
        std::string word = "Jovian";
        std::cout << "Head recursion: " << reverse_head_recursion(word) << std::endl;
        std::cout << "Tail recursion: " << reverse_tail_recursion(word) << std::endl;
    */

    std::string word = "Jovian";
    std::vector<std::string> results;
    permute(word, 0, results);
    
    std::cout << "Backtracking (permutations):\n";
    for (const auto& p : results) {
        std::cout << p << '\n';
    }



    return 0;
}