/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package loginRegister;

import java.io.IOException;
import java.sql.*;
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
public class RegisterServlet extends HttpServlet {


    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8"); 
        
        String userName=request.getParameter("userName");
        String email=request.getParameter("email");
        String password1=request.getParameter("password");
        String password2=request.getParameter("confirm_pasdsword");
        String name=request.getParameter("name");
        String sex=request.getParameter("sex");
        String birth=request.getParameter("year")+"-"+request.getParameter("month")+"-"+request.getParameter("day");
        String nation=request.getParameter("nation");
        String edu=request.getParameter("edu");
        String work=request.getParameter("work");
        String phone=request.getParameter("phone");
        String place=request.getParameter("place");
        if(userName.length()==0||password1.length()==0||password2.length()==0||name.length()==0||phone.length()==0||email.length()==0){
            response.sendRedirect("http://localhost:8080/PIMS/register/register.jsp");
        }else if(!(password1.equals(password2))){
            response.sendRedirect("http://localhost:8080/PIMS/register/dealRegister.jsp?error=6");
        }else{
            try{
                Connection con=null;
                Statement stmt=null;
                ResultSet rs=null;
                con = connectToSQL.conectToSql();
                stmt=con.createStatement();
                String sql1="select * from user where userName='"+userName+"'";
                rs=stmt.executeQuery(sql1);
                rs.last();
                int k;
                k=rs.getRow();
                if(k>0){
                    response.sendRedirect("http://localhost:8080/PIMS/register/dealRegister.jsp?error=5");
                }else{
                    String sql2="insert into user"+"(userName,password,name,sex,birth,nation,edu,work,phone,place,email)"+"values("+"'"+userName+"'"+","+"'"+password1+"'"+","+"'"+name+"'"+","+"'"+sex+"'"+","+"'"+birth+"'"+","+"'"+nation+"'"+","+"'"+edu+"'"+","+"'"+work+"'"+","+"'"+phone+"'"+","+"'"+place+"'"+","+"'"+email+"'"+")";
                    stmt.executeUpdate(sql2);
                }
                rs.close();
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
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
