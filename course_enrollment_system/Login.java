package database;

public class Login{
	
	private static StudentProgram student;
	private static ManagerProgram manager;
	private static DBConnection connection;

	public static void main(String[] args) {
		
		connection = new DBConnection();
		
		try {
			if(args.length == 2) {
				
				int ID= Integer.parseInt(args[0]);
				String password= args[1];

				
				if(connection.isAdmin(ID, password)) {
					manager= new ManagerProgram(connection.getConnection(), ID);
					manager.process();
	
				}
				else if(connection.isStudent(ID, password)){
					student= new StudentProgram(connection.getConnection(), ID);
					student.process();
					
				}
				
				
				else {
					System.out.println("존재하지 않는 id나 비밀번호 입니다. \n");
					return;
				}
			}
			
			else {
				System.out.println("학번 비밀번호\n순서대로 입력 \n");
				return;
			}
			
			
		}catch(Exception e) {
			System.out.println(e.getMessage());
			return;
		}
		
	}

}
