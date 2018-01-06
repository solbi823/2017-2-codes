package database;

import java.sql.*;

public class ManagerProgram extends Program{
	
	private Statistics stats;

	public ManagerProgram(Connection db, int id) {
		super(db, id);
	}

	public void help() {
		System.out.println("Manager logined. Your ID number is "+id
				+ "\nType your command. These are command list.\n"
				+ "*********************************************************\n"
				+ "help : show types of commands again\n"
				+ "init : (*important*) start class registration , make register table (may go first.)\n"
				+ "modify student [student id]: modify student's password\n"
				+ "modify manager [manager id]: modify manager's password\n\n"
				+ "all : show all classes information\n"
				+ "stats [major_name]: show statistics of the major enrollment\n"
				+ "class open [classID] : open class with a class ID\n"
				+ "class close [classID] : close class\n\n"
				+ "search class [classNO] : search class with class no\n"
				+ "search course [course_id] : search classes with course id\n"
				+ "search name [class name] : search classes with class name (keyword search)\n"
				+ "search lec [lecturer name] : search classes with lecturer name (right truncation)\n\n"
				+ "cancel : cancel your last query\n"
				+ "quit : quit the program\n"
				+ "*********************************************************\n");
	}


	public void process() {
		
		this.save();
		this.help();
		this.input();
		
		while(true) {
		
			if(this.order[0].equals("help")) {
				this.help();
			}
			else if(this.order[0].equals("init")) {
				if(this.init()) {
					System.out.println("Successfully System opened.\n");
				}
				else {
					System.out.println("Making table failed.\n");
				}
			}
			
			else if(this.order[0].equals("modify")) {
				this.modify(this.order[1], this.order[2]);
			}
			
			else if(this.order[0].equals("all")) {
				this.searchClass.manipulate("", "");
				this.searchClass.print();
			}
			
			else if(this.order[0].equals("stats")) {
				if(order.length!=2) {
					System.out.println("incorrect arguments number.\n");
				}
				else {
					this.stats= new Statistics(this.con, this.order[1]);
					stats.manipulate();
				}
			}
			
			else if(this.order[0].equals("class")) {
				if(order.length!=3) {
					System.out.println("incorrect arguments number.\n");
				}
				else {
					this.classControl(this.order[1], this.order[2]);
				}
			}
			
			else if(this.order[0].equals("search")) {
				if(order.length!=3) {
					System.out.println("incorrect arguments number.\n");
				}
				else {
					this.searchClass.manipulate(order[1], order[2]);
					this.searchClass.print();
				}
			}
			
			else if(this.order[0].equals("cancel")) {
				this.rollBack();
			}			
			
			else if(this.order[0].equals("quit")) {
				try {
					this.con.commit();
				} catch (SQLException e) {
					e.printStackTrace();
				}
				System.out.println("Program terminates.\n");
				break;
			}
			else {
				System.out.println("Please input correct command.\n");
			}
			
			this.input();
		}
	}
	
	
	private boolean init() {
		
		this.SQL="DROP TABLE IF EXISTS register ";
		try {
			this.st= this.con.createStatement();
			this.st.executeUpdate(this.SQL);
			
		}catch(SQLException e) {
			return false;
		}
		
		
		this.SQL=" CREATE TABLE register " + 
				" (registerID INT NOT NULL AUTO_INCREMENT, " + 
				" studentID INT NOT NULL, " + 
				" classID INT NOT NULL, " + 
				" PRIMARY KEY (registerID))";
		try {
			this.st= this.con.createStatement();
			this.st.executeUpdate(this.SQL);
			this.save();
			return true;
			
		}catch(SQLException e) {
			return false;
		}
	}
	

	private void modify(String option, String id) {		//update가 안되고 있음...
		
		String password;
		
		if(option.equals("student")) {
			
			System.out.print("Input password you want to change to>> ");
			password= stdin.nextLine();
			this.SQL="UPDATE student SET password='"+password+ "' WHERE studentID="+id;
			try {
				this.st= this.con.createStatement();
				this.st.executeUpdate(this.SQL);
				System.out.println("password changed.\n");
				this.save();
				
			}catch(SQLException e) {
				e.printStackTrace();
			}			
		}

		else if(option.equals("manager")) {
			
			//확인차원에서 그냥
			this.SQL="SELECT * FROM admin";
			try {
				this.st= this.con.createStatement();
				this.rs=this.st.executeQuery(this.SQL);
				
				while(this.rs.next()) {
					System.out.println("id= "+rs.getInt(1)+"  password= "+rs.getString(2));
				}
			}catch(SQLException e) {
				e.printStackTrace();
			}
			
			
			
			System.out.print("Input password you want to change to>> ");
			password= stdin.nextLine();
			this.SQL="UPDATE admin SET adminPassword='"+password+ "' WHERE adminID="+id;
			try {
				this.st= this.con.createStatement();
				this.st.executeUpdate(this.SQL);
				System.out.println("password changed.\n");
				this.save();
				
			}catch(SQLException e) {
				e.printStackTrace();
			}
			
			
			
			
			//확인차원에서 그냥
			this.SQL="SELECT * FROM admin";
			try {
				this.st= this.con.createStatement();
				this.rs=this.st.executeQuery(this.SQL);
				
				while(this.rs.next()) {
					System.out.println("id= "+rs.getInt(1)+"  password= "+rs.getString(2));
				}
			}catch(SQLException e) {
				e.printStackTrace();
			}
			
		}

		else {
			System.out.println("option is incorrect.\n");
		}
	}
	
	
	private void classControl(String option, String classID) {

		if(option.equals("open")) {
			
			this.SQL="UPDATE class SET opened=2014 WHERE class.﻿classID="+ classID;
			try {
				this.st= this.con.createStatement();
				this.st.executeUpdate(this.SQL);
				System.out.println("class opened.\n");
				this.save();
				
			}catch(SQLException e) {
				e.printStackTrace();
			}
		}
		
		else if(option.equals("close")) {
			
			this.SQL="UPDATE class SET opened=-1 WHERE class.﻿classID="+ classID;
			try {
				this.st= this.con.createStatement();
				this.st.executeUpdate(this.SQL);
				System.out.println("class closed.\n");
				this.save();
				
			}catch(SQLException e) {
				e.printStackTrace();
			}
		}
		
		else {
			System.out.println("option is incorrect.\n");
		}	
	}
	
}
