#ifndef BRAINFUCK_CREATOR
#define BRAINFUCK_CREATOR

#include <iostream> 
#include <string>
#include <vector>

typedef struct bf_commands
{
    static char right_cell;
    static char left_cell;
    static char add;
    static char sub;
    static char print;
    static char loop_start;
    static char loop_end;
} BF_Commands;


class BFC
{
private:
    std::string _code;
    std::string _given_str;
    unsigned int _iter;
    bool _is_readable;
    int _indent_amount;
    std::vector<int> _ascii_vec;
    std::vector<int> _k_vec;
    std::vector<int> _add_vec;

    void _create_ascii_vec_();
    void _init_calc_vecs_();

    /**
     * Finds minimum value in this->_ascii_vec
     * @returns Minimum int value in this->_ascii_vec
    */
    int _find_half_min_();

    std::string _return_endline_();
    std::string _return_indent();

public:
    /**
     * Initiator for the BrainFuck Creator Class.
     * If no string is given via the set_string or set_string_getter() the default empty string will be used.
     *
    */
    BFC();
    ~BFC();

    /**
     * Sets string of the BrainFuck Creator Class.
     * @param[in] givenStr String to be turned into BrainFuck code
     */
    void set_string(std::string givenStr);
    /**
     * Sets string of the BrainFuck Creator Class.
     * Asks you to get your string via `std::cin`
     */
    void set_string_getter();

    /**
     * Prints out the BrainFuck representation of the stored string.
     * @param[in] isReadable Will the code be seperated to newlines for readability.
    */
    void createBrainFuck(bool isReadable);
};


#endif // BRAINFUCK_CREATOR