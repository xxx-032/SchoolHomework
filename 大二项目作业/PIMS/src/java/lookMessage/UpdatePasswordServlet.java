/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package lookMessage;

import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.swing.JOptionPane;
import loginRegister.LoginBean;
import loginRegister.connectToSQL;

/**
 *
 * @author Administrator
 */
public class UpdatePasswordServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        String password1=request.getParameter("password");
        String password2=request.getParameter("confirm_pasdsword");
        if(password1.length()==0||password2.length()==0){
            response.sendRedirect("http://localhost:8080/PIMS/desktop/lookmessage/updatePassword.jsp");
        }else if(!(password1.equals(password2))){
            response.sendRedirect("http://localhost:8080/PIMS/desktop/lookmessage/updatePassword.jsp");
        }else{
            try{
                Connection con=null;
                Statement stmt=null;
                ResultSet rs=null;
                con = connectToSQL.conectToSql();
                stmt=con.createStatement();
                String userName="";
                HttpSession session=request.getSession();
                ArrayList login=(ArrayList)session.getAttribute("login");
               if(login==null||login.size()==0){
                    response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
               }else{
                    for(int i=login.size()-1;i>=0;i--){
                         LoginBean nn=(LoginBean)login.get(i);
                         userName=nn.getUserName();
                    }
                }
                String sql1="Update user set password='"+password1+"' where userName='"+userName+"'";
                stmt.executeUpdate(sql1);
                String sql2="select * from user where userName='"+userName+"'";
                rs=stmt.executeQuery(sql2);
                LoginBean nn=new LoginBean();
                nn.setPassword(password1);
                ArrayList wordlist=null;
                wordlist=new ArrayList();
                wordlist.add(nn);
                session.setAttribute("login", login);
                rs.close();
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/desktop/lookmessage/LookMessage.jsp");
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
