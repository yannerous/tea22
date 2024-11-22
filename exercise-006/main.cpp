#include <fmt/chrono.h>
#include <fmt/format.h>
#include "LinkedList.h"

auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);

   
    LinkedList<int>* listPtr = (LinkedList<int>*)malloc(sizeof(LinkedList<int>));
    int num[] = {1,3,5,42,5};
    ListNode<int>* nodePtr = NULL;
    for(int i = 0; i< 5;i++)
    {
        addToList<int>(listPtr,&num[i]);
    }
    printList<int>(listPtr);
    RemoveFromList<int>(listPtr,&num[1]);
    printList<int>(listPtr);

    return 0; /* exit gracefully*/
}
