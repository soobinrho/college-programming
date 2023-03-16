#include <iostream>

int main () {
  /*
   *   DEADLOCK DETECTION ALGORITHM
   *   An algorithm that reads a resource tree and then determines
   *   if it has a deadlock or not. The resource tree consists
   *   of three components: <threadID> <operator> <resourceID>
   *
   *   Example:
   *     a<Z
   *     b>X
   *     c<X
   *     d
   *     e
   *
   *   - Note that resourceID is capitalized, while threadID is not.
   */

  // . I thought it was best to abstract these data as a linked list.

  // By nodes, I mean either a resource or a thread.
  
    // . Keep track of the current list L as an unordered map.
    //     Key: the ID of the node
    //     Value: 1 (if that node is checked) || 0 (if not)


    // Print the progress.


    // Reset the list L because these nodes don't have a deadlock.


    // . Exit because a deadlock has been found.


  return 0;
}
