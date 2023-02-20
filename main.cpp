#include "utils.h"
#include<tuple>
#include<functional>

int main() 
{
    //1.2 unionAndFilterContainer 
    std::vector<int> a = {1,2,3,4,5};
    std::vector<int> b = {6,7,8,9,10};
    auto c = unionAndFilterContainer(a,b, [](int x){return x%2==0;});
    if (std::all_of(c.begin(), c.end(), [](auto x){ return x%2==0;}))
    std::cout << "QUESTION 2 PASSED" << std::endl;
    else
    std::cout << "QUESTION 2 FAILED" << std::endl;

    //1.1 Ackermann's function
    std::cout << ackermann<1,2>::result << std::endl;

    //1.3 Equality of Tuples
    std::tuple tup1 {1,1,1};
    bool eq = std::apply(equalityU, tup1);
    if(eq)
    std::cout<< "Given tuple equal" << std::endl;
    else
    std::cout<< "Given tuple not equal" << std::endl;

    //1.4 Matrix Multiplication

    std::pair<int,int> p1 (3,4);
    std::pair<int,int> p2 (4,5);
    std::pair<int,int> p3 (4,5);
    std::pair<int,int> p4 (5,4);
    std::tuple tup (p1,p2,p3,p4);

    bool ans = matMulPossible(tup);
    if(ans)
    std::cout<<"Matrix multiplication is possible"<< std::endl;
    else
    std::cout<<"Matrix multiplication is not possible"<< std::endl;
}
