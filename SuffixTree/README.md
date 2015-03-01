High Level Ukkonen’s algorithm
`
Construct tree T1
For i from 1 to m-1 do
begin {phase i+1}
          For j from 1 to i+1
                    begin {extension j}
                    Find the end of the path from the root labelled S[j..i] in the current tree.
                    Extend that path by adding character S[i+l] if it is not there already
          end;
end;
`

There are 3 extension rules:

**Rule 1**: If the path from the root labelled S[j..i] ends at leaf edge (i.e. S[i] is last character on leaf edge) then character S[i+1] is just added to the end of the label on that leaf edge.

**Rule 2**: If the path from the root labelled S[j..i] ends at non-leaf edge (i.e. there are more characters after S[i] on path) and next character is not s[i+1], then a new leaf edge with label s{i+1] and number j is created starting from character S[i+1].
A new internal node will also be created if s[1..i] ends inside (in-between) a non-leaf edge.

**Rule 3**: If the path from the root labelled S[j..i] ends at non-leaf edge (i.e. there are more characters after S[i] on path) and next character is s[i+1] (already in tree), do nothing.

