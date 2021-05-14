#include <cmath>
#include "BFC.hpp"

// BFC Commands Definitions : 

char BF_Commands::right_cell = '>';
char BF_Commands::left_cell = '<';
char BF_Commands::add = '+';
char BF_Commands::sub = '-';
char BF_Commands::print = '.';
char BF_Commands::loop_start = '[';
char BF_Commands::loop_end = ']';

// BFC Public Functions :
BFC::BFC()
{
    this->_given_str = "";
}

BFC::~BFC()
{
}

void BFC::set_string(std::string givenStr) {
    this->_given_str = givenStr;
}

void BFC::set_string_getter() {
    std::string _new;
    std::getline(std::cin, _new);
    this->_given_str = _new;
}

void BFC::createBrainFuck(bool isReadable) {
    this->_is_readable = isReadable;
    this->_create_ascii_vec_();
    this->_init_calc_vecs_();

    this->_code = "";

    // Add Iteration Amount to first 
    for (int i = 0; i < this->_iter; i++) this->_code += BF_Commands::add;
    this->_code += this->_return_endline_();

    // Shift Right 2 times

    // Loop :
    this->_code += BF_Commands::loop_start;
    this->_code += this->_return_endline_();
    this->_indent_amount++;
    this->_code += this->_return_indent();
    this->_code += BF_Commands::right_cell;
    this->_code += BF_Commands::right_cell;
    this->_code += this->_return_endline_();
    for (int i = 0; i < this->_ascii_vec.size(); i++)
    {
        // Indent if needed :
        this->_code += this->_return_indent();

        // Make additions :
        for (int k = 0; k < this->_k_vec[i]; k++) {
            this->_code += BF_Commands::add;
        }
        // Shift Right
        this->_code += BF_Commands::right_cell;

        // Endline :
        this->_code += this->_return_endline_();
    }
    // Return to first cell and sub 1:
    for (int i = 0; i < this->_ascii_vec.size() + 2;i++)
        this->_code += BF_Commands::left_cell;
    this->_code += BF_Commands::sub;


    this->_code += this->_return_endline_();
    this->_indent_amount--;
    this->_code += BF_Commands::loop_end;
    this->_code += this->_return_endline_();
    this->_code += BF_Commands::right_cell;
    this->_code += BF_Commands::right_cell;
    // End Additions :
    for (int t = 0; t < this->_add_vec.size(); t++) {
        this->_code += this->_return_endline_();
        for (int z = 0; z < this->_add_vec[t]; z++)
            this->_code += BF_Commands::add;
        this->_code += BF_Commands::right_cell;
    }

    this->_code += BF_Commands::left_cell;
    // Go to start [<]
    this->_code += this->_return_endline_();
    this->_code += BF_Commands::loop_start;
    this->_code += BF_Commands::left_cell;
    this->_code += BF_Commands::loop_end;
    this->_code += _return_endline_();

    // Go to end while printing [>.]
    this->_code += BF_Commands::right_cell;
    this->_code += BF_Commands::loop_start;
    this->_code += BF_Commands::print;
    this->_code += BF_Commands::right_cell;
    this->_code += BF_Commands::loop_end;
    this->_code += _return_endline_();

    std::cout << this->_code;
}

// BFC Private Functions :
void BFC::_create_ascii_vec_() {
    this->_ascii_vec = std::vector<int>(0);
    const char* _c_str_rep = this->_given_str.c_str();
    for (int i = 0; i < this->_given_str.length(); i++) {
        this->_ascii_vec.push_back((int)_c_str_rep[i]);
    }
}

int BFC::_find_half_min_() {
    int _min = 1000000; // Big Number
    for (int i = 0; i < static_cast<int>(this->_ascii_vec.size()); i++) {
        if (this->_ascii_vec[i] < _min) _min = this->_ascii_vec[i];
    }
    std::cout << "Found Half!" << std::endl;
    return (int)(_min / 2);
}

void BFC::_init_calc_vecs_() {

    this->_iter = (int)floor(this->_find_half_min_());

    int _len_vec = static_cast<int>(this->_ascii_vec.size());

    this->_k_vec = std::vector<int>(_len_vec);
    this->_add_vec = std::vector<int>(_len_vec);

    for (int i = 0; i < _len_vec; i++) {
        this->_k_vec[i] = (int)(this->_ascii_vec[i] / this->_iter);
        this->_add_vec[i] = (int)(this->_ascii_vec[i] % this->_iter);
    }
    std::cout << "Initialized Arrays!" << std::endl;
}

std::string BFC::_return_endline_() {
    return ((this->_is_readable) ? "\n" : "");
}

std::string BFC::_return_indent() {
    std::string _s = "";
    for (int i = this->_indent_amount; i > 0; i--) { _s += "\t"; }
    return ((this->_is_readable) ? _s : "");
}