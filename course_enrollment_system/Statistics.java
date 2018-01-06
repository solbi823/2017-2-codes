package database;

import java.sql.*;

public class Statistics {
	
	private Connection con;
	private Statement st;
	private ResultSet rs;
	private String SQL;
	
	private String major_name;
	private String[] classes;
	private int opened;
	
	public Statistics(Connection db, String major_name){
		this.con=db;
		this.major_name=major_name;
	}
	
	public void manipulate() {

		int sum;
		String className;
		this.opened=2014;

		try {
			this.SQL="SELECT class.name, SUM(class.person_max) FROM class, major "
					+ "WHERE class.major_id=major.﻿major_id and major.name='"+this.major_name+"' and class.opened="+this.opened+
					" GROUP BY class.name";
			
			this.st=this.con.createStatement();
			this.rs=this.st.executeQuery(this.SQL);
			
			rs.last();
			int num=rs.getRow();
			this.classes=new String[num];
			rs.beforeFirst();

			int index=0;
			while(rs.next()) {
				this.classes[index]=rs.getString(1);
				index++;
			}
			
		}catch(SQLException e1) {
			e1.printStackTrace();
		}

		System.out.print("MAJOR:  "+this.major_name
				+ "\n==================================================================================\nyear\t\t");
		
		for (int i=0; i<this.classes.length; i++) {
			System.out.print(this.classes[i]+"\t");
		}
		
		System.out.println("\n==================================================================================");

		
		while(this.opened>2010) {
			
			System.out.print(this.opened+"\t\t");
			
			this.SQL="SELECT class.name, SUM(class.person_max) FROM class, major "
					+ "WHERE class.major_id=major.﻿major_id and major.name='"+this.major_name+"' and class.opened="+this.opened+
					" GROUP BY class.name";

			try{
				this.st=this.con.createStatement();
				this.rs=this.st.executeQuery(this.SQL);

				int index2=0;
				while(rs.next()) {

					className=rs.getString(1);
					sum=rs.getInt(2);

					if(!className.equals(this.classes[index2])) {
						index2++;
						continue;
					}
					else {
						index2++;
						System.out.print(sum+"\t\t");
					}
				}

			}catch(SQLException e2) {
				e2.printStackTrace();
			}
			
			System.out.print("\n");
			this.opened--;

		}
		System.out.print("\n");
	}

}
