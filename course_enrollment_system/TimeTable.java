package database;

import java.sql.*;

public class TimeTable {

	private Connection con;
	private Statement st;
	private ResultSet rs;
	private String SQL;
	
	private int studentID;
	
	public TimeTable(Connection con, int studentID) {
		this.con =con;
		this.studentID=studentID;

		this.SQL="SELECT class.classNO, class.name, class.credit, time.begin, time.end "
				+ "FROM register, class, time "
				+ "WHERE register.classID=class.﻿classID and register.classID=time.classID "
				+ "and class.room_id IS NOT NULL "
				+ "and register.studentID="+this.studentID;
	}
	
	public void update() {
		try{
			this.st=this.con.createStatement();
			this.rs=this.st.executeQuery(this.SQL);
		}catch(SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void printTT() {
		
		String time1, time2, beginH, beginM, endH, endM;
		int day;
		int credit=0;
		
		this.update();
		
		System.out.println("====================TIME TABLE====================\n"
				+ "classNO  Name\t\tcredit\tDAY\tTIME\n"
				+ "==================================================\n");

		try {
			
			while(rs.next()) {
				
				credit+=rs.getInt(3);
				
				time1= rs.getString(4);
				day= Integer.parseInt(time1.substring(9, 10));
				beginH=time1.substring(11, 13);
				beginM=time1.substring(14, 16);

				time2= rs.getString(5);
				endH=time2.substring(11, 13);
				endM=time2.substring(14, 16);

				if(day==6 || (day==5 && Integer.parseInt(beginH)>=6) ) {
					continue;
				}

				System.out.println(rs.getInt(1)+"\t"+rs.getString(2)+"\t"+rs.getInt(3)+"\t"
						+this.numToDay(day)+"\t"+beginH+" : "+beginM+" ~ "+endH+" : "+endM);

			}

			System.out.println("==================================================\n");
			

			rs.close();
			st.close();

		}catch(SQLException e) {
			e.printStackTrace();
		}
	}
	
	
	public String numToDay(int day) {
		
		if(day==1) {
			return "MON";
		}
		else if(day==2) {
			return "TUE";
		}
		else if(day==3) {
			return "WED";
		}
		else if(day==4) {
			return "THU";
		}
		else if(day==5) {
			return "FRI";
		}
		else {
			return "day error.";
		}
	}
	
}
