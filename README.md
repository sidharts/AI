# AI
ARTIFICIAL INTELLIGENCE

IMPLEMENTATION OF RESOLUTION IN PROPOSITIONAL LOGIC
USING BACKWARD CHAINING

Input: A text file that contains sample input. The first line indicates the query. The second line
contains an integer n specifying the number of clauses in the text file. Each line after will contain
an axiom, which is written as an implication whose premise is a conjunction of positive literals
and whose conclusions is a single positive literal. It
has the form:

p1 ∧ p2 ∧...∧ pn ⇒Q

Output: If you can prove the query, then the answer will be YES, otherwise, NO (with NO
meaning that you either disapprove the query, or the knowledge base is incomplete to determine
the query).

Sample Input:

A_Witch@
7@
Made_Of_Wood&gt;A_Witch@
Weighs_Same_As_Duck&amp;Floats_On_Water&gt;Made_Of_Wood@
Turned_Me_Into_A_Newt&amp;Weighs_Same_As_Duck&gt;Floats_On_Water@
Has_A_Wart&amp;Made_Of_Wood&gt;Weighs_Same_As_Duck@
Has_A_Wart&amp;Turned_Me_Into_A_Newt&gt;Weighs_Same_As_Duck@
Has_A_Wart@

Turned_Me_Into_A_Newt#

‘@’ is used to signify end of sentence.
‘#’ is used to signify end of whole input.

The above program will output YES.
