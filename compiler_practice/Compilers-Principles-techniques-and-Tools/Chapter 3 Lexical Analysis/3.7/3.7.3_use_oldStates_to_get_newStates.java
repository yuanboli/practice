//this is a pseudocode to use oldStates and input to get newStates
for(s on oldStates)
{
	for(t on move[s,c])
		if(!alreadyOn[t])
			addState(t);
	pop s from oldStates;
}

for(s on newStates)
{
	pop s from newStates;
	push s onto onto oldStates;
	alreadyOn[s] = FALSE;
}