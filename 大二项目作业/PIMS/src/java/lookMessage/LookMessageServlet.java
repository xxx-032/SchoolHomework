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
import loginRegister.connectToSQL;

/**
 *
 * @author Administrator
 */
public class LookMessageServlet extends HttpServlet {
        protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        HttpSession session=request.getSession();
        ArrayList login=(ArrayList)session.getAttribute("login");
        if(login==null||login.size()==0){
            response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
        }       
        String userName=request.getParameter("userName");
        try{
            Connection con=null;
            Statement stmt=null;
            ResultSet rs=null;
            con = connectToSQL.conectToSql();
            stmt=con.createStatement();
            String sql="select * from user where userName='"+userName+"'";
            rs=stmt.executeQuery(sql);
            LookMessageBean mm=new LookMessageBean();
            while(rs.next()){
                mm.setName(rs.getString("name"));
                mm.setSex(rs.getString("sex"));
                mm.setBirth(rs.getString("birth"));
                mm.setNation(rs.getString("nation"));
                mm.setEdu(rs.getString("edu"));
                mm.setWork(rs.getString("work"));
                mm.setPhone(rs.getString("phone"));
                mm.setPlace(rs.getString("place"));
                mm.setEmail(rs.getString("email"));
            }
            ArrayList wordlist=wordlist=new ArrayList();
            wordlist.add(mm);
            session.setAttribute("wordlist", wordlist);
            rs.close();
            stmt.close();
            con.close();
            response.sendRedirect("http://localhost:8080/PIMS/desktop/AboutYouselves.jsp");
        }catch(Exception e){
            e.printStackTrace();
        }
        
    } 

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        doGet(request, response);
    }

}
