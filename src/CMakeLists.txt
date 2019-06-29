
SET(SRC_LIST main.cpp
    lib/log.cpp
    algorithms/sort/sort.cpp
    lib/time_analyzer.cpp
    util/util.cpp
    algorithms/find/maxsubarr.cpp
    algorithms/sort/heapsort.cpp
    algorithms/sort/quicksort.cpp
    lib/huffman.cpp
    )
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE DEBUG)
ADD_EXECUTABLE(study ${SRC_LIST})
