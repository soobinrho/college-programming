#include <iostream>

int main () {
  /*
   *   DEADLOCK DETECTION ALGORITHM
   *   An algorithm that reads a resource tree and then determines
   *   if it has a deadlock or not. The resource tree consists
   *   of three components: source id, destination id, and an operator.
   *
   *   Example input:
   *   A>B
   *   C<B
   *   C>D
   *   E<D
   *   E>A
   */

  // . I thought it was best to abstract these data as a linked list.

  // Behavior of this data structure:
  // - By nodes, I mean either a resource or a thread.
  // - Nodes can only point to only one node.
  //   To be exact, they can point to either 1 node or no node at all.
  // - Although nodes can point to only one another node,
  //   multiple nodes can point to one node at the same time.

  
    // . Keep track of the current list L as an unordered map.


    // Print the progress.


    // Reset the list L because these nodes don't have a deadlock.


    // . Exit because a deadlock has been found.


  return 0;
}
