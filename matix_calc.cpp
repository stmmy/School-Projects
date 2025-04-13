#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


using namespace std;

struct node {
    float data, row, col;
    node *next;
};

class linked_list {
    private:
        node *head, *tail;
        node *headSub, *tailSub;
        int size, dimension, det=0;
        int sizeSub, dimensionSub;
    public:
        linked_list() {
            head = NULL;
            tail = NULL;

            headSub = NULL;
            tailSub = NULL;
        }

        void get_input(string input){
            ifstream file(input);
            int n;
            
            while(file >> n) {
                node *tmp = new node;
                tmp->data = n;
                tmp->row = 0;
                tmp->col = 0;
                tmp->next = NULL;

                if (head == NULL) {
                    head = tmp;
                    tail = tmp;
                }
                else {
                    tail->next = tmp;
                    tail = tail->next;
                }
            }
            file.close();
            set_size();
            set_rowcol();
        }

        
        //Setter Functions
        void set_rowcol() {
            int row = 0;
            int col = 0;
            node *tmp = new node;
            tmp = head;
            for (int i=0; i != size; i++) {
                tmp->col = col;
                tmp->row = row;
                col++;
                if (col == dimension){
                    row++;
                    col = 0;
                }
                tmp = tmp->next;
            }
        }

        void set_size() {
            node *tmp;
            tmp = head;
            dimension = 0;
            size =0;
            
            while (tmp != NULL) {
                size++;
                tmp = tmp->next;
            }
            
            if (size%8 == 0) {
                dimension = 8; }
            else if (size%7 == 0) {
                dimension = 7; }
            else if (size%6 == 0) {
                dimension = 6; }
            else if (size%5 == 0) {
                dimension = 5; }
            else if (size%4 == 0) {
                dimension = 4; }
            else if (size%3 == 0) {
                dimension = 3; }
            else if (size%2 == 0) {
                dimension = 2; }
        }

        void set_sub_size() {
            node *tmp;
            tmp = headSub;
            dimensionSub = 0;
            sizeSub = 0;
            
            while (tmp != NULL) {
                sizeSub++;
                tmp = tmp->next;
            }
            
            if (sizeSub%8 == 0) {
                dimensionSub = 8; }
            else if (sizeSub%7 == 0) {
                dimensionSub = 7; }
            else if (sizeSub%6 == 0) {
                dimensionSub = 6; }
            else if (sizeSub%5 == 0) {
                dimensionSub = 5; }
            else if (sizeSub%4 == 0) {
                dimensionSub = 4; }
            else if (sizeSub%3 == 0) {
                dimensionSub = 3; }
            else if (sizeSub%2 == 0) {
                dimensionSub = 2; }
        }

        
        //Getter Functions
        int get_size() {
            set_size();
            return size;
        }

        int get_dimension() {
            set_size();
            return dimension;
        }

        int get_node(int n, int x) {
            int the_node;
            int count = 0;
            node *tmp;
            tmp = head;

            if (x == 2) {
                while (tmp != NULL) {
                    if (count == n) {
                        break;
                    }
                    count++;
                    tmp = tmp->next;
                }
                return tmp->col;
            }
            else if (x == 1) {
                while (tmp != NULL) {
                    if (count == n) {
                        break;
                    }
                    count++;
                    tmp = tmp->next;
                }
                return tmp->row;
            }
            else if (x == 0) {
                while (tmp != NULL) {
                    if (count == n) {
                        break;
                    }
                    count++;
                    tmp = tmp->next;
                }
                return tmp->data;
            }
            return 0;
        }

        node* gethead() {
            return head;
        }

        
        //Utility Functions
        void add_node(int n, int r, int c) {
            node *tmp = new node;
            tmp->data = n;
            tmp->row = r;
            tmp->col = c;
            tmp->next = NULL;

            if (head == NULL) {
                head = tmp;
                tail = tmp;
            }
            else {
                tail->next = tmp;
                tail = tail->next;
            }
            set_size();
        }

        void add_sub_node(int n, int r, int c) {
            node *tmp = new node;
            tmp->data = n;
            tmp->row = r;
            tmp->col = c;
            tmp->next = NULL;

            if (headSub == NULL) {
                headSub = tmp;
                tailSub = tmp;
            }
            else {
                tailSub->next = tmp;
                tailSub = tailSub->next;
            }
            set_sub_size();
        }

        void delete_nodes() {
            node *tmp = head;
            node *next = NULL;

            while (tmp != NULL)
            {
                next = tmp->next;
                free(tmp);
                tmp = next;
            }
            head = NULL;
        }

