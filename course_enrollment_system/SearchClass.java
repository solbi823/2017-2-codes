package database;

import java.sql.*;

public class SearchClass {
	
	private Connection con;
	private Statement st;
	private ResultSet rs;
	private String SQL;
	
	public SearchClass(Connection db){
		this.con=db;
		try {
			this.con.setAutoCommit(false);		//저장하기 위해서 autocommit 해제. 
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void manipulate(String option , String keyWord) {
		this.SQL="SELECT class.﻿classID, class.classNO, class.course_id, class.name, major.name, class.year, class.credit, lecturer.name, class.person_max, class.opened, building.name " + 
				"FROM class, major, lecturer, building, room " + 
				"WHERE class.major_id=major.﻿major_id and class.lecturer_id=lecturer.﻿lecturer_id and "
				+ "class.room_id=room.﻿room_id and room.building_id=building.﻿building_id "
				+ "and class.room_id IS NOT NULL ";
		
		if(option.equals("")) {		//show all
			return;
		}
		else if(option.equals("class")) {
			this.SQL+="and class.classNO="+keyWord;
		}
		else if(option.equals("course")) {
			this.SQL+="and class.course_id=\""+keyWord+"\"";
		}
		else if(option.equals("name")) {
			this.SQL+="and class.name like \"%" +keyWord + "%\"";
		}
		else if(option.equals("lec")) {
			this.SQL+="and lecturer.name like \'" + keyWord + "%\'";
		}
		else {
			System.out.println("unvalid option.\n");
			return;
		}
	}
	
	public void print() {
		
		try {
			this.st= this.con.createStatement();
			this.rs= st.executeQuery(this.SQL);
			
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
			
		}catch(SQLException se) {
			System.out.println("error: "+se.getMessage());
		}
	}

}
