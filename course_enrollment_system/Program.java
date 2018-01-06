package database;

import java.sql.*;
import java.util.*;

public abstract class Program {
	
	protected int id;
	
	protected Connection con;
	protected Statement st;
	protected ResultSet rs;
	protected String SQL;
	
	protected Scanner stdin;
	protected String[] order;		//매번 명령어를 파싱하여 저장하는 임시객체 
	
	protected String[] commands;		//모든  명령어를 저장하는 객체 
	protected int maxCommand;
	protected int commandIndex;		//저장되어 있는 명령어의 개수.
	
	protected Savepoint[] savepoint;		//savepoint 저장하는 배열.
	protected int saveIndex;				//저장되어있는 savepoint 개수. 
	
	protected SearchClass searchClass;
	
	
	public Program(Connection db, int id) {
		
		this.con= db;
		try {
			this.con.setAutoCommit(false);		//저장하기 위해서 autocommit 해제. 
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		this.id= id;
		this.stdin = new Scanner(System.in);
		this.order = new String[3];
		
		this.maxCommand= 100;
		this.commands= new String[maxCommand];
		this.commandIndex=0;
		
		this.savepoint= new Savepoint[maxCommand];
		this.saveIndex=0;
		
		this.searchClass = new SearchClass(db);
	}
	
	
	public void input() {
		
		
		System.out.print("Input command >> ");
		String tmp=stdin.nextLine();
		
		this.commands[commandIndex]=tmp;
		this.commandIndex++;
		this.order= tmp.split(" ");
	}
	
	public void save() {
		
		try {
		this.savepoint[this.saveIndex]=con.setSavepoint();
		System.out.println("save success. save point index: "+this.saveIndex);
		this.saveIndex++;
		
		}catch(SQLException ex) {
			ex.printStackTrace();
				try {
					con.rollback();
					System.out.println("트렌젝션 실패 \n");
				} catch (SQLException e) {
					e.printStackTrace();
				}
		}
	}
	
	public void rollBack() {	
		
		try {
			this.saveIndex-=2;
			con.rollback(this.savepoint[this.saveIndex]);
			System.out.println("rollback sucess. index decreased: "+ this.saveIndex);
			this.saveIndex++;
		}catch(SQLException ex) {
			ex.printStackTrace();
		}
	}
	
	
	public abstract void help();
	public abstract void process();
	
}
