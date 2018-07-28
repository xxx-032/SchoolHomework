/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package loginRegister;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.swing.JOptionPane;

/**
 *
 * @author Administrator
 */
public class LoginServlet extends HttpServlet {
    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        String userName=request.getParameter("userName");
        String password=request.getParameter("password");
        if(userName.equals("")){
            response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
        }else if(password.equals("")){
            response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
        }else{
            try{
                Connection con=null;
                Statement stmt=null;
                ResultSet rs=null;
                con = connectToSQL.conectToSql();
                stmt=con.createStatement();
                String sql="select * from user where userName='"+userName+"'";
                rs=stmt.executeQuery(sql);
                int N=0;
                int P=0;
                while(rs.next()){
                    if(userName.equals(rs.getString("userName"))){
                        N=111111;
                        if(password.equals(rs.getString("password"))){
                            P=111111;
                            LoginBean nn=new LoginBean();//实例化保存个人信息的JavaBean
                            nn.setUserName(userName);//保存用户名
                            nn.setPassword(password);//保存密码
                            HttpSession session=request.getSession();//获取session对象
                            ArrayList login=new ArrayList();//实例化列表对象
                            login.add(nn);//把个人信息保存到列表中
                            session.setAttribute("login", login);//把列表保存到session对象中，以便在别的页面中获取个人信息
                            localUser.username = userName;
                            response.sendRedirect("http://localhost:8080/PIMS/desktop/main.jsp");
                        }
                    }
                }
                if(N<111111){
                    response.sendRedirect("http://localhost:8080/PIMS/login/dealLogin.jsp?error=3");
                }else if(P<111111){
                    response.sendRedirect("http://localhost:8080/PIMS/login/dealLogin.jsp?error=4");
                }
            }catch(Exception e){
                e.printStackTrace();
            }
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        doGet(request, response);
    }     
}
