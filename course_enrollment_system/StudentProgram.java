package database;

import java.sql.*;

public class StudentProgram extends Program{

	private TimeTable timetable;
	
	public StudentProgram(Connection db, int id) {
		super(db, id);
		timetable= new TimeTable(db, id);
	}


	public void help() {
		System.out.println("Student logined. Your ID number is "+id
				+ "\nType your command. These are command list.\n"
				+ "*********************************************************\n"
				+ "help : show types of commands again\n"
				+ "modify [new password] : modify your password\n\n"
				+ "all : show all classes information\n"
				+ "check : show all classes you registered\n"
				+ "tt : show your current time table\n\n"
				+ "class register [classID] : register new class with a class no\n"
				+ "class drop [classID] : drop the class you registered\n\n"
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
			else if(this.order[0].equals("modify")) {
				this.modify(this.order[1]);
			}
			else if(this.order[0].equals("all")) {
				this.searchClass.manipulate("", "");
				this.searchClass.print();
			}
			else if(this.order[0].equals("check")) {
				this.check();
			}
			
			else if(this.order[0].equals("tt")) {
				this.timetable.printTT();
			}
			
			else if(this.order[0].equals("class")) {
				this.classRD(order[1], order[2]);
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


	private void modify(String password) {
		
		this.SQL="UPDATE student SET password='"+password+"' WHERE studentID="+this.id;
		try {
			this.st= this.con.createStatement();
			this.st.executeUpdate(this.SQL);
			System.out.println("password changed.\n");
			this.save();
			
		}catch(SQLException e) {
			e.printStackTrace();
		}	
	}
	
	private void check() {
		
		System.out.println("[registered class lists]");
		
		this.SQL="SELECT class.﻿classID, class.classNO, class.course_id, class.name, major.name, class.year, class.credit, lecturer.name, class.person_max, class.opened, building.name " + 
				"FROM class, major, lecturer, building, room, register " + 
				"WHERE register.classID=class.﻿classID and register.studentID="+this.id
				+ " and class.major_id=major.﻿major_id and class.lecturer_id=lecturer.﻿lecturer_id and class.room_id=room.﻿room_id and room.building_id=building.﻿building_id ";
				
		try {
			this.st= this.con.createStatement();
			this.rs=this.st.executeQuery(this.SQL);
			
			System.out.println("=======================================================\n"
					+ "class ID\tclass no\tcourse id\tclass name\tmajor name\tyear\tcredit\tlecturer\tperson max\topened\tbuilding\t\n"
					+ "=======================================================\n");
			while(rs.next()) {
				int classID=rs.getInt(1);
				int classNO= rs.getInt(2);
				String course_id= rs.getString(3);
				String class_name= rs.getString(4);
				String major_name= rs.getString(5);
				int year= rs.getInt(6);
				int credit= rs.getInt(7);
				String lecturer_name= rs.getString(8);
				int person_max= rs.getInt(9);
				int opened=rs.getInt(10);
				String building_name= rs.getString(11);
				
				
				System.out.println(classID+"\t"+classNO+"\t\t"+course_id+"\t\t"+class_name+"\t\t\t"+major_name+"\t"+
				year+"\t"+credit+"\t"+lecturer_name+"\t"+person_max+"\t"+opened+"\t"+building_name);
			}
			System.out.println("=======================================================\n");
			rs.close();
			
			
		}catch(SQLException e) {
			e.printStackTrace();
		}
	}
	
	private void classRD(String option, String classID) {
		
		if(option.equals("register")) {
			
			this.SQL="INSERT INTO register VALUES (NULL, "+this.id+", "+classID+")";
			try {
				this.st= this.con.createStatement();
				this.st.executeUpdate(this.SQL);
				System.out.println("classID: "+classID+" is registered.\n");
				this.save();
				
			}catch(SQLException e) {
				e.printStackTrace();
			}
		}
		else if(option.equals("drop")) {
		
			this.SQL="DELETE FROM register WHERE register.studentID="+this.id+" and register.classID="+classID; 
			try {
				this.st= this.con.createStatement();
				this.st.executeUpdate(this.SQL);
				System.out.println("classID: "+classID+" is dropped.\n");
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
