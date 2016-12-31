//this is just a pseudocode to simulate an NFA
S = epsilon-closure(s0);
c = nextChar();
while(c != eof)
{
	S = epsilon-closure(move(S, c));
	c = nextChar();
}
if(S and F share some common elements)
	return true;
else
	return false;