//this is a pseudocode for LR parsing algorithm
let a be the first symbol of w$;
while(true)
{
	let s be the state on the top of the stack;
	if(ACTION[s,a] = shift t)
	{
		push t onto stack;
		let a be the next input symbol;
	}
	if(ACTION[s,a] = reduce A --> b)
	{
		pop the length of b symbols off the stack;
		let state t now be on the top of the stack;
		push GOTO[t,A] onto the stack;
		output the production A --> b;
	}
	else if(ACTION[s,a] = accept)
		break;//parsing is done;
	else
		call error-recovery routine;
}