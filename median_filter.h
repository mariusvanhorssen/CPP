#pragma once

#include <stddef.h>
#include <stdlib.h>

template <class T> 
T median_filter(T* pData, size_t Size) 
{
  auto CompSortAsc = [](const void* a, const void* b) -> int
  {
    if(*(static_cast<const T*>(a)) > (*static_cast<const T*>(b)))
    {
      return  1;
    }
    else
    {
      return -1;
    }
  };
  
  qsort (pData, Size, sizeof(T), CompSortAsc);
  return pData[Size / 2];
}