//this is a pseudocode for getting a epsilon-closure
addState(s)
{
	push s onto newStates;
	alreadyOn[s] = TRUE;
	for(t on move[s, epsilon])
		if(!alreadyOn(t))
			addState(t);
}