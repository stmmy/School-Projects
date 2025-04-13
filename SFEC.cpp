#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <pthread.h>

struct pTc
{
  char symbol;
  std::vector<double> p;
  int index;
  std::string* code;
};

void * SFEC(void * params)
{
    pTc threadArg = *((pTc *) params);
    std::vector<int>remains;
    std::string code;
    double cp = 0;
    double cdf = 0;
    double length = 0;
    int bnum;
    
    //Calc cumulative probability and cdf
    if (threadArg.index > 0) { for (int i=0; i < threadArg.index+1; i++) { if (i != 0) {cp = cp + threadArg.p[i-1];} } }
    cdf = threadArg.p[threadArg.index]/2 + cp;
    
    //calc length
    length = ceil(log2(1/threadArg.p[threadArg.index])+1);
    
    //Get vector of binary vals based of cdf
    bnum = round(cdf * pow(2,8));
    for(int i=0; i<8; i++) 
    {
        remains.push_back(bnum%2);
        bnum = bnum/2;   
    }
    
    //Store code from back of remains vector relative to length
    for (int i=remains.size()-1; i != (remains.size()-1)-length; i--) {code = code + std::to_string(remains[i]);}
    *threadArg.code = code;
    return nullptr;
}


int main()
{
    char tmp;
    double input;
    std::string line;
    std::vector<char> symbols;
    std::vector<double> probs;
    std::vector<std::string> codes;
    std::vector<pTc> args;
    std::vector<pthread_t> tid;
    
    
    //Reading in input
    std::getline(std::cin, line);
    for (int i=0; i < line.length(); i++) {if (line[i] != ' ') {symbols.push_back(line[i]);}}
    for (int i=0; i < symbols.size(); i++) 
    {
        std::cin >> input;
        probs.push_back(input);
    }
    
    //Populate arg vector and codes vector to avoid seg fault
    for (int i=0; i<symbols.size(); i++) {codes.push_back(std::string());} 
    for (int i=0; i<symbols.size(); i++)
    {
        args.push_back(pTc());
        tmp = symbols[i];
        args[i].symbol = tmp;
        args[i].p = probs;
        args[i].index = i;
        args[i].code = &codes[i];
    }
    
    //Create threads and then join them together
    for (int i=0; i<symbols.size(); i++) 
    {
        pthread_t newThread;
        pthread_create(&newThread, NULL, SFEC, &args[i]);
        tid.push_back(newThread);
    }
    for(int i=0; i<symbols.size() ; i++) {pthread_join(tid[i], NULL);}

    //Print Out
    std::cout << "SHANNON-FANO-ELIAS Codes:" << std::endl;
    for(int i=0; i<symbols.size(); i++) {std::cout << std::endl << "Symbol "<< symbols[i] << ", Code: " << codes[i];}



    return 0;
}
