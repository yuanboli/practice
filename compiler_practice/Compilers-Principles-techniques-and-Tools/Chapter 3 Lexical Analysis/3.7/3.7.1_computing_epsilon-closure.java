//this is just a pseudocode


// to get epsilon-closure;
push all states of T onto stack
initialize epsilon-closure(T) to T;
while(stack is not empty)
{
	pop t, the top element, off stack
	for(each state u with an edge from t to u labeled epsilon)
	{
		if(u is not in epsilon-closure(T))
		{	add u in epsilon-closure(T);
			push u onto stack;
	
		}
	}
}