        void display() {
            node *tmp;
            tmp = head;
            set_size();

            for (int i=0; i != size; i++) {
                if (i%dimension ==0) {
                    cout << endl;
                }
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            //cout << dimension << endl;
            //cout << size << endl;
        }

        
        //Functionality
        void add(linked_list a, linked_list b) {
            for (int i=0; i != a.get_size(); i++) {
                node *tmp = new node;
                tmp->data = a.get_node(i,0) + b.get_node(i,0);
                add_node(tmp->data, 0, 0);
            }
            set_size();
        }

        void subtract(linked_list a, linked_list b) {
            for (int i=0; i != a.get_size(); i++) {
                node *tmp = new node;
                tmp->data = a.get_node(i,0) - b.get_node(i,0);
                add_node(tmp->data, 0, 0);
            }
            set_size();
        }

        void multiply(linked_list a, linked_list b) {
            node *tmp1;
            node *tmp2;
            int num = 0;
            int num_a;
            int num_b;
            for (int i=0; i != a.get_dimension(); i++) {
                for (int j=0; j != a.get_dimension(); j++) {
                    for (int l=0; l != a.get_dimension(); l++) {
                        tmp1 = a.gethead();
                        tmp2 = b.gethead();
                        for (int k=0; k != a.get_size(); k++) {
                            if (a.get_node(k, 1) == i && a.get_node(k, 2) == l) {
                                num_a = tmp1->data;
                                break;
                            }
                            tmp1 = tmp1->next;
                        }
                        for (int k=0; k != b.get_size(); k++) {
                            if (b.get_node(k, 1) == l && b.get_node(k, 2) == j) {
                                num_b = tmp2->data;
                                break;
                            }
                            tmp2 = tmp2->next;
                        }
                        num = num + (num_a*num_b);
                    }
                    add_node(num, 0, 0);
                    num = 0;
                }
            }
        }
        
        void transpose(linked_list a) {
            node *tmp;
            for (int i=0; i != a.get_dimension(); i++) {
                for (int j=0; j != a.get_dimension(); j++) {
                    tmp = a.gethead();
                    for (int k=0; k != a.get_size(); k++) {
                        if (a.get_node(k,1) == j && a.get_node(k,2) == i) {
                            add_node(tmp->data, 0, 0);
                            break;
                        }
                        tmp = tmp->next;
                    }
                }
            }
        }

        double determinant(int m, linked_list x) {
            double answere = 0, inner_sol;
            int num;
    
            if (m == 2) 
            {
                int a,b,c,d;
                a = x.get_node(0, 0);
                b = x.get_node(1, 0);
                c = x.get_node(2, 0);
                d = x.get_node(3, 0);
                answere = (a*d) - (b*c);
            }
            else 
            {
                int sign = +1, basic;
                linked_list y;
                for (int i=0; i != m; i++){
                    basic = x.get_node(i, 0);

                    for (int j=0; j != m; j++){
                        for (int k=0; k != m; k++) {
                            if (j != 0 && k != i) {
                                num = x.get_node((j*m)+k,0);
                                y.add_node(num,0,0);
                            }
                        }
                    }
                    inner_sol = pow(-1,i)*basic*determinant(m-1, y);
                    answere = answere + inner_sol;
                    y.delete_nodes();
                }   
            }           
            return answere;
        }
};


int main(int argc, char *argv[]) {
    linked_list a;
    linked_list b;
    linked_list ans;
    ofstream output_file;
    string operation = argv[1];

    if (operation == "add") {
        string input1 = argv[2];
        string input2 = argv[3];
        a.get_input(input1);
        b.get_input(input2);
        ans.add(a, b);
        float num = 0;

        string filename = argv[4];
        output_file.open(filename);
        for (int i=0; i != ans.get_size(); i++) {
            num = ans.get_node(i,0);
            if (i%ans.get_dimension() == 0 && i != 0) {
                output_file << "\n";
            }
            output_file << fixed << setprecision(1) << num << " ";
        }
        output_file.close();        
    }
    else if (operation == "sub") {
        string input1 = argv[2];
        string input2 = argv[3];
        a.get_input(input1);
        b.get_input(input2);
        ans.subtract(a, b);
        float num = 0;

        string filename = argv[4];
        output_file.open(filename);
        for (int i=0; i != ans.get_size(); i++) {
            num = ans.get_node(i,0);
            if (i%ans.get_dimension() == 0 && i != 0) {
                output_file << "\n";
            }
            output_file << fixed << setprecision(1) << num << " ";
        }
        output_file.close();    
    }
    else if (operation == "mul") {
        string input1 = argv[2];
        string input2 = argv[3];
        a.get_input(input1);
        b.get_input(input2);
        ans.multiply(a, b);
        float num = 0;

        string filename = argv[4];
        output_file.open(filename);
        for (int i=0; i != ans.get_size(); i++) {
            num = ans.get_node(i,0);
            if (i%ans.get_dimension() == 0 && i != 0) {
                output_file << "\n";
            }
            output_file << fixed << setprecision(1) << num << " ";
        }
        output_file.close();          
    }
    else if (operation == "tra") {
        string input1 = argv[2];
        a.get_input(input1);
        ans.transpose(a);
        float num = 0;

        string filename = argv[3];
        output_file.open(filename);
        for (int i=0; i != ans.get_size(); i++) {
            num = ans.get_node(i,0);
            if (i%ans.get_dimension() == 0 && i != 0) {
                output_file << "\n";
            }
            output_file << fixed << setprecision(1) << num << " ";
        }
        output_file.close();          
    }
    else if (operation == "det") {
        string input1 = argv[2];
        a.get_input(input1);
        
        string filename = argv[3];
        output_file.open(filename);
        output_file << fixed << setprecision(1) << ans.determinant(a.get_dimension(), a) << "\n";
        output_file.close();             
    }        
    return 0; 
}

