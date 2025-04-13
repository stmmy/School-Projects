#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


class stack {
    private:
        vector<char> mystack;
        vector<float> eval_stack;
        string output = "";
        string input;
        int stack_size = 0;
        int eval_stack_size = 0;
        float result = 0;
        bool valid = true;
    public:
        stack(string iinput) {input = iinput;}

        //stack functions
        char top() {return mystack.back();}

        int size() {return stack_size;}

        char pop() {
            char temp = top();
            mystack.pop_back();
            stack_size--;
            return temp;
        }

        void add(char input_operator) {
            mystack.push_back(input_operator);
            stack_size++;
        }

        //eval stack functions
        int eval_top() {return eval_stack.back();}

        int eval_size() {return eval_stack_size;}

        int eval_pop() {
            int temp = eval_top();
            eval_stack.pop_back();
            eval_stack_size--;
            return temp;
        }

        void eval_add(int input_operator) {
            eval_stack.push_back(input_operator);
            eval_stack_size++;
        }

        //main functions
        bool is_operator(char input) {
            char operators[5] = {'^', '/', '*', '+', '-'};
            for (int i=0; i != 5; i++) {
                if (input == operators[i]){
                    return true;
                }
                else if (input == '(' || input == ')') {
                    return true;
                }        
            }
            return false;
        }

        int precedence(char input) {
            char operators[5] = {'^', '/', '*', '+', '-'};
            for (int i=0; i != 5; i++) {
                if (input == operators[i]){
                    if (i == 1 || i == 2) {
                        return 2;
                    }
                    else if (i == 3 || i == 4) {
                        return 3;
                    }
                    else {
                        return 1;
                    }
                }       
            }
            return 10;
        } 

        void itp_convert(int pos) {
            if (is_operator(input[pos]) == false && pos+1 <= input.size()) {
                output = output + input[pos];
                itp_convert(pos+1);
                return;
            }
            else if (input[pos] == '(') {
                add('(');
                itp_convert(pos+1);
                return;
            }
            else if (is_operator(input[pos]) == true && input[pos] != ')') {
                if (size() == 0) {
                    add(input[pos]);
                    itp_convert(pos+1);
                    return;
                } 
                else if (top() == '(') {
                    add(input[pos]);
                    itp_convert(pos+1);
                    return;
                } 
                else if (precedence(input[pos]) < precedence(top())) {
                    add(input[pos]);
                    itp_convert(pos+1);
                    return;
                }
                else {
                    output = output + pop();
                    itp_convert(pos);
                    return;
                }
            }
            else if (input[pos] == ')') {
                int tmp = size();
                for (int i=0; i != tmp; i++) {
                    if (top() == '(') {
                        pop();
                        break;
                    }
                    else {
                        output = output + pop();
                    }
                }
                itp_convert(pos+1);
                return;
            }
            else {
                int tmp = size();
                for (int i=0; i != tmp; i++) {
                    output = output + pop();
                }
                return;
            }
            return;
        }

        void postfix_evaluate() {
            int n1, n2;
            for (int i=0; i != input.size(); i++) {
                if (is_operator(input[i]) == false) {
                    eval_add((float)input[i] - 48);
                }
                else {
                    if (eval_size() < 2) {
                        valid = false;
                        break;
                    }
                    if (input[i] == '^') {
                        n2 = eval_pop();
                        n1 = eval_pop();
                        eval_add(pow(n1,n2));
                    }
                    else if (input[i] == '*') {
                        n2 = eval_pop();
                        n1 = eval_pop();
                        eval_add(n1*n2);
                    }
                    else if (input[i] == '/') {
                        n2 = eval_pop();
                        n1 = eval_pop();
                        eval_add(n1/n2);
                    }
                    else if (input[i] == '+') {
                        n2 = eval_pop();
                        n1 = eval_pop();
                        eval_add(n1+n2);
                    }
                    else if (input[i] == '-') {
                        n2 = eval_pop();
                        n1 = eval_pop();
                        eval_add(n1-n2);
                    }
                }
            }
            
            result = eval_pop();
        }

        void output2(string filename){
            ofstream output_file;
            output_file.open(filename);
            output_file << output;
            output_file.close();
        }

        void output3(string filename){
            ofstream output_file;
            output_file.open(filename);
            if (valid == true) {
                output_file << setprecision(1) << std::fixed << result << "\n";
            }
            else {
                output_file << "nv" << "\n";
            }
            output_file.close();
        }
};


int main(int argc, char *argv[]) {
    int part = stoi(argv[1]);
    string user_input = argv[2];
    string user_output = argv[3];
    stack a(user_input);

    if (part == 2) {
        a.itp_convert(0);
        a.output2(user_output);
    }
    else if (part == 3) {
        a.postfix_evaluate();
        a.output3(user_output);
    }
}
