public class Table{
  public String id;
	public int value;
	public Table tail;

	Table(String i, int v, Table t){
	  id = i;
		value = v;
		tail = t;
	}

	public int lookup(String key){
	  if(key == null){
		  System.err.println("lookup error.");
			System.exit(1);
		}

		if(key.equals(id)){
		  return value;
		}else{
		  if(tail == null){
			  System.err.println("lookup error.");
				System.exit(1);
			}
		  return tail.lookup(key);
		}
	}
}


class IntAndTable{
  public int i;
	public Table t;

	public IntAndTable(int ii, Table tt){
	  i = ii;
		t = tt;
	}
}
