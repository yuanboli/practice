abstract class Stm {
	abstract public int maxargs();
}

class CompoundStm extends Stm {
   Stm stm1, stm2;
   CompoundStm(Stm s1, Stm s2) {stm1=s1; stm2=s2;}
	 public int maxargs(){
	   return Math.max(stm1.maxargs(), stm2.maxargs());
	 }
}

class AssignStm extends Stm {
   String id; Exp exp;
   AssignStm(String i, Exp e) {id=i; exp=e;}
	 public int maxargs(){
	   return exp.maxargs();
	 }
}

class PrintStm extends Stm {
   ExpList exps;
   PrintStm(ExpList e) {exps=e;}
	 public int maxargs(){
		 return Math.max(exps.countPrintArgs(), exps.maxargs());
	 }
}

abstract class Exp {
	abstract public int maxargs();
}

class IdExp extends Exp {
   String id;
   IdExp(String i) {id=i;}
	 public int maxargs(){
	   return 0;
	 }
}

class NumExp extends Exp {
   int num;
   NumExp(int n) {num=n;}
	 public int maxargs(){
	   return 0;
	 }
}

class OpExp extends Exp {
   Exp left, right; int oper;
   final static int Plus=1,Minus=2,Times=3,Div=4;
   OpExp(Exp l, int o, Exp r) {left=l; oper=o; right=r;}
	 public int maxargs(){
	   return Math.max(left.maxargs(), right.maxargs());
	 }
}

class EseqExp extends Exp {
   Stm stm; Exp exp;
   EseqExp(Stm s, Exp e) {stm=s; exp=e;}
	 public int maxargs(){
	   return Math.max(stm.maxargs(), exp.maxargs());
	 }
}

abstract class ExpList {
	abstract public int maxargs();
	abstract public int countPrintArgs();
}

class PairExpList extends ExpList {
   Exp head; ExpList tail;
   public PairExpList(Exp h, ExpList t) {head=h; tail=t;}
	 public int maxargs(){
	   return Math.max(head.maxargs(), tail.maxargs());
	 }
   
	 public int countPrintArgs(){
	   return tail.countPrintArgs() + 1;
	 }
}

class LastExpList extends ExpList {
   Exp head; 
   public LastExpList(Exp h) {head=h;}
	 public int maxargs(){
	   return head.maxargs();
	 }
	 
	 public int countPrintArgs(){
	   return 1;
	 }
}
