#include <iostream>
#include <fstream>

using namespace std;

class hanoi {
    private:
        ofstream output_file;
        string filename;
    public:
        
        hanoi(string tfn) {
            filename = tfn;
            output_file.open(filename);
        }

        void write(int disc_num, char peg1, char peg2) {
            output_file << disc_num << " " << peg1 << " -> " << peg2 << "\n";
        }

        void close_file() { output_file.close(); }

        void hanoi3(int n, int start, int end) {
            char pegs[3] = {'A', 'B', 'C'};

            if (n == 1) {
                write(n, pegs[start-1], pegs[end-1]);
                //printf("%d %c -> %c \n", n, pegs[start-1], pegs[end-1]);
            }
            else {
                int other = 6 - (start + end);
                hanoi3(n-1, start, other);
                write(n, pegs[start-1], pegs[end-1]);
                //printf("%d %c -> %c \n", n, pegs[start-1], pegs[end-1]);
                hanoi3(n-1, other, end);
            }
        }

        void hanoi4(int n, int from, int to, int a1, int a2) {
            char pegs[4] = {'A', 'B', 'C', 'D'};
            
            if (n == 0) {
                return;
            }
            else if (n == 1) {
                write(n, pegs[from-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n, pegs[from-1], pegs[to-1]);
                return;
            }
            else {
                hanoi4(n - 2, from, a1, a2, to);
                write(n - 1, pegs[from-1], pegs[a2-1]);
                write(n, pegs[from-1], pegs[to-1]);
                write(n - 1, pegs[a2-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n - 1, pegs[from-1], pegs[a2-1]);
                //printf("%d %c -> %c \n", n, pegs[from-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n - 1, pegs[a2-1], pegs[to-1]);
                hanoi4(n - 2, a1, to, from, a2);
            }
        }

        void hanoi5(int n, int from, int to,int a1, int a2, int a3) {
            char pegs[5] = {'A', 'B', 'C', 'D', 'E'};

            if (n == 0)
                return;
            else if (n == 1) {
                write(n, pegs[from-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n, pegs[from-1], pegs[to-1]);
                return;
            }
            else if (n==2) {
                write(n-1, pegs[from-1], pegs[a1-1]);
                write(n, pegs[from-1], pegs[to-1]);
                write(n-1, pegs[a1-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n-1, pegs[from-1], pegs[a1-1]);
                //printf("%d %c -> %c \n", n, pegs[from-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n-1, pegs[a1-1], pegs[to-1]);
                return;
            }
            else {
                hanoi5(n - 3, from, a1, a2, a3, to);
                write(n - 2, pegs[from-1], pegs[a3-1]);
                write(n - 1, pegs[from-1], pegs[a2-1]);
                write(n, pegs[from-1], pegs[to-1]);
                write(n - 1, pegs[a2-1], pegs[to-1]);
                write(n - 2, pegs[a3-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n - 2, pegs[from-1], pegs[a3-1]);
                //printf("%d %c -> %c \n", n - 1, pegs[from-1], pegs[a2-1]);
                //printf("%d %c -> %c \n", n, pegs[from-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n - 1, pegs[a2-1], pegs[to-1]);
                //printf("%d %c -> %c \n", n - 2, pegs[a3-1], pegs[to-1]);
                hanoi5(n - 3, a1, to, from, a2, a3);
            }
        }
};

int main(int argc, char *argv[]) {
    int p = stoi(argv[1]);
    int n = stoi(argv[2]);
    string output_filename = argv[3];
    hanoi x(output_filename);
    
    if (p == 3) {
        x.hanoi3(n, 1, 3);
    }
    else if (p == 4) {
        x.hanoi4(n, 1,4,2,3);
    }
    else if (p == 5) {
        x.hanoi5(n, 1, 5, 2, 3, 4);
    }
    
    x.close_file();
    return 0;
}
