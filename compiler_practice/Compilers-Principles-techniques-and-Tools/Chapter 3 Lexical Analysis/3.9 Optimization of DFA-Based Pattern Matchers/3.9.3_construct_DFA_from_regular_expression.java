//this is just pseudocode to construct a DFA from regex
while(there is an unmarked state S in Dstates)
{
	mark S;
	for(each input symbol a)
	{
		let U be the union of followpos(p) for all p in S that correspond to a;
		if(U is not in Dstates)
			add U as an unmarked state to Dstates;
		Dtran[S,a] = U;
	}
}
