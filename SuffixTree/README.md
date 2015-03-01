**[High Level Ukkonen’s algorithm](http://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/)**

Construct tree T1

          For i from 1 to m-1 do
                    begin {phase i+1}
                    For j from 1 to i+1
                              begin {extension j}
                              Find the end of the path from the root labelled S[j..i] in the current tree.
                              Extend that path by adding character S[i+l] if it is not there already
                    end;
          end;

There are 3 extension rules:

**Rule 1**: If the path from the root labelled S[j..i] ends at leaf edge (i.e. S[i] is last character on leaf edge) then character S[i+1] is just added to the end of the label on that leaf edge.

**Rule 2**: If the path from the root labelled S[j..i] ends at non-leaf edge (i.e. there are more characters after S[i] on path) and next character is not s[i+1], then a new leaf edge with label s{i+1] and number j is created starting from character S[i+1].
A new internal node will also be created if s[1..i] ends inside (in-between) a non-leaf edge.

**Rule 3**: If the path from the root labelled S[j..i] ends at non-leaf edge (i.e. there are more characters after S[i] on path) and next character is s[i+1] (already in tree), do nothing.

**Suffix links**

For an internal node v with path-label xA, where x denotes a single character and A denotes a (possibly empty) substring, if there is another node s(v) with path-label A, then a pointer from v to s(v) is called a suffix link.
If A is empty string, suffix link from internal node will go to root node.
There will not be any suffix link from root node (As it’s not considered as internal node).

**Trick#1**: Skip/Count Trick

**Trick#2**: Rule 3 is show stopper

**Trick#3**: Once a leaf, always a leaf

**activePoint**: This could be root node, any internal node or any point in the middle of an edge. This is the point where traversal starts in any extension. For the 1st extension of phase 1, activePoint is set to root. Other extension will get activePoint set correctly by previous extension (with one exception case APCFALZ discussed below) and it is the responsibility of current extension to reset activePoint appropriately at the end, to be used in next extension where Rule 2 or Rule 3 is applied (of same or next phase).

To accomplish this, we need a way to store activePoint. We will store this using three variables: activeNode, activeEdge, activeLength.

**activeNode**: This could be root node or an internal node.

**activeEdge**: When we are on root node or internal node and we need to walk down, we need to know which edge to choose. activeEdge will store that information. In case, activeNode itself is the point from where traversal starts, then activeEdge will be set to next character being processed in next phase.

**activeLength**: This tells how many characters we need to walk down (on the path represented by activeEdge) from activeNode to reach the activePoint where traversal starts. In case, activeNode itself is the point from where traversal starts, then activeLength will be ZERO.
