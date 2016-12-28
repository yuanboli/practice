class For extends Stmt;
{
	Expr E1;
	Expr E2;
	Expr E3;
	Stmt S;
	
	public For(Expr e1, Expr e2, Expr e3, Stmt s)
	{
		E1 = e1;
		E2 = e2;
		E3 = e3;
		S = s;
	}
	public void gen()
	{
		E1.gen();
		Expr n = E2;
		emit("ifFalse" + n.toString() + "goto" + after);
		S.gen();
		E3.gen();
		emit(after + ":");
	}
}