//this is just pseudocode
/**
 * from the start state to get all the Dstates and Dtran function
 */
while(there is an unmarked state T in Dstates)
{
	mark T;
	for(each input symbol a)
	{
		U = epsilon-closure(move(T, a));
		if(U is not in Dstates)
			add U as an unmarked state to Dstates;
		Dtran[T, a] = U;
	}
}