abstract class Stm {
	abstract public int maxargs();
	abstract public Table interpStm(Table t);
}

class CompoundStm extends Stm {
   Stm stm1, stm2;
   CompoundStm(Stm s1, Stm s2) {stm1=s1; stm2=s2;}
	 public int maxargs(){
	   return Math.max(stm1.maxargs(), stm2.maxargs());
	 }

	 public Table interpStm(Table t){
	   Table ttemp = stm1.interpStm(t);
		 return stm2.interpStm(ttemp);
	 }
}

class AssignStm extends Stm {
   String id; Exp exp;
   AssignStm(String i, Exp e) {id=i; exp=e;}
	 public int maxargs(){
	   return exp.maxargs();
	 }

	 public Table interpStm(Table t){
	   IntAndTable ttemp = exp.interpExp(t);
	   return new Table(id, ttemp.i, t);
	 }
}

class PrintStm extends Stm {
   ExpList exps;
   PrintStm(ExpList e) {exps=e;}
	 public int maxargs(){
		 return Math.max(exps.countPrintArgs(), exps.maxargs());
	 }

	 public Table interpStm(Table t){
		 return exps.interpPrint(t);
	 }
}

abstract class Exp {
	abstract public int maxargs();
	abstract public IntAndTable interpExp(Table t);
}

class IdExp extends Exp {
   String id;
   IdExp(String i) {id=i;}
	 public int maxargs(){
	   return 0;
	 }

	 public IntAndTable interpExp(Table t){
	   return new IntAndTable(t.lookup(id), t);
	 }
}

class NumExp extends Exp {
   int num;
   NumExp(int n) {num=n;}
	 public int maxargs(){
	   return 0;
	 }

	 public IntAndTable interpExp(Table t){
	   return new IntAndTable(num, t);
	 }
}

class OpExp extends Exp {
   Exp left, right; int oper;
   final static int Plus=1,Minus=2,Times=3,Div=4;
   OpExp(Exp l, int o, Exp r) {left=l; oper=o; right=r;}
	 public int maxargs(){
	   return Math.max(left.maxargs(), right.maxargs());
	 }

	 public IntAndTable interpExp(Table t){
	   IntAndTable t1 = left.interpExp(t);
		 IntAndTable t2 = right.interpExp(t1.t);
		 int temp = 0;
		 switch(oper){
		   case Plus: temp = t1.i + t2.i;
			   break;
		   case Minus: temp = t1.i - t2.i;
			   break;
			 case Times: temp = t1.i * t2.i;
			   break;
			 case Div: temp = t1.i / t2.i;
			   break;
		 }
		 return new IntAndTable(temp, t2.t);
	 }
}

class EseqExp extends Exp {
   Stm stm; Exp exp;
   EseqExp(Stm s, Exp e) {stm=s; exp=e;}
	 public int maxargs(){
	   return Math.max(stm.maxargs(), exp.maxargs());
	 }

	 public IntAndTable interpExp(Table t){
	   Table temp = stm.interpStm(t);
		 return exp.interpExp(temp);
	 }
}

abstract class ExpList {
	abstract public int maxargs();
	abstract public int countPrintArgs();
	abstract public IntAndTable interpExp(Table t);
	abstract public Table interpPrint(Table t);
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

	 public IntAndTable interpExp(Table t){
	   IntAndTable temp = head.interpExp(t);
		 return tail.interpExp(temp.t);
	 }

	 public Table interpPrint(Table t){
	   IntAndTable temp = head.interpExp(t);
		 System.out.print(temp.i);
		 System.out.print(" ");
		 return tail.interpPrint(temp.t);
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

	 public IntAndTable interpExp(Table t){
	   return head.interpExp(t);
	 }

	 public Table interpPrint(Table t){
	   IntAndTable temp = head.interpExp(t);
		 System.out.println(temp.i);
		 return temp.t;
	 }
}
