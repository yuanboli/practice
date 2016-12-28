//just a pseudocode

switch(*forward++)
{
case eof:
	if (forward is end of the first buffer)
	{
		reload second buffer;
		forward = beginning of the second buffer;
	}
	else if(forward is the end of the second buffer)
	{
		reload first buffer
		forward = beginning of the first buffer
	}
	else	// which is the true eof meaning
		terminate lexical analysis
	break;
	
	Cases for other characters;
}