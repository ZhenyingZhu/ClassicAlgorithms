
# add two lists that represent integers.
/*
 * [Source]: CTCI chapter 2 question 5
 */

// [Solution]: First reverse two lists, then add them and reverse back.

// [Solution]: Add zeros to the shorter one, then sum them together
/* Java solution
import lib.LinkedNode;

class AddHelper{
	public int cum;
	public LinkedNode node;
	public AddHelper(LinkedNode node, int cum){
		this.node = node;
		this.cum=cum;
	}
}

class Question{ // Forward order. 
	public LinkedNode addList(LinkedNode a, LinkedNode b){
		int lena=listLength(a);
		int lenb=listLength(b);
		int diff=lena-lenb;
		LinkedNode first=null;
		LinkedNode second=null;
		if(diff>0){
			first=a;
			second=addZero(b, diff);
		} else {
			first=b;
			second=addZero(a, -diff);
		}
		AddHelper help=addNode(first, second);
		LinkedNode result;
		if(help.cum==0){
			result=help.node;
		}else{
			result=new LinkedNode(help.cum);
			result.next=help.node;
		}
		return result;
	}
	
	public AddHelper addNode(LinkedNode x, LinkedNode y){
		if(x.next==null && y.next==null){
			int sum=x.data+y.data;
			if(sum>=10){
				int cum=sum/10;
				sum=sum%10;
				return new AddHelper(new LinkedNode(sum), cum);
			}else{
				return new AddHelper(new LinkedNode(sum), 0);
			}
		}
		AddHelper descend=addNode(x.next, y.next); 
		int sum=x.data+y.data+descend.cum;
		int cum=0;
		if(sum>=10){
			cum=sum/10;
			sum=sum%10;
		}
		LinkedNode current=new LinkedNode(sum);
		current.next=descend.node;
		return new AddHelper(current, cum);
	}
	public int listLength(LinkedNode head){
		int cnt=0;
		LinkedNode run=head;
		while(run!=null){
			cnt++;
			run=run.next;
		}
		return cnt;
	}
	public LinkedNode addZero(LinkedNode head, int mount){
		while(mount>0){
			LinkedNode zero=new LinkedNode(0);
			zero.next=head;
			head=zero;
		}
		return head;
	}
	public static void main(String[] args){
		LinkedNode a0=new LinkedNode(6);
		LinkedNode a1=new LinkedNode(1);
		LinkedNode a2=new LinkedNode(7);
		a0.next=a1;
		a1.next=a2;
		LinkedNode b0=new LinkedNode(2);
		LinkedNode b1=new LinkedNode(9);
		LinkedNode b2=new LinkedNode(5);
		b0.next=b1;
		b1.next=b2;
		LinkedNode result=new Question().addList(a0, b0);
		result.printList();
	}
}
 */

# timestamp
Oct 20 
Oct 20 
