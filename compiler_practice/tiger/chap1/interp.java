class interp {
  static void interp(Stm s) { /* you write this part */ }

  static int maxargs(Stm s) { 
		return s.maxargs();
  }

  public static void main(String args[]) throws java.io.IOException {
     System.out.println(maxargs(prog.prog));
     interp(prog.prog);
  }
}
