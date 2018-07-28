/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package loginRegister;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author xxx_032
 */
public class connectToSQL {
    public static Connection conectToSql() throws ClassNotFoundException, SQLException{
        Class.forName("com.mysql.jdbc.Driver");
        String url="jdbc:mysql://localhost:3306/person?useUnicode=true";
        return DriverManager.getConnection(url,"root","root");
    }
}
