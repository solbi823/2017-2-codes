package database;

import java.sql.*;


public class DBConnection {

	private Connection con= null;		//connection 객체.
	private Statement st= null;
	private ResultSet rs;
	
	public DBConnection() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			con =DriverManager.getConnection("jdbc:mysql://localhost:3306/university?useUnicode=yes&characterEncoding=UTF-8&useSSL=false", "root", "root");  //주소 , 계정, 비밀번호
			con.setAutoCommit(false); 		//자동으로 커밋이 안되도록 설정.
		}
		catch(Exception e) {
			
			System.out.println("데이터베이스 연결 오류: "+e.getMessage());
		}
	}
	
	public Connection getConnection() {
		return this.con;
	}
	
	


	public boolean isAdmin(int adminID, String adminPassword) {
		try {
			String SQL = "SELECT * FROM ADMIN WHERE adminID="+adminID+" and adminPassword ='"+adminPassword+"'";
			this.st= this.con.createStatement();
			this.rs=st.executeQuery(SQL);

			if(rs.next()) {
				return true;
			}

		}catch(Exception e){
			System.out.println("데이터베이스 검색 오류1: "+e.getMessage());

		}

		return false;
	}

	public boolean isStudent(int studentID, String password) {
		try {
			String SQL = "SELECT * FROM student WHERE studentID="+studentID+" and password='"+password+"'";
			
			this.st= this.con.createStatement();
			this.rs=st.executeQuery(SQL);

			if(rs.next()) {
				return true;
			}
		}catch(SQLException e) {
			System.out.println("데이터베이스 검색 오류2: "+e.getMessage());
		}

		try {
		rs.close();
		st.close();
		}catch(Exception e) {}
		
		return false;
	}
	
}
