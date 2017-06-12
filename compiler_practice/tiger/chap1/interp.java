class interp {
  static void interp(Stm s) { 
	  s.interpStm(new Table(null, -1, null));
	}

  static int maxargs(Stm s) { 
		return s.maxargs();
  }

  public static void main(String args[]) throws java.io.IOException {
     System.out.println(maxargs(prog.prog));
     interp(prog.prog);
  }
}
