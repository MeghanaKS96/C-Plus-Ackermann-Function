#include <algorithm>
#include <iostream>
#include <vector>
#include<tuple>

//1.1 Ackermann's function
template < int M, int N > class ackermann 
{
  public:
  static int const result = ackermann< M-1 , ackermann< M, N-1 >::result >::result ;
};

template < int M > class ackermann <M, 0>
{
  public:
  static int const result = ackermann<M-1, 1>::result;
};

template <int N> class ackermann <0,N> 
{
  public:
  static int const result = N+1;
};

//1.2 Union and Filter Container
template<typename T>
std::vector<int> unionAndFilterContainer(std::vector<T> a ,std::vector<T> b,bool(func)(int))
{
  std::vector<int> c;
  std::vector<int> d ;

  std::set_union(a.begin(), a.end(), b.begin(), b.end(),std::back_inserter(d));

  for(int x : d)
  {
      if(func(x))
      c.push_back(x);
  }

  return c;
}

//1.3 Tuple Equality
auto equalityU = [](auto const& a0, auto const&... args) 
{
  return ((args==a0) && ...);
};

//1.4 Matrix Multiplication
template<typename P>
bool matMulPossible(P const& tup)
{
  int j = 0;
  int column_val = -1;
  bool poss=true;
  int size = std::tuple_size<P>{};

  if(size % 2 !=0)
  {
    return false;
  }

  auto const check = [&](auto const &pair)
  {
    if (j ++ % 2 == 0)
    {
      column_val = pair.second;
    }
    else
    {
      if (column_val != pair.first)
      {
        return false;
      }  
    }
    return true;
  };

  return std::apply([&check](auto const &...pairs)
  {return (check(pairs)&& ...);},tup);

}




 